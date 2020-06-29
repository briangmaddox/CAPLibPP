#ifndef NOAACAPALERTOBJECT_CPP
#define NOAACAPALERTOBJECT_CPP

#include <boost/algorithm/string/predicate.hpp>
#include <CAPLibpp/NOAACAPAlertObject.h>

namespace CAPLib
{
// ************************************************************************************************
NOAACAPAlertObject::NOAACAPAlertObject()
  : mStatus{CAPStatusEnum::INVALID}, mMsgType{CAPMsgTypeEnum::INVALID}, mScope{CAPScopeEnum::INVALID}
{

}

// ************************************************************************************************
std::string NOAACAPAlertObject::Identifier() const
{
  return mIdentifier;
}

// ************************************************************************************************
void NOAACAPAlertObject::SetIdentifier(const std::string &inIdentifier)
{
  mIdentifier = inIdentifier;
}

// ************************************************************************************************
std::string NOAACAPAlertObject::Sender() const
{
  return mSender;
}

// ************************************************************************************************
void NOAACAPAlertObject::SetSender(const std::string &inSender)
{
  mSender = inSender;
}

// ************************************************************************************************
std::string NOAACAPAlertObject::Sent() const
{
  return mSent;
}

// ************************************************************************************************
void NOAACAPAlertObject::SetSent(const std::string &inSent)
{
  mSent = inSent;
}

// ************************************************************************************************
CAPStatusEnum NOAACAPAlertObject::Status() const
{
  return mStatus;
}

// ************************************************************************************************
void NOAACAPAlertObject::SetStatus(const std::string &inStatus)
{
  if (boost::iequals(inStatus, "Actual"))
  {
    mStatus = CAPStatusEnum::ACTUAL;
  }
  else if (boost::iequals(inStatus, "Exercise"))
  {
    mStatus = CAPStatusEnum::EXERCISE;
  }
  else if (boost::iequals(inStatus, "System"))
  {
    mStatus = CAPStatusEnum::SYSTEM;
  }
  else if (boost::iequals(inStatus, "Test"))
  {
    mStatus = CAPStatusEnum::TEST;
  }
  else if (boost::iequals(inStatus, "Draft"))
  {
    mStatus = CAPStatusEnum::DRAFT;
  }
  else
  {
    mStatus = CAPStatusEnum::INVALID;
  }
}

// ************************************************************************************************
CAPMsgTypeEnum NOAACAPAlertObject::MsgType() const
{
  return mMsgType;
}

// ************************************************************************************************
void NOAACAPAlertObject::SetMsgType(const std::string &inMsgType)
{
  if (boost::iequals(inMsgType, "Alert"))
  {
    mMsgType = CAPMsgTypeEnum::ALERT;
  }
  else if (boost::iequals(inMsgType, "Update"))
  {
    mMsgType = CAPMsgTypeEnum::UPDATE;
  }
  else if (boost::iequals(inMsgType, "Cancel"))
  {
    mMsgType = CAPMsgTypeEnum::CANCEL;
  }
  else if (boost::iequals(inMsgType, "Ack"))
  {
    mMsgType = CAPMsgTypeEnum::ACK;
  }
  else if (boost::iequals(inMsgType, "Error"))
  {
    mMsgType = CAPMsgTypeEnum::ERROR;
  }
  else
  {
    mMsgType = CAPMsgTypeEnum::INVALID;
  }
}

// ************************************************************************************************
std::string NOAACAPAlertObject::Source() const
{
  return mSource;
}

// ************************************************************************************************
void NOAACAPAlertObject::SetSource(const std::string &inSource)
{
  mSource = inSource;
}

// ************************************************************************************************
CAPScopeEnum NOAACAPAlertObject::Scope() const
{
  return mScope;
}

// ************************************************************************************************
void NOAACAPAlertObject::SetScope(const std::string &inScope)
{
  if (boost::iequals(inScope, "public"))
  {
    mScope = CAPScopeEnum::PUBLIC;
  }
  else if (boost::iequals(inScope, "restricted"))
  {
    mScope = CAPScopeEnum::RESTRICTED;
  }
  else if (boost::iequals(inScope, "private"))
  {
    mScope = CAPScopeEnum::PRIVATE;
  }
  else
  {
    mScope = CAPScopeEnum::INVALID;
  }
}

// ************************************************************************************************
std::string NOAACAPAlertObject::Restriction() const
{
  return mRestriction;
}

// ************************************************************************************************
void NOAACAPAlertObject::SetRestriction(const std::string &inRestriction)
{
  mRestriction = inRestriction;
}

// ************************************************************************************************
std::string NOAACAPAlertObject::Addresses() const
{
  return mAddresses;
}

// ************************************************************************************************
void NOAACAPAlertObject::SetAddresses(const std::string &inAddresses)
{
  mAddresses = inAddresses;
}

// ************************************************************************************************
std::vector<std::string> NOAACAPAlertObject::Codes() const
{
  return mCodes;
}

// ************************************************************************************************
void NOAACAPAlertObject::AddCode(const std::string &inCodes)
{
  mCodes.push_back(inCodes);
}

// ************************************************************************************************
std::string NOAACAPAlertObject::Note() const
{
  return mNote;
}

// ************************************************************************************************
void NOAACAPAlertObject::SetNote(const std::string &inNote)
{
  mNote = inNote;
}

// ************************************************************************************************
std::string NOAACAPAlertObject::References() const
{
  return mReferences;
}

// ************************************************************************************************
void NOAACAPAlertObject::SetReferences(const std::string &inReferences)
{
  mReferences = inReferences;
}

// ************************************************************************************************
std::string NOAACAPAlertObject::Incidents() const
{
  return mIncidents;
}

// ************************************************************************************************
void NOAACAPAlertObject::SetIncidents(const std::string &inIncidents)
{
  mIncidents = inIncidents;
}

// ************************************************************************************************
std::vector<CAPInfoObject> NOAACAPAlertObject::Infos() const
{
  return mInfo;
}

// ************************************************************************************************
void NOAACAPAlertObject::AddInfo(const CAPInfoObject &inInfo)
{
  mInfo.push_back(inInfo);
}

// ************************************************************************************************
bool NOAACAPAlertObject::ProcessXML(const boost::property_tree::ptree &inXMLReader)
{
  if (inXMLReader.empty())
  {
    return false;
  }

  try
  {
    // First set the single entries
    SetIdentifier(inXMLReader.get<std::string>("alert.identifier", ""));
    SetSender(inXMLReader.get<std::string>("alert.sender", ""));
    SetSent(inXMLReader.get<std::string>("alert.sent", ""));
    SetStatus(inXMLReader.get<std::string>("alert.status", ""));
    SetMsgType(inXMLReader.get<std::string>("alert.msgType", ""));
    SetSource(inXMLReader.get<std::string>("alert.source", ""));
    SetScope(inXMLReader.get<std::string>("alert.scope", ""));
    SetRestriction(inXMLReader.get<std::string>("alert.restriction", ""));
    SetAddresses(inXMLReader.get<std::string>("alert.addresses", ""));
    SetNote(inXMLReader.get<std::string>("alert.note", ""));
    SetReferences(inXMLReader.get<std::string>("alert.references", ""));
    SetIncidents(inXMLReader.get<std::string>("alert.incidents", ""));

    // Now we handle the members that can occur more than once
    for (auto &tNode: inXMLReader.get_child("alert"))
    {
      if (tNode.first == "info")
      {
        // Do the info portion
        CAPInfoObject tempInfo;
        if (tempInfo.ProcessXML(tNode.second))
        {
          AddInfo(tempInfo);
        }
        continue;
      }

      if (tNode.first == "code")
      {
        AddCode(tNode.second.data());

        continue;
      }
    }
  }
  catch (...)
  {
    return false;
  }

  return true;
}

} // namespace CAPLib

#endif // #ifndef NOAACAPALERTOBJECT_CPP
