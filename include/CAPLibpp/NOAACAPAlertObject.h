#ifndef NOAACAPALERTOBJECT_H
#define NOAACAPALERTOBJECT_H

#include <string>
#include <vector>
#include <boost/property_tree/ptree.hpp>
#include <CAPLibpp/CAPInfoObject.h>
#include <CAPLibpp/CAPLibEnums.h>

namespace CAPLib
{

/**
 * @brief The NOAACAPAlertObject class models a NOAA Common Alerting Protocol (CAP) entity.
 * This object encapsulates individual CAP alerts from the RSS feed.
 */
class NOAACAPAlertObject
{
public:

  /**
   * @brief NOAACAPAlertObject Default Constructor
   */
  NOAACAPAlertObject();

  /**
   * @brief Identifier returns the mIdentifier field.
   * @return std::string of the identifier
   */
  std::string Identifier() const;

  /**
   * @brief SetIdentifier Sets the mIdentifier field of the object
   * @param inIdentifier input string to set
   */
  void SetIdentifier(const std::string &inIdentifier);

  /**
   * @brief Sender returns the mSender field of the object
   * @return std::string of the sender
   */
  std::string Sender() const;

  /**
   * @brief SetSender sets the mSender field of the object
   * @param inSender input string to set
   */
  void SetSender(const std::string &inSender);

  /**
   * @brief Sent returns the mSent field of the object
   * @return std::string representing mSent
   */
  std::string Sent() const;

  /**
   * @brief SetSent sets the mSent field of the object
   * @param inSent input std::string to set
   */
  void SetSent(const std::string &inSent);

  /**
   * @brief Status returns the mStatus field of the object
   * @return CAPStatusEnum representing the status
   */
  CAPStatusEnum Status() const;

  /**
   * @brief SetStatus sets the mStatus field of the object
   * @param inStatus input CAPStatusEnum to set
   */
  void SetStatus(const std::string &inStatus);

  /**
   * @brief MsgType returns the mMsgType field of the object
   * @return CAPMsgTypeEnum representing the mMsgType
   */
  CAPMsgTypeEnum MsgType() const;

  /**
   * @brief SetMsgType sets the mMsgType field of the object
   * @param inMsgType input CAPMsgTypeEnum to set
   */
  void SetMsgType(const std::string &inMsgType);

  /**
   * @brief Source returns the mSource field of the object
   * @return std::string of the mSource
   */
  std::string Source() const;

  /**
   * @brief SetSource sets the mSource field of the object
   * @param inSource input std::string to set
   */
  void SetSource(const std::string &inSource);

  /**
   * @brief Scope returns the mScope field of the object
   * @return CAPScopeEnum of the mScope
   */
  CAPScopeEnum Scope() const;

  /**
   * @brief SetScope sets the mScope field of the object
   * @param inScope input CAPScopeEnum to set
   */
  void SetScope(const std::string &inScope);

  /**
   * @brief Restriction returns the mRestriction field of the object
   * @return std::string of the restriction
   */
  std::string Restriction() const;

  /**
   * @brief SetRestriction sets the mRestriction field of the object
   * @param inRestriction input string to set
   */
  void SetRestriction(const std::string &inRestriction);

  /**
   * @brief Addresses returns the mAddresses field of the object
   * @return string of the addresses
   */
  std::string Addresses() const;

  /**
   * @brief SetAddresses sets the mAddresses field of the object
   * @param inAddresses input string to set
   */
  void SetAddresses(const std::string &inAddresses);

  /**
   * @brief Codes returns the mCodes field of the object
   * @return  vector of the codes
   */
  std::vector<std::string> Codes() const;

  /**
   * @brief SetCodes sets the mCodes field of the object
   * @param inCodes input vector to set
   */
  void AddCode(const std::string &inCodes);

  /**
   * @brief Note returns the mNote field of the object
   * @return string of the note
   */
  std::string Note() const;

  /**
   * @brief SetNote sets the mNote field of the object
   * @param inNote input string to set
   */
  void SetNote(const std::string &inNote);

  /**
   * @brief References rerturns the mReferences field of the object
   * @return string of the references
   */
  std::string References() const;

  /**
   * @brief SetReferences sets the mReferences field of the object
   * @param inReferences input string to set
   */
  void SetReferences(const std::string &inReferences);

  /**
   * @brief Incidents returns the mIncidents field of the object
   * @return string of the incidents
   */
  std::string Incidents() const;

