#ifndef CAPPARAMETEROBJECT_H
#define CAPPARAMETEROBJECT_H

#include <string>
#include <boost/property_tree/ptree.hpp>

namespace CAPLib
{

/**
 * @class CAPParameterObject
 * @brief The CAPParameterObject class describes and implements the CAP Parameter field.
 */
class CAPParameterObject
{
public:
  /**
   * @brief CAPParameterObject default constructor
   */
  CAPParameterObject() = default;

  /**
   * @brief setValueName set the value of valueName
   * @param inValue is the new value of valueName
   */
  void SetValueName(const std::string &inValueName);

  /**
   * @brief ValueName Get the value of valueName
   * @return the value of valueName
   */
  std::string ValueName() const;

  /**
   * @brief SetValue set the value of the value field
   * @param inValue input value to set
   */
  void SetValue(const std::string &inValue);

  /**
   * @brief value is the field value associated with valueName
   * @return the value member
   */
  std::string Value() const;

  /**
   * @brief ProcessXML Process the input XML
   * @param inXMLReader const boost::property_tree::ptree of the input stream
   * @return true if successful, false otherwise
   */
  bool ProcessXML(const boost::property_tree::ptree &inXMLReader);

protected:
// None

private:
  /**
   * @brief valueName is a user-assigned string designating the domain of the code.
   */
  std::string mValueName;

  /**
   * @brief value is a string (which may represent a number) denoting the value itself (e.g.,
   * valueName ="SAME" and value="CIV".).  Values of “valueName” that are acronyms SHOULD be
   * represented in all capital letters without periods (e.g., SAME, FIPS, ZIP).
   */
  std::string mValue;
}; // class CAPParameterObject

} // namespace CAPLib
#endif // CAPPARAMETEROBJECT_H
