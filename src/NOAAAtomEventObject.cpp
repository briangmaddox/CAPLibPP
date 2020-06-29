#ifndef NOAAATOMEVENTOBJECT_CPP
#define NOAAATOMEVENTOBJECT_CPP

#include <boost/optional/optional.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <sstream>
#include <CAPLibpp/NOAAAtomEventObject.h>

namespace CAPLib
{

// ************************************************************************************************
std::string NOAAAtomEventObject::Identifier() const
{
  return mIdentifier;
}

// ************************************************************************************************
void NOAAAtomEventObject::SetIdentifier(const std::string &inIdentifier)
{
    mIdentifier = inIdentifier;
}

// ************************************************************************************************
std::string NOAAAtomEventObject::Logo() const
{
    return mLogo;
}

// ************************************************************************************************
void NOAAAtomEventObject::SetLogo(const std::string &inLogo)
{
    mLogo = inLogo;
}

// ************************************************************************************************
std::string NOAAAtomEventObject::Generator() const
{
    return mGenerator;
}

// ************************************************************************************************
void NOAAAtomEventObject::SetGenerator(const std::string &inGenerator)
{
    mGenerator = inGenerator;
}

// ************************************************************************************************
std::string NOAAAtomEventObject::Updated() const
{
  return mUpdated;
}

// ************************************************************************************************
void NOAAAtomEventObject::SetUpdated(const std::string &inUpdated)
{
  mUpdated = inUpdated;
}

// ************************************************************************************************
std::string NOAAAtomEventObject::Published() const
{
  return mPublished;
}

// ************************************************************************************************
void NOAAAtomEventObject::SetPublished(const std::string &inPublished)
{
  mPublished = inPublished;
}

// ************************************************************************************************
std::string NOAAAtomEventObject::Author() const
{
  return mAuthor;
}

// ************************************************************************************************
void NOAAAtomEventObject::SetAuthor(const std::string &inAuthor)
{
  mAuthor = inAuthor;
}

// ************************************************************************************************
std::string NOAAAtomEventObject::Title() const
{
  return mTitle;
}

// ************************************************************************************************
void NOAAAtomEventObject::SetTitle(const std::string &inTitle)
{
  mTitle = inTitle;
}

// ************************************************************************************************
std::string NOAAAtomEventObject::Link() const
{
  return mLink;
}

// ************************************************************************************************
void NOAAAtomEventObject::SetLink(const std::string &inLink)
{
  mLink = inLink;
}

// ************************************************************************************************
std::string NOAAAtomEventObject::Summary() const
{
  return mSummary;
}

// ************************************************************************************************
void NOAAAtomEventObject::SetSummary(const std::string &inSummary)
{
  mSummary = inSummary;
}

// ************************************************************************************************
std::vector<NOAACAPAlertObject> NOAAAtomEventObject::CAPAlertObjects() const
{
  return mCAPObjects;
}

// ************************************************************************************************
void NOAAAtomEventObject::AddCAPAlertObject(const NOAACAPAlertObject &inCAPObject)
{
  mCAPObjects.push_back(inCAPObject);
}

// ************************************************************************************************
bool NOAAAtomEventObject::ProcessXML(const boost::property_tree::ptree &inXML)
{
  if (inXML.empty())
  {
    return false;
  }

  try
  {
    // First set the direct elements
    SetIdentifier(inXML.get<std::string>("feed.id", ""));
    SetLogo(inXML.get<std::string>("feed.logo", ""));
    SetGenerator(inXML.get<std::string>("feed.generator", ""));
    SetUpdated(inXML.get<std::string>("feed.updated", ""));
    SetAuthor(inXML.get<std::string>("feed.author.name", ""));
    SetTitle(inXML.get<std::string>("feed.title", ""));
    SetLink(inXML.get<std::string>("feed.link", ""));

    // Now we go through find all of the <entry> elements and process them
    for (auto &tNode : inXML.get_child("feed"))
    {
      if (tNode.first == "entry")
      {
        // Grab the link text, return "None" if it isn't there
        std::string capURL(tNode.second.get<std::string>("link.<xmlattr>.href", "None"));

        // Only process if we get the actual URL
        if (capURL != "None")
        {
          std::stringstream capXML(GetCAPURL(capURL));

          // Did we get actual CAP Text?
          if (!capXML.str().empty())
          {
            boost::property_tree::ptree tempTree;

            boost::property_tree::read_xml(capXML, tempTree);

            NOAACAPAlertObject tempObject;

            if (tempObject.ProcessXML(tempTree))
            {
              AddCAPAlertObject(tempObject);
            }
          }
        }
      } // if (tNode.first == "entry")
    } // for (auto &tNode : inXML.get_child("feed"))
  } // try
  catch(...)
  {
    return false;
  }

  return true;
}

// ************************************************************************************************
std::stringstream NOAAAtomEventObject::GetCAPURL(const std::string &inURL)
{
  std::stringstream response;

  try
  {
    curlpp::initialize();

    curlpp::Easy curlEasy;

    curlEasy.setOpt(curlpp::options::Url(inURL));
    curlEasy.setOpt(curlpp::options::UserAgent("libcurl-agent/1.0"));
    curlEasy.setOpt(curlpp::options::WriteStream(&response));

    curlEasy.perform();
    curlEasy.reset();
    curlpp::terminate();

    return response;
  }
  catch (...)
  {
    return std::stringstream(); // return an empty stringstream
  }
}

} // namespace

#endif