  /**
   * @brief SetIncidents sets the mIncidents field of the object
   * @param inIncidents input string to set
   */
  void SetIncidents(const std::string &inIncidents);

  /**
   * @brief Info returns the mInfo field of the object
   * @return vector of CAPInfoObjects
   */
  std::vector<CAPInfoObject> Infos() const;

  /**
   * @brief SetInfo sets the mInfo field of the object
   * @param inInfo input vector to set
   */
  void AddInfo(const CAPInfoObject &inInfo);

  /**
   * @brief ProcessXML processes the incoming XML to create the object
   * @param inXML QXMLStreamReader of the XML starting at the <entry> element
   * @return true on success, false otherwise
   */
  bool ProcessXML(const boost::property_tree::ptree &inXMLReader);

protected:
  // None

private:

  /**
   * @brief mIdentifier A number or std::string uniquely identifying this message, assigned by the sender.
   * MUST NOT include spaces, commas or restricted characters (< and &).
   */
  std::string mIdentifier;

  /**
   * @brief mSender Identifies the originator of this alert.
   * Guaranteed by assigner to be unique globally; e.g., may be based on an Internet domain name . MUST
   * NOT include spaces, commas or restricted characters (< and &)
   */
  std::string mSender;

  /**
   * @brief mSent The time and date of the origination of the alert message.
   * The date and time is represented in [dateTime] format (e. g., "2002-05- 24T16:49:00-07:00" for 24 May 2002
   * at 16: 49 PDT). Alphabetic timezone designators such as “Z” MUST NOT be used. The timezone for UTC MUST be
   * represented as “-00:00” or “+00:00.
   */
  std::string mSent;

  /**
   * @brief mStatus The code denoting the appropriate handling of the alert message.
   */
  CAPStatusEnum mStatus;

  /**
   * @brief mMsgType The code denoting the nature of the alert message.
   */
  CAPMsgTypeEnum mMsgType;

  /**
   * @brief mSource The particular source of this alert; e.g., an operator or a specific device.
   */
  std::string mSource;

  /**
   * @brief mScope The code denoting the intended distribution of the alert message.
   */
  CAPScopeEnum mScope;

  /**
   * @brief mRestriction The text describing the rule for limiting distribution of the restricted alert message.
   * Used when <scope> value is "Restricted".
   */
  std::string mRestriction;

  /**
   * @brief mAddresses The group listing of intended recipients of the private alert message.
   * Used when <scope> value is "Private". Each recipient SHALL be identified by an identifier or an address. Multiple
   * space-delimited addresses MAY be included. Addresses including whitespace MUST be enclosed in double-quotes.
   */
  std::string mAddresses;

  /**
   * @brief mCodes The code denoting the special handling of the alert message.
   * Any user-defined flag or special code used to flag the alert message for special handling. Multiple instances MAY
   * occur within a single <info> block.
   */
  std::vector<std::string> mCodes;

  /**
   * @brief mNote The text describing the purpose or significance of the alert message.
   * The message note is primarily intended for use with Cancel and Error alert message types.
   */
  std::string mNote;

  /**
   * @brief mReferences The group listing identifying earlier message(s) referenced by the alert message.
   * The extended message identifier(s) (in the form sender,identifier,sent) of an earlier CAP message or messages
   * referenced by this one.  If multiple messages are referenced, they SHALL be separated by whitespace.
   */
  std::string mReferences;

  /**
   * @brief mIncidents The group listing naming the referent incident(s) of the alert message.
   * Used to collate multiple messages referring to different aspects of the same incident  If multiple incident
   * identifiers are referenced, they SHALL be separated by whitespace. Incident names including whitespace SHALL be
   * surrounded by double-quotes.
   */
  std::string mIncidents;

  /**
   * @brief mInfo The container for all component parts of the info sub-element of the alert message.
   * Multiple occurrences are permitted within a single <alert>. If targeting of multiple "info" blocks in the same language
   * overlaps, information in later blocks may expand but may not override the corresponding values in earlier ones. Each set
   * of "info" blocks containing the same language identifier SHALL be treated as a separate sequence.  In addition to the
   * specified sub-elements, MAY contain one or more <resource> blocks and/or one or more <area> blocks.
   */
  std::vector<CAPInfoObject> mInfo;
};

} // namespace CAPLib
#endif // NOAACAPALERTOBJECT_H
