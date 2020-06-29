#ifndef CAPLIBENUMS_CPP
#define CAPLIBENUMS_CPP

#include <CAPLibpp/CAPLibEnums.h>

namespace CAPLib
{
// Functions to convert enums to strings
// *********************************************************************************************************************
std::string CAPEnumToString(const CAPCategoryEnum &inCategoryEnum)
{
  switch (inCategoryEnum)
  {
    case CAPCategoryEnum::GEO:
      return std::string("GEO");
    case CAPCategoryEnum::MET:
      return std::string("MET");
    case CAPCategoryEnum::SAFETY:
      return std::string("SAFETY");
    case CAPCategoryEnum::SECURITY:
      return std::string("SECURITY");
    case CAPCategoryEnum::RESCUE:
      return std::string("RESCUE");
    case CAPCategoryEnum::FIRE:
      return std::string("FIRE");
    case CAPCategoryEnum::HEALTH:
      return std::string("HEALTH");
    case CAPCategoryEnum::ENV:
      return std::string("ENV");
    case CAPCategoryEnum::TRANSPORT:
      return std::string("TRANSPORT");
    case CAPCategoryEnum::INFRA:
      return std::string("INFRA");
    case CAPCategoryEnum::CBRNE:
      return std::string("CBRNE");
    case CAPCategoryEnum::OTHER:
      return std::string("OTHER");
    default:
      return std::string("INVALID");
  }
}

// *********************************************************************************************************************
std::string CAPEnumToString(const CAPCertaintyEnum &inCertaintyEnum)
{
  switch (inCertaintyEnum)
  {
    case CAPCertaintyEnum::OBSERVED:
      return std::string("OBSERVED");
    case CAPCertaintyEnum::LIKELY:
      return std::string("LIKELY");
    case CAPCertaintyEnum::POSSIBLE:
      return std::string("POSSIBLE");
    case CAPCertaintyEnum::UNLIKELY:
      return std::string("UNLIKELY");
    case CAPCertaintyEnum::UNKNOWN:
      return std::string("UNKNOWN");
    default:
      return std::string("INVALID");
  }
}
// *********************************************************************************************************************
std::string CAPEnumToString(const CAPMsgTypeEnum &inMsgTypeEnum)
{
  switch (inMsgTypeEnum)
  {
    case CAPMsgTypeEnum::ALERT:
      return std::string("ALERT");
    case CAPMsgTypeEnum::UPDATE:
      return std::string("UPDATE");
    case CAPMsgTypeEnum::CANCEL:
      return std::string("CANCEL");
    case CAPMsgTypeEnum::ACK:
      return std::string("ACK");
    case CAPMsgTypeEnum::ERROR:
      return std::string("ERROR");
    default:
      return std::string("INVALID");
  }
}

// *********************************************************************************************************************
std::string CAPEnumToString(const CAPResponseTypeEnum &inResponseTypeEnum)
{
  switch (inResponseTypeEnum)
  {
    case CAPResponseTypeEnum::SHELTER:
      return std::string("SHELTER");
    case CAPResponseTypeEnum::EVACUATE:
      return std::string("EVACUATE");
    case CAPResponseTypeEnum::PREPARE:
      return std::string("PREPARE");
    case CAPResponseTypeEnum::EXECUTE:
      return std::string("EXECUTE");
    case CAPResponseTypeEnum::MONITOR:
      return std::string("MONITOR");
    case CAPResponseTypeEnum::ASSESS:
      return std::string("ASSESS");
    case CAPResponseTypeEnum::NONE:
      return std::string("NONE");
    default:
      return std::string("INVALID");
  }
}

// *********************************************************************************************************************
std::string CAPEnumToString(const CAPScopeEnum &inScopeEnum)
{
  switch (inScopeEnum)
  {
    case CAPScopeEnum::PUBLIC:
      return std::string("PUBLIC");
    case CAPScopeEnum::RESTRICTED:
      return std::string("RESTRICTED");
    case CAPScopeEnum::PRIVATE:
      return std::string("PRIVATE");
    default:
      return std::string("INVALID");
  }
}

// *********************************************************************************************************************
std::string CAPEnumToString(const CAPSeverityEnum &inSeverityEnum)
{
  switch (inSeverityEnum)
  {
    case CAPSeverityEnum::EXTREME:
      return std::string("EXTREME");
    case CAPSeverityEnum::SEVERE:
      return std::string("SEVERE");
    case CAPSeverityEnum::MODERATE:
      return std::string("MODERATE");
    case CAPSeverityEnum::MINOR:
      return std::string("MINOR");
    case CAPSeverityEnum::UNKNOWN:
      return std::string("UNKNOWN");
    default:
      return std::string("INVALID");
  }
}

// *********************************************************************************************************************
std::string CAPEnumToString(const CAPStatusEnum &inStatusEnum)
{
  switch (inStatusEnum)
  {
   case CAPStatusEnum::ACTUAL:
      return std::string("ACTUAL");
    case CAPStatusEnum::EXERCISE:
      return std::string("EXERCISE");
    case CAPStatusEnum::SYSTEM:
      return std::string("SYSTEM");
    case CAPStatusEnum::TEST:
      return std::string("TEST");
    case CAPStatusEnum::DRAFT:
      return std::string("DRAFT");
    default:
      return std::string("INVALID");
  }
}

// *********************************************************************************************************************
std::string CAPEnumToString(const CAPUrgencyEnum &inUrgencyEnum)
{
  switch (inUrgencyEnum)
  {
    case CAPUrgencyEnum::IMMEDIATE:
      return std::string("IMMEDIATE");
    case CAPUrgencyEnum::EXPECTED:
      return std::string("EXPECTED");
    case CAPUrgencyEnum::FUTURE:
      return std::string("FUTURE");
    case CAPUrgencyEnum::PAST:
      return std::string("PAST");
    case CAPUrgencyEnum::UNKNOWN:
      return std::string("UNKNOWN");
    default:
      return std::string("INVALID");
  }
}

} // namespace

#endif
