#ifndef CAPINFOOBJECT_H
#define CAPINFOOBJECT_H

#include <string>
#include <vector>
#include <boost/property_tree/ptree.hpp>
#include <CAPLibpp/CAPAreaObject.h>
#include <CAPLibpp/CAPLibEnums.h>
#include <CAPLibpp/CAPEventCodeObject.h>
#include <CAPLibpp/CAPParameterObject.h>
#include <CAPLibpp/CAPResourceObject.h>

namespace CAPLib
{

/**
  * @class CAPInfoObject
  * @brief The container for all component parts of the info sub- element of the alert message.
  * Multiple occurrences are permitted within a single <alert>. If targeting of multiple "info" blocks
  * in the same language overlaps, information in later blocks may expand but may not override the
  * corresponding values in earlier ones. Each set of "info" blocks containing the same language
  * identifier SHALL be treated as a separate sequence. In addition to the specified sub-elements, MAY
  * contain one or more <resource> blocks and/or one or more <area> blocks.
  */
class CAPInfoObject
{
public:

  /**
   * @brief CAPInfoObject Default Constructor
   */
  CAPInfoObject();

  /**
   * @brief Gets the area vector of the object.
   * @return vector<CAPAreaObject> of the area objects
   */
  std::vector<CAPAreaObject> Areas() const;

  /**
   * @brief Adds an individual area entry to the internal vector.
   * @param inAreaObject Input area object to add.
   */
  void AddArea(const CAPAreaObject &inAreaObject);

  /**
   * @brief Language returns the <language> field.
   * @return string representing the language
   */
  std::string Language() const;

  /**
   * @brief SetLanguage sets the language entry of the object.
   * @param inLanguage input language to set.
   */
  void SetLanguage(const std::string &inLanguage);

  /**
   * @brief Category returns the <category> field(s) of the object.
   * @return vector of CAPCategoryEnum objects
   */
  std::vector<CAPCategoryEnum> Categories() const;

  /**
   * @brief SetCategory sets the <category> field of the object
   * @param inCategory Input vector to use.
   */
  void AddCategory(const std::string &inCategory);

  /**
   * @brief Event returns the <event> field of the object.
   * @return string representing the <event> field.
   */
  std::string Event() const;

  /**
   * @brief SetEvent sets the <event> field of the object
   * @param inEvent input string to set.
   */
  void SetEvent(const std::string &inEvent);

  /**
   * @brief ResponseType returns the <responsetype> fields of the object
   * @return vector collection of CAPResponseTypeEnum
   */
  std::vector<CAPResponseTypeEnum> ResponseTypes() const;

  /**
   * @brief AddResponseType adds a single CAPResponseTypeEnum to the object's vector
   * @param inResponseType input CAPResponseTypeEnum to add
   */
  void AddResponseType(const std::string &inResponseType);

  /**
   * @brief Urgency rerturns the <urgency> field of the object
   * @return CAPUrgencyEnum
   */
  CAPUrgencyEnum Urgency() const;

  /**
   * @brief SetUrgency sets the <urgency> field of the object
   * @param inUrgency input CAPUrgencyEnum to set
   */
  void SetUrgency(const std::string &inUrgency);

  /**
   * @brief Severity returns the <severity> field of the object
   * @return CAPSeverityEnum
   */
  CAPSeverityEnum Severity() const;

  /**
   * @brief SetSeverity sets the <severity> field of the object
   * @param inSeverity input CAPSeverityEnum to set
   */
  void SetSeverity(const std::string &inSeverity);

  /**
   * @brief Certainty returns the <certainty> field of the object
   * @return CAPCertaintyEnum
   */
  CAPCertaintyEnum Certainty() const;

  /**
   * @brief SetCertainty sets the <certainty> field of the object.
   * @param inCertainty input CAPCertaintyEnum to set
   */
  void SetCertainty(const std::string &inCertainty);

  /**
   * @brief Audience returns the <audience> field of the object
   * @return string representing the field
   */
  std::string Audience() const;

  /**
   * @brief SetAudience sets the <audience> field of the object
   * @param inAudience input string to set
   */
  void SetAudience(const std::string &inAudience);

  /**
   * @brief EventCode returns the <eventCode> field of the object
   * @return vector of CAPEventCodeObjects
   */
  std::vector<CAPEventCodeObject> EventCodes() const;

  /**
   * @brief AddEventCode adds a single CAPEventCodeObject to the object's vector
   * @param inEventCode input CAPEventCodeObject to add
   */
  void AddEventCode(const CAPEventCodeObject &inEventCode);

