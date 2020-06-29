#ifndef CAPRESOURCEOBJECT_CPP
#define CAPRESOURCEOBJECT_CPP

#include <CAPLibpp/CAPResourceObject.h>

namespace CAPLib
{

// ************************************************************************************************
CAPResourceObject::CAPResourceObject() : mSize{-1}
{
}

void CAPResourceObject::SetResourceDesc(const std::string &inResourceDesc)
{
  mResourceDesc = inResourceDesc;
} // void CAPResourceObject::SetResourceDesc(const std::string &inResourceDesc)

// ************************************************************************************************
std::string CAPResourceObject::ResourceDesc() const
{
  return mResourceDesc;
}  // std::string CAPResourceObject::ResourceDesc() const

// ************************************************************************************************
void CAPResourceObject::SetMimeType(const std::string &inMIMEType)
{
  mMIMEType = inMIMEType;
} // void CAPResourceObject::SetMimeType(const std::string &inMIMEType)

// ************************************************************************************************
std::string CAPResourceObject::MimeType() const
{
  return mMIMEType;
} // std::string CAPResourceObject::MimeType() const

// ************************************************************************************************
void CAPResourceObject::SetSize(int inSize)
{
  mSize = inSize;
} // void CAPResourceObject::SetSize(int inSize)

// ************************************************************************************************
int CAPResourceObject::Size() const
{
  return mSize;
} // int CAPResourceObject::Size() const

// ************************************************************************************************
void CAPResourceObject::SetURI(const std::string &inURI)
{
  mURI = inURI;
} // void CAPResourceObject::SetURI(const QUrl &inURI)

// ************************************************************************************************
std::string CAPResourceObject::URI() const
{
  return mURI;
} // QUrl CAPResourceObject::URI() const

// ************************************************************************************************
void CAPResourceObject::SetDerefURI(const std::string &inDerefURI)
{
  mDerefURI = inDerefURI;
} // void CAPResourceObject::SetDerefURI(const std::string &inDerefURI)

// ************************************************************************************************
std::string CAPResourceObject::DerefURI() const
{
  return mDerefURI;
} // std::string CAPResourceObject::DerefURI() const

// ************************************************************************************************
void CAPResourceObject::SetDigest(const std::string &inDigest)
{
  mDigest = inDigest;
} // void CAPResourceObject::SetDigest(const std::string &inDigest)

// ************************************************************************************************
std::string CAPResourceObject::Digest() const
{
  return mDigest;
}

// ************************************************************************************************
bool CAPResourceObject::ProcessXML(const boost::property_tree::ptree &inXMLReader)
{
  if (inXMLReader.empty())
  {
    return false;
  }

  try
  {
    SetResourceDesc(inXMLReader.get<std::string>("resourceDesc", ""));
    SetMimeType(inXMLReader.get<std::string>("mimeType", ""));
    SetSize(std::stoi(inXMLReader.get<std::string>("size", "")));
    SetURI(inXMLReader.get<std::string>("uri", ""));
    SetDerefURI(inXMLReader.get<std::string>("derefUri", ""));
    SetDigest(inXMLReader.get<std::string>("digest", ""));

    return true;
  }
  catch (...)
  {
    return false;
  }
} // std::string CAPResourceObject::Digest() const

} // namespace CAPLib

#endif // #ifndef CAPRESOURCEOBJECT_CPP
