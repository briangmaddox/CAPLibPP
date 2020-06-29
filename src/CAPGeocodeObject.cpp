#ifndef CAPGEOCODEOBJECT_CPP
#define CAPGEOCODEOBJECT_CPP

#include <CAPLibpp/CAPGeocodeObject.h>

namespace CAPLib
{

// ************************************************************************************************
std::string CAPGeocodeObject::CAPGeocodeObject::ValueName() const
{
  return mValueName;
}

// ************************************************************************************************
void CAPGeocodeObject::SetValueName(const std::string &inValueName)
{
  mValueName = inValueName;
}

// ************************************************************************************************
std::string CAPGeocodeObject::Value() const
{
  return mValue;
}

// ************************************************************************************************
void CAPGeocodeObject::SetValue(const std::string &inValue)
{
  mValue = inValue;
}

// ************************************************************************************************
bool CAPGeocodeObject::ProcessXML(const boost::property_tree::ptree &inXMLReader)
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

#endif // #ifndef CAPGEOCODEOBJECT_CPP