  /**
   * @brief Effective returns the <effective> field of the object
   * @return QDate object
   */
  std::string Effective() const;

  /**
   * @brief SetEffective sets the <effective> field of the object
   * @param inEffective input QDate to set
   */
  void SetEffective(const std::string &inEffective);

  /**
   * @brief Onset returns the <onset> field of the object
   * @return QDate object
   */
  std::string Onset() const;

  /**
   * @brief SetOnset sets the <onset> field of the object
   * @param inOnset input QDate to set
   */
  void SetOnset(const std::string &inOnset);

  /**
   * @brief Expires returns the <expires> field of the object
   * @return QDate object
   */
  std::string Expires() const;

  /**
   * @brief SetExpires sets the <expires> field of the object
   * @param inExpires input QDate to set
   */
  void SetExpires(const std::string &inExpires);

  /**
   * @brief SenderName returns the <senderName> field of the object
   * @return string of the sender name
   */
  std::string SenderName() const;

  /**
   * @brief SetSenderName sets the <senderName> field of the object
   * @param inSenderName input string to set
   */
  void SetSenderName(const std::string &inSenderName);

  /**
   * @brief Headline returns the <headline> field of the object
   * @return  string of the object headline
   */
  std::string Headline() const;

  /**
   * @brief SetHeadline sets the <headline> field of the object
   * @param inHeadline input string to set
   */
  void SetHeadline(const std::string &inHeadline);

  /**
   * @brief Description gets the <description> field of the object
   * @return string representing the description.
   */
  std::string Description() const;

  /**
   * @brief SetDescription sets the <description> field of the object
   * @param inDescription input string to set
   */
  void SetDescription(const std::string &inDescription);

  /**
   * @brief Instruction gets the <instruction> field of the object
   * @return string of the instructions
   */
  std::string Instruction() const;

  /**
   * @brief SetInstruction sets the <instruction> field of the object
   * @param inInstruction input string to set
   */
  void SetInstruction(const std::string &inInstruction);

  /**
   * @brief Web gets the <web> field of the object
   * @return QUrl of the field
   */
  std::string Web() const;

  /**
   * @brief SetWeb sets the <web> field of the object
   * @param inWeb input QUrl to set
   */
  void SetWeb(const std::string &inWeb);

  /**
   * @brief Contact returns the <contact> field of the object
   * @return string of the contact information
   */
  std::string Contact() const;

  /**
   * @brief SetContact sets the <contact> field of the object
   * @param inContact input string to set
   */
  void SetContact(const std::string &inContact);

  /**
   * @brief Parameters gets the <parameters> vector of the object
   * @return vector of CAPParameterObjects
   */
  std::vector<CAPParameterObject> Parameters() const;

  /**
   * @brief AddParameter adds an individual CAPParameterObject to the vector
   * @param inParameter input CAPParameterObject to add
   */
  void AddParameter(const CAPParameterObject &inParameter);

  /**
   * @brief Resources gets the <resources> vector of the object
   * @return vector of CAPResourceObjects
   */
  std::vector<CAPResourceObject> Resources() const;

  /**
   * @brief AddResource adds a single CAPResourceObject to the vector of the object
   * @param inResource CAPResourceObject to add
   */
  void AddResource(const CAPResourceObject &inResource);

  /**
   * @brief ProcessXML Processes the input XML to create an info object
   * @param inXMLReader XML Stream to process
   * @return True if successful, False otherwise
   */
  bool ProcessXML(const boost::property_tree::ptree &inXMLReader);

protected:
  // None

private:

  /**
   * @brief mLanguage The code denoting the anguage of the nfo sub-element of the alert message.
   * Code Values: Natural language identifier per [RFC 3066]. If not present, an implicit default value
   * of "en-US" SHALL be assumed. A null value in this element SHALL be considered equivalent to “en-US.”
   */
  std::string mLanguage;

  /**
   * @brief mCategory The code denoting the category of the subject event of the alert message.
   * Multiple instances MAY occur within a single <info> block.
   */
  std::vector<CAPCategoryEnum> mCategory;

  /**
   * @brief mEvent The text denoting the type of the subject event of the alert message.
   */
  std::string mEvent;

  /**
   * @brief mResponseType The code denoting the type of action recommended or the target audience.
   * Multiple instances MAY occur within a single <info> block.
   */
  std::vector<CAPResponseTypeEnum> mResponseType;

