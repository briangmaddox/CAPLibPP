#ifndef CAPAREAOBJECT_CPP
#define CAPAREAOBJECT_CPP

#include <CAPLibpp/CAPAreaObject.h>

namespace CAPLib
{

// ************************************************************************************************
std::string CAPLib::CAPAreaObject::Altitude() const
{
  return mAltitude;
}

// ************************************************************************************************
void CAPAreaObject::SetAltitude(const std::string &inAltitude)
{
  mAltitude = inAltitude;
}

// ************************************************************************************************
std::string CAPAreaObject::AreaDescription() const
{
  return mAreaDesc;
}

// ************************************************************************************************
void CAPAreaObject::SetAreaDescription(const std::string &inAreaDescription)
{
  mAreaDesc = inAreaDescription;
}

// ************************************************************************************************
std::string CAPAreaObject::Ceiling() const
{
  return mCeiling;
}

// ************************************************************************************************
void CAPAreaObject::SetCeiling(const std::string &inCeiling)
{
  mCeiling = inCeiling;
}

// ************************************************************************************************
std::vector<CAPGeocodeObject> CAPAreaObject::Geocodes() const
{
  return mGeocode;
}

// ************************************************************************************************
void CAPAreaObject::AddGeocode(const CAPGeocodeObject &inGeocodeObject)
{
  mGeocode.push_back(inGeocodeObject);
}

// ************************************************************************************************
std::vector<std::string> CAPAreaObject::Polygons() const
{
  return mPolygon;
}

// ************************************************************************************************
void CAPAreaObject::AddPolygon(const std::string &inPolygonObject)
{
  mPolygon.push_back(inPolygonObject);
}

// ************************************************************************************************
std::vector<std::string> CAPAreaObject::Circles() const
{
  return mCircle;
}

// ************************************************************************************************
void CAPAreaObject::AddCircle(const std::string &inCircleEntry)
{
  mCircle.push_back(inCircleEntry);
}

// ************************************************************************************************
bool CAPAreaObject::ProcessXML(const boost::property_tree::ptree &inXMLReader)
{
  if (inXMLReader.empty())
  {
    return false;
  }

  try
  {
    // Set the single occurance entities
    SetAreaDescription(inXMLReader.get<std::string>("areaDesc", ""));
    SetAltitude(inXMLReader.get<std::string>("altitude", ""));
    SetCeiling(inXMLReader.get<std::string>("ceiling", ""));

    // Now handle the multiple ones
    for (auto &it: inXMLReader)
    {
      if (it.first == "polygon")
      {
        AddPolygon(it.second.data());
        continue;
      }

      if (it.first == "circle")
      {
        AddCircle(it.second.data());
        continue;
      }

      if (it.first == "geocode")
      {
        CAPGeocodeObject tempGeoCode;
        if (tempGeoCode.ProcessXML(it.second))
        {
          AddGeocode(tempGeoCode);
        }
        continue;
      }
    }

    return true;
  }
  catch (...)
  {
    return false;
  }
}


} // namespace CAPLib

#endif // #ifndef CAPAREAOBJECT_CPP
