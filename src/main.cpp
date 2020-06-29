#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <string>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <sstream>
#include <stdexcept>
#include <CAPLibpp/NOAAAtomEventObject.h>
#include <CAPLibpp/CAPLibEnums.h>

int main()
{
  try
  {
      std::stringstream response;
      CAPLib::NOAAAtomEventObject atomEvent;
      boost::property_tree::ptree testTree;
      //std::string inputFile("/home/bmaddox/test.xml");

      curlpp::initialize();
      curlpp::Easy foo;
      foo.setOpt(curlpp::options::Url("https://alerts.weather.gov/cap/va.php?x=1"));
      foo.setOpt(curlpp::options::UserAgent("libcurl-agent/1.0"));
      foo.setOpt(curlpp::options::WriteStream(&response ) );
      foo.perform();
      foo.reset();
      curlpp::terminate();

      boost::property_tree::read_xml(response, testTree);

      atomEvent.ProcessXML(testTree);

      // Now print out things to test.
      std::cout << "Atom Feed:" << std::endl;
      std::cout << "  Identifier: " << atomEvent.Identifier() << std::endl;
      std::cout << "  Logo URL: " << atomEvent.Logo() << std::endl;
      std::cout << "  Updated: " << atomEvent.Updated() << std::endl;
      std::cout << "  Published: " << atomEvent.Published() << std::endl;
      std::cout << "  Author: " << atomEvent.Author() << std::endl;
      std::cout << "  Title: " << atomEvent.Title() << std::endl;
      std::cout << "  Link URL: " << atomEvent.Link() << std::endl;
      std::cout << "  Summary: " << atomEvent.Summary() << std::endl;
      std::cout << std::endl << std::endl;

      std::cout << "CAP Events:" << std::endl;
      for (auto &it: atomEvent.CAPAlertObjects())
      {
          std::cout << "#####################################################" << std::endl;
          std::cout << "Identifier: " << it.Identifier() << std::endl;
          std::cout << "Sender: " << it.Sender() << std::endl;
          std::cout << "Sent: " << it.Sent() << std::endl;
          std::cout << "Status: " << CAPLib::CAPEnumToString(it.Status()) << std::endl;
          std::cout << "MsgType: " << CAPLib::CAPEnumToString(it.MsgType()) << std::endl;
          std::cout << "Source: " << it.Source() << std::endl;
          std::cout << "Scope: " << CAPLib::CAPEnumToString(it.Scope()) << std::endl;
          std::cout << "Restriction: " << it.Restriction() << std::endl;
          std::cout << "Addresses: " << it.Addresses() << std::endl;
          std::cout << "Codes:" << std::endl;
          for (auto &tCode: it.Codes())
          {
              std::cout << "  " << tCode << std::endl;
          }
          std::cout << "Note: " << it.Note() << std::endl;
          std::cout << "References: " << it.References() << std::endl;
          std::cout << "Incidents: " << it.Incidents() << std::endl;

          for (auto &tInfo: it.Infos())
          {
              std::cout << "Info:" << std::endl;
              std::cout << "  Area:" << std::endl;
              for (auto &tArea: tInfo.Areas())
              {
                  std::cout << "    Altitude: " << tArea.Altitude() << std::endl;
                  std::cout << "    Area Description: " << tArea.AreaDescription() << std::endl;
                  std::cout << "    Ceiling: " << tArea.Ceiling() << std::endl;
                  for (auto &tGeocode: tArea.Geocodes())
                  {
                      std::cout << "    Geocode:" << std::endl;
                      std::cout << "      Value Name: " << tGeocode.ValueName() << std::endl;
                      std::cout << "      Value: " << tGeocode.Value() << std::endl;
                  }
                  for (auto &tPolygon: tArea.Polygons())
                  {
                      std::cout << "    Polygon: " << tPolygon << std::endl;
                  }
                  for (auto &tCircle: tArea.Circles())
                  {
                      std::cout << "    Circle: " << tCircle << std::endl;
                  }
              }
              std::cout << "  Language: " << tInfo.Language() << std::endl;
              for (auto &tCategory: tInfo.Categories())
              {
                  std::cout << "  Category: " << CAPLib::CAPEnumToString(tCategory) << std::endl;
              }
              std::cout << "  Event: " << tInfo.Event() << std::endl;
              for (auto &tResponseType: tInfo.ResponseTypes())
              {
                  std::cout << "  Response Type: " << CAPLib::CAPEnumToString(tResponseType) << std::endl;
              }
              std::cout << "  Urgency: " << CAPLib::CAPEnumToString(tInfo.Urgency()) << std::endl;
              std::cout << "  Severity: " << CAPLib::CAPEnumToString(tInfo.Severity()) << std::endl;
              std::cout << "  Certainty: " << CAPLib::CAPEnumToString(tInfo.Certainty()) << std::endl;
              std::cout << "  Audience" << tInfo.Audience() << std::endl;
              for (auto &tEventCode: tInfo.EventCodes())
              {
                  std::cout << "  Event Code:" << std::endl;
                  std::cout << "    Value Name: " << tEventCode.ValueName() << std::endl;
                  std::cout << "    Value: " << tEventCode.Value() << std::endl;
              }
              std::cout << "  Effective: " << tInfo.Effective() << std::endl;
              std::cout << "  Onset: " << tInfo.Onset() << std::endl;
              std::cout << "  Expires: " << tInfo.Expires() << std::endl;
              std::cout << "  Sender Name: " << tInfo.SenderName() << std::endl;
              std::cout << "  Headline: " << tInfo.Headline() << std::endl;
              std::cout << "  Description: " << tInfo.Description() << std::endl;
              std::cout << "  Instruction: " << tInfo.Instruction() << std::endl;
              std::cout << "  Web: " << tInfo.Web() << std::endl;
              std::cout << "  Contact: " << tInfo.Contact() << std::endl;
              for (auto &tParameter: tInfo.Parameters())
              {
                  std::cout << "  Parameter:" << std::endl;
                  std::cout << "    Value Name: " << tParameter.ValueName() << std::endl;
                  std::cout << "    Value: " << tParameter.Value() << std::endl;
              }
              for (auto &tResource: tInfo.Resources())
              {
                  std::cout << "  Resource:" << std::endl;
                  std::cout << "    Resource Description: " << tResource.ResourceDesc() << std::endl;
                  std::cout << "    Mimetype: " << tResource.MimeType() << std::endl;
                  std::cout << "    Size: " << tResource.Size() << std::endl;
                  std::cout << "    URI: " << tResource.URI() << std::endl;
                  std::cout << "    Deref URI: " << tResource.DerefURI() << std::endl;
                  std::cout << "    Digest: " << tResource.Digest() << std::endl;
              }
          }
      } // for (auto &it: atomEvent.CAPAlertObjects())
  } // try
  catch (std::exception &tempException)
  {
      std::cout << "Caught exception in main: " << tempException.what() << std::endl;
      std::exit(EXIT_FAILURE);
  }
  catch (...)
  {
      std::cout << "An unknown exception occurred in main." << std::endl;
      std::exit(EXIT_FAILURE);
  }

  std::exit(EXIT_SUCCESS);
}
