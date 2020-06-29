#ifndef CAPEVENTCODEOBJECT_CPP
#define CAPEVENTCODEOBJECT_CPP

#include <CAPLibpp/CAPEventCodeObject.h>

namespace CAPLib
{

// ************************************************************************************************
std::string CAPEventCodeObject::ValueName() const
{
  return mValueName;
}

// ************************************************************************************************
void CAPEventCodeObject::SetValueName(const std::string &inValueName)
{
  mValueName = inValueName;
}

// ************************************************************************************************
std::string CAPEventCodeObject::Value() const
{
  return mValue;
}

// ************************************************************************************************
void CAPEventCodeObject::SetValue(const std::string &inValue)
{
  mValue = inValue;
}

// ************************************************************************************************
bool CAPEventCodeObject::ProcessXML(const boost::property_tree::ptree &inXMLReader)
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

}

#endif // #ifndef CAPEVENTCODEOBJECT_CPP
