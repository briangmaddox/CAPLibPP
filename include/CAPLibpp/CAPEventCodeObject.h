#ifndef CAPEVENTCODEOBJECT_H
#define CAPEVENTCODEOBJECT_H

#include <string>
#include <boost/property_tree/ptree.hpp>

namespace CAPLib
{

/**
  * @class CAPEventCodeObject
  * @brief Struct that represents a CAP <eventCode> entry.
  */
class CAPEventCodeObject
{
public:

  /**
   * @brief Gets the valueName of the object.
   * @return string
   */
  std::string ValueName() const;

  /**
   * @brief Sets the valueName of the object.
   * @param inValueName Input valueName for the object.
   */
  void SetValueName(const std::string &inValueName);

  /**
   * @brief Gets the value of the object.
   * @return string of the value
   */
  std::string Value() const;

  /**
   * @brief Sets the value field of the object.
   * @param inValue Input value to set.
   */
  void SetValue(const std::string &inValue);

  /**
   * @brief ProcessXML Processes the input XML to create the object
   * @param inXMLReader boost::property_tree::ptree
   * @return true if successful, false otherwise
   */
  bool ProcessXML(const boost::property_tree::ptree &inXMLReader);

protected:
// None

private:

  /**
   * @brief valueName A user-assigned string designating the domain of the code.
   */
  std::string mValueName;

  /**
   * @brief value A string (which may represent a number) denoting the value itself (e.g., valueName ="SAME" and value="CEM").
   * Values of “valueName” that are acronyms SHOULD be represented in all capital letters without periods (e.g., SAME, FIPS, ZIP).
   */
  std::string mValue;
}; // class CAPEventCode

} // namespace CAPLib
#endif // CAPEVENTCODEOBJECT_H
