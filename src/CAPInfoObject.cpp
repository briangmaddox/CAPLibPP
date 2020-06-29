#ifndef CAPINFOOBJECT_CPP
#define CAPINFOOBJECT_CPP

#include <CAPLibpp/CAPInfoObject.h>
#include <boost/algorithm/string/predicate.hpp>

namespace CAPLib
{

// ************************************************************************************************
CAPInfoObject::CAPInfoObject()
    : mUrgency{CAPUrgencyEnum::UNKNOWN}, mSeverity{CAPSeverityEnum::UNKNOWN},
    mCertainty{CAPCertaintyEnum::UNKNOWN}
{
}

// ************************************************************************************************
std::vector<CAPAreaObject> CAPInfoObject::Areas() const
{
  return mArea;
}

// ************************************************************************************************
void CAPInfoObject::AddArea(const CAPAreaObject &inAreaObject)
{
  mArea.push_back(inAreaObject);
}

// ************************************************************************************************
std::string CAPInfoObject::Language() const
{
  return mLanguage;
}

// ************************************************************************************************
void CAPInfoObject::SetLanguage(const std::string &inLanguage)
{
  mLanguage = inLanguage;
}

// ************************************************************************************************
std::vector<CAPCategoryEnum> CAPInfoObject::Categories() const
{
  return mCategory;
}

// ************************************************************************************************
void CAPInfoObject::AddCategory(const std::string &inCategory)
{
  if (boost::iequals(inCategory, "Geo"))
  {
    mCategory.push_back(CAPCategoryEnum::GEO);
  }
  else if (boost::iequals(inCategory, "Met"))
  {
    mCategory.push_back(CAPCategoryEnum::MET);
  }
  else if (boost::iequals(inCategory, "Safety"))
  {
    mCategory.push_back(CAPCategoryEnum::SAFETY);
  }
  else if (boost::iequals(inCategory, "Security"))
  {
    mCategory.push_back(CAPCategoryEnum::SECURITY);
  }
  else if (boost::iequals(inCategory, "Rescue"))
  {
    mCategory.push_back(CAPCategoryEnum::RESCUE);
  }
  else if (boost::iequals(inCategory, "Fire"))
  {
    mCategory.push_back(CAPCategoryEnum::FIRE);
  }
  else if (boost::iequals(inCategory, "Health"))
  {
    mCategory.push_back(CAPCategoryEnum::HEALTH);
  }
  else if (boost::iequals(inCategory, "Env"))
  {
    mCategory.push_back(CAPCategoryEnum::ENV);
  }
  else if (boost::iequals(inCategory, "Transport"))
  {
    mCategory.push_back(CAPCategoryEnum::TRANSPORT);
  }
  else if (boost::iequals(inCategory, "Infra"))
  {
    mCategory.push_back(CAPCategoryEnum::INFRA);
  }
  else if (boost::iequals(inCategory, "CBRNE"))
  {
    mCategory.push_back(CAPCategoryEnum::CBRNE);
  }
  else if (boost::iequals(inCategory, "Other"))
  {
    mCategory.push_back(CAPCategoryEnum::OTHER);
  }
  else
  {
    mCategory.push_back(CAPCategoryEnum::INVALID);
  }
}

// ************************************************************************************************
std::string CAPInfoObject::Event() const
{
  return mEvent;
}

// ************************************************************************************************
void CAPInfoObject::SetEvent(const std::string &inEvent)
{
  mEvent = inEvent;
}

// ************************************************************************************************
std::vector<CAPResponseTypeEnum> CAPInfoObject::ResponseTypes() const
{
    return mResponseType;
}

// ************************************************************************************************
void CAPInfoObject::AddResponseType(const std::string &inResponseType)
{
  if (boost::iequals(inResponseType, "Shelter"))
  {
    mResponseType.push_back(CAPResponseTypeEnum::SHELTER);
  }
  else if (boost::iequals(inResponseType, "Evacuate"))
  {
    mResponseType.push_back(CAPResponseTypeEnum::EVACUATE);
  }
  else if (boost::iequals(inResponseType, "Prepare"))
  {
    mResponseType.push_back(CAPResponseTypeEnum::PREPARE);
  }
  else if (boost::iequals(inResponseType, "Execute"))
  {
    mResponseType.push_back(CAPResponseTypeEnum::EXECUTE);
  }
  else if (boost::iequals(inResponseType, "Monitor"))
  {
    mResponseType.push_back(CAPResponseTypeEnum::MONITOR);
  }
  else if (boost::iequals(inResponseType, "None"))
  {
    mResponseType.push_back(CAPResponseTypeEnum::NONE);
  }
  else
  {
    mResponseType.push_back(CAPResponseTypeEnum::INVALID);
  }
}

// ************************************************************************************************
CAPUrgencyEnum CAPInfoObject::Urgency() const
{
  return mUrgency;
}

// ************************************************************************************************
void CAPInfoObject::SetUrgency(const std::string &inUrgency)
{
  if (boost::iequals(inUrgency, "Immediate"))
  {
    mUrgency = CAPUrgencyEnum::IMMEDIATE;
  }
  else if (boost::iequals(inUrgency, "Expected"))
  {
    mUrgency = CAPUrgencyEnum::EXPECTED;
  }
  else if (boost::iequals(inUrgency, "Future"))
  {
    mUrgency = CAPUrgencyEnum::FUTURE;
  }
  else if (boost::iequals(inUrgency, "Past"))
  {
    mUrgency = CAPUrgencyEnum::PAST;
  }
  else if (boost::iequals(inUrgency, "Unknown"))
  {
    mUrgency = CAPUrgencyEnum::UNKNOWN;
  }
  else
  {
    mUrgency = CAPUrgencyEnum::INVALID;
  }
}

// ************************************************************************************************
CAPSeverityEnum CAPInfoObject::Severity() const
{
  return mSeverity;
}

// ************************************************************************************************
void CAPInfoObject::SetSeverity(const std::string &inSeverity)
{
  if (boost::iequals(inSeverity, "Extreme"))
  {
    mSeverity = CAPSeverityEnum::EXTREME;
  }
  else if (boost::iequals(inSeverity, "Severe"))
  {
    mSeverity = CAPSeverityEnum::SEVERE;
  }
  else if (boost::iequals(inSeverity, "Moderate"))
  {
    mSeverity = CAPSeverityEnum::MODERATE;
  }
  else if (boost::iequals(inSeverity, "Minor"))
  {
    mSeverity = CAPSeverityEnum::MINOR;
  }
  else if (boost::iequals(inSeverity, "Unknown"))
  {
    mSeverity = CAPSeverityEnum::UNKNOWN;
  }
  else
  {
    mSeverity = CAPSeverityEnum::INVALID;
  }
}

// ************************************************************************************************
CAPCertaintyEnum CAPInfoObject::Certainty() const
{
  return mCertainty;
}

// ************************************************************************************************
void CAPInfoObject::SetCertainty(const std::string &inCertainty)
{
  if (boost::iequals(inCertainty, "Observed"))
  {
    mCertainty = CAPCertaintyEnum::OBSERVED;
  }
  else if (boost::iequals(inCertainty, "Likely"))
  {
    mCertainty = CAPCertaintyEnum::LIKELY;
  }
  else if (boost::iequals(inCertainty, "Possible"))
  {
    mCertainty = CAPCertaintyEnum::POSSIBLE;
  }
  else if (boost::iequals(inCertainty, "Unlikely"))
  {
    mCertainty = CAPCertaintyEnum::UNLIKELY;
  }
  else if (boost::iequals(inCertainty, "Unknown"))
  {
    mCertainty = CAPCertaintyEnum::UNKNOWN;
  }
  else
  {
    mCertainty = CAPCertaintyEnum::INVALID;
  }
}

// ************************************************************************************************
std::string CAPInfoObject::Audience() const
{
  return mAudience;
}

// ************************************************************************************************
void CAPInfoObject::SetAudience(const std::string &inAudience)
{
  mAudience = inAudience;
}

// ************************************************************************************************
std::vector<CAPEventCodeObject> CAPInfoObject::EventCodes() const
{
  return mEventCode;
}

// ************************************************************************************************
void CAPInfoObject::AddEventCode(const CAPEventCodeObject &inEventCode)
{
  mEventCode.push_back(inEventCode);
}

// ************************************************************************************************
std::string CAPInfoObject::Effective() const
{
  return mEffective;
}

// ************************************************************************************************
void CAPInfoObject::SetEffective(const std::string &inEffective)
{
  mEffective = inEffective;
}

// ************************************************************************************************
std::string CAPInfoObject::Onset() const
{
  return mOnset;
}

// ************************************************************************************************
void CAPInfoObject::SetOnset(const std::string &inOnset)
{
  mOnset = inOnset;
}

// ************************************************************************************************
std::string CAPInfoObject::Expires() const
{
  return mExpires;
}

// ************************************************************************************************
void CAPInfoObject::SetExpires(const std::string &inExpires)
{
  mExpires = inExpires;
}

// ************************************************************************************************
std::string CAPInfoObject::SenderName() const
{
    return mSenderName;
}

// ************************************************************************************************
void CAPInfoObject::SetSenderName(const std::string &inSenderName)
{
    mSenderName = inSenderName;
}

// ************************************************************************************************
std::string CAPInfoObject::Headline() const
{
  return mHeadline;
}

// ************************************************************************************************
void CAPInfoObject::SetHeadline(const std::string &inHeadline)
{
  mHeadline = inHeadline;
}

// ************************************************************************************************
std::string CAPInfoObject::Description() const
{
  return mDescription;
}

// ************************************************************************************************
void CAPInfoObject::SetDescription(const std::string &inDescription)
{
  mDescription = inDescription;
}

// ************************************************************************************************
std::string CAPInfoObject::Instruction() const
{
  return mInstruction;
}

// ************************************************************************************************
void CAPInfoObject::SetInstruction(const std::string &inInstruction)
{
  mInstruction = inInstruction;
}

// ************************************************************************************************
std::string CAPInfoObject::Web() const
{
  return mWeb;
}

// ************************************************************************************************
void CAPInfoObject::SetWeb(const std::string &inWeb)
{
  mWeb = inWeb;
}

// ************************************************************************************************
std::string CAPInfoObject::Contact() const
{
  return mContact;
}

// ************************************************************************************************
void CAPInfoObject::SetContact(const std::string &inContact)
{
  mContact = inContact;
}

// ************************************************************************************************
std::vector<CAPParameterObject> CAPInfoObject::Parameters() const
{
  return mParameters;
}

// ************************************************************************************************
void CAPInfoObject::AddParameter(const CAPParameterObject& inParameter)
{
  mParameters.push_back(inParameter);
}

// ************************************************************************************************
std::vector<CAPResourceObject> CAPInfoObject::Resources() const
{
  return mResources;
}

// ************************************************************************************************
void CAPInfoObject::AddResource(const CAPResourceObject &inResource)
{
  mResources.push_back(inResource);
}

// ************************************************************************************************
bool CAPInfoObject::ProcessXML(const boost::property_tree::ptree &inXMLReader)
{
  if (inXMLReader.empty())
  {
    return false;
  }

  try
  {
    // Set the simple elements
    SetLanguage(inXMLReader.get<std::string>("language", ""));
    SetEvent(inXMLReader.get<std::string>("event", ""));
    SetUrgency(inXMLReader.get<std::string>("urgency", ""));
    SetSeverity(inXMLReader.get<std::string>("severity", ""));
    SetCertainty(inXMLReader.get<std::string>("certainty", ""));
    SetAudience(inXMLReader.get<std::string>("audience", ""));
    SetEffective(inXMLReader.get<std::string>("effective", ""));
    SetOnset(inXMLReader.get<std::string>("onset", ""));
    SetExpires(inXMLReader.get<std::string>("expires", ""));
    SetSenderName(inXMLReader.get<std::string>("senderName", ""));
    SetHeadline(inXMLReader.get<std::string>("headline", ""));
    SetDescription(inXMLReader.get<std::string>("description", ""));
    SetInstruction(inXMLReader.get<std::string>("instruction", ""));
    SetWeb(inXMLReader.get<std::string>("web", ""));
    SetContact(inXMLReader.get<std::string>("contact", ""));

    // Now handle the multiple occuring elements
    for (auto &it: inXMLReader)
    {
      if (it.first == "category")
      {
        AddCategory(it.second.data());
        continue;
      }

      if (it.first == "responseType")
      {
        AddResponseType(it.second.data());
        continue;
      }

      if (it.first == "eventCode")
      {
        CAPEventCodeObject tempEventCode;
        if (tempEventCode.ProcessXML(it.second))
        {
          AddEventCode(tempEventCode);
        }

        continue;
      }

      if (it.first == "parameter")
      {
        CAPParameterObject tempParameter;
        if (tempParameter.ProcessXML(it.second))
        {
          AddParameter(tempParameter);
        }

        continue;
      }

      if (it.first == "resource")
      {
        CAPResourceObject tempResource;
        if (tempResource.ProcessXML(it.second))
        {
          AddResource(tempResource);
        }

        continue;
      }

      if (it.first == "area")
      {
        CAPAreaObject tempArea;
        if (tempArea.ProcessXML(it.second))
        {
          AddArea(tempArea);
        }

        continue;
      }

    } // for (auto &it: inXMLReader)

    return true;
  }
  catch (...)
  {
    return false;
  }
}

} // namespace CAPLib

#endif // #ifndef CAPINFOOBJECT_CPP
