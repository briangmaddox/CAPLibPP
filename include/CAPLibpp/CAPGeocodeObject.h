#ifndef CAPGEOCODEOBJECT_H
#define CAPGEOCODEOBJECT_H

#include <string>
#include <boost/property_tree/ptree.hpp>

namespace CAPLib
{

/**
  * @class CAPGeocodeObject
  * @brief The geographic code delineating the affected area the alert message.
  * This element is primarily for compatibility with other systems. Use of this element presumes
  * knowledge of the coding system on the part of recipients; therefore, for interoperability, it
  * SHOULD be used in concert with an equivalent description in the more universally understood
  * <polygon> and <circle> forms whenever possible.
  */
class CAPGeocodeObject
{
public:
  /**
   * @brief ValueName gets the valueName of the object
   * @return valueName string
   */
  std::string ValueName() const;

  /**
   * @brief SetValueName Sets the valueName of the object.
   * @param inValueName Input valueName to set.
   */
  void SetValueName(const std::string &inValueName);

  /**
   * @brief Value Gets the value of the object.
   * @return value string
   */
  std::string Value() const;

  /**
   * Sets the value field of the object.
   * @param  inValue Input value to set.
   */
  void SetValue(const std::string &inValue);

  /**
   * @brief ProcessXML Processes the input XML to create the object
   * @param inXMLReader QXmlStreamReader
   * @return true if successful, false otherwise
   */
  bool ProcessXML(const boost::property_tree::ptree &inXMLReader);

protected:
  // None

private:

  /**
   * @brief valueName is the title of the value
   */
  std::string mValueName;

  /**
   * @brief value is the actual value
   */
  std::string mValue;
}; // class CAPGeocodeObject

} // namespace CAPLib
#endif // CAPGEOCODEOBJECT_H