  /**
   * @brief mUrgency The code denoting the urgency of the subject event of the alert message.
   * The “urgency”, “severity”, and “certainty” elements collectively distinguish less emphatic from more
   * emphatic messages.
   */
  CAPUrgencyEnum mUrgency;

  /**
   * @brief The code denoting the severity of the subject event of the alert message.
   */
  CAPSeverityEnum mSeverity;

  /**
   * @brief mCertainty The code denoting the certainty of the subject event of the alert message.
   * For backward compatibility with CAP 1.0, the deprecated value of “Very Likely” SHOULD be treated as
   * equivalent to “Likely.”
   */
  CAPCertaintyEnum mCertainty;

  /**
   * @brief mAudience The text describing the intended audience of the alert message.
   */
  std::string mAudience;

  /**
   * @brief mEventCode A system-specific code identifying the event type of the alert message.
   * Multiple instances MAY occur within a single <info> block.
   */
  std::vector<CAPEventCodeObject> mEventCode;

  /**
   * @brief mEffective The effective time of the information of the alert message.
   * The date and time is represented in [dateTime] format (e. g., “2002-05-24T16:49:00-07:00” for
   * 24 May 2002 at 16: 49 PDT). Alphabetic timezone designators such as “Z” MUST NOT be used. The
   * timezone for UTC MUST be represented as “-00:00” or “+00:00. If this item is not included, the
   * effective time SHALL be assumed to be the same as in <sent>.
   */
  std::string mEffective;

  /**
   * @brief mOnset The expected time of the beginning of the subject event of the alert message.
   * The date and time is represented in [dateTime] format (e. g., “2002-05-24T16:49:00-07:00” for
   * 24 May 2002 at 16: 49 PDT). Alphabetic timezone designators such as “Z” MUST NOT be used. The
   * timezone for UTC MUST be represented as “-00:00” or “+00:00.
   */
  std::string mOnset;

  /**
   * @brief mExpires The expiry time of the information of the alert message.
   * The date and time is represented in [dateTime] format (e. g., “2002-05-24T16:49:00-07:00” for
   * 24 May 2002 at 16:49 PDT). Alphabetic timezone designators such as “Z” MUST NOT be used. The
   * timezone for UTC MUST be represented as “-00:00” or “+00:00. If this item is not provided, each
   * recipient is free to set its own policy as to when the message is no longer in effect.
   */
  std::string mExpires;

  /**
   * @brief mSenderName The text naming the originator of the alert message.
   * The human-readable name of the agency or authority issuing this alert.
   */
  std::string mSenderName;

  /**
   * @brief mHeadline The text headline of the alert message.
   * A brief human-readable headline. Note that some displays (for example, short messaging service
   * devices) may only present this headline; it SHOULD be made as direct and actionable as possible
   * while remaining short. 160 characters MAY be a useful target limit for headline length.
   */
  std::string mHeadline;

  /**
   * @brief mDescription The text describing the subject event of the alert message.
   * An extended human readable description of he hazard or event that occasioned this message.
   */
  std::string mDescription;

  /**
   * @brief mInstruction The text describing the recommended action to be taken by recipients of the alert message.
   * An extended human readable instruction to targeted recipients. (If different instructions are intended
   * for different recipients, they should be represented by use of multiple <info> blocks.).
   *
   */
  std::string mInstruction;

  /**
   * @brief mWeb The identifier of the hyperlink associating additional information with the alert message.
   * A full, absolute URI for an HTML page or other text resource with additional or reference information regarding this alert.
   */
  std::string mWeb;

  /**
   * @brief mContact The text describing the contact for follow-up and confirmation of the alert message.
   */
  std::string mContact;

  /**
   * @brief mParameters A system-specific additional parameter associated with the alert message.
   * Multiple instances MAY occur within a single <info> block.
   */
  std::vector<CAPParameterObject> mParameters;

  /**
   * @brief mResources The container for all component parts of the resource sub-element of the info sub-element of the alert element.
   */
  std::vector<CAPResourceObject> mResources;

  /**
   * @brief mArea The container for all component parts of the area sub-element of the info sub-element of the alert message.
   * Multiple occurrences permitted, in which case the target area for the <info> block is the union of all the included <area>
   * blocks. MAY contain one or multiple instances of <polygon>, <circle> or <geocode>. If multiple <polygon>, <circle> or
   * <geocode> elements are included, the area described by this <area> is the union of those represented by the included elements.
   */
  std::vector<CAPAreaObject> mArea;
}; // class CAPInfoObject

} // namespace CAPLib
#endif // CAPINFOOBJECT_H
