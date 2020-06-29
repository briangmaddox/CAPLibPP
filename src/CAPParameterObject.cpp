#ifndef CAPPARAMETEROBJECT_CPP
#define CAPPARAMETEROBJECT_CPP

#include <boost/algorithm/string.hpp>
#include <CAPLibpp/CAPParameterObject.h>

namespace CAPLib
{

// ************************************************************************************************
void CAPParameterObject::SetValueName(const std::string &inValueName)
{
  mValueName = inValueName;
}

// ************************************************************************************************
std::string CAPParameterObject::ValueName() const
{
  return mValueName;
}

// ************************************************************************************************
void CAPParameterObject::SetValue(const std::string &inValue)
{
  // First set the class member.
  // As per the CAP spec, we now make sure everything is converted to uppercase in this field.
  // Use the "standard" method to uppercase a std::string
  mValue = boost::to_upper_copy(inValue);
}

// ************************************************************************************************
std::string CAPParameterObject::Value() const
{
  return mValue;
}

// ************************************************************************************************
bool CAPParameterObject::ProcessXML(const boost::property_tree::ptree &inXMLReader)
{
  if (inXMLReader.empty())
  {
    return false;
  }

  try
  {
    SetValueName(inXMLReader.get<std::string>("valueName", ""));
    SetValue(inXMLReader.get<std::string>("value", ""));

    return true;
  }
  catch (...)
  {
    return false;
  }
}

} // namespace CAPLib

#endif // ifndef CAPPARAMETEROBJECT_CPP
