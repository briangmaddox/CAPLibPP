#ifndef CAPLIBENUMS_H
#define CAPLIBENUMS_H

#include <string>
// Defines all of the enumerations needed by the CAPLib

namespace CAPLib
{

/**
 * @brief The CAPCategoryEnum enum encapsulates the valid values for the <category> field.
 */
enum class CAPCategoryEnum
{
  GEO,       ///< Geophysical (inc. landslide).
  MET,       ///< Meteorological (inc. flood).
  SAFETY,    ///< General emergency and public safety.
  SECURITY,  ///< Law enforcement, military, homeland and local/private security.
  RESCUE,    ///< Rescue and recovery.
  FIRE,      ///< Fire suppression and rescue.
  HEALTH,    ///< Medical and public health.
  ENV,       ///< Pollution and other environmental.
  TRANSPORT, ///< Public and private transportation.
  INFRA,     ///< Utility, telecommunication, other non-transport infrastructure.
  CBRNE,     ///< Chemical, Biological, Radiological, Nuclear or High-Yield Explosive threat or attack.
  OTHER,     ///< Other events.
  INVALID    ///< Indicates an invalid value was passed in the <category> field.
};

/**
 * @brief The CAPCertaintyEnum enum holds the valid values for the <certainty> element.
 */
enum class CAPCertaintyEnum
{
  OBSERVED, ///< Determined to have occurred or to be ongoing.
  LIKELY,   ///< Likely (p > ~50%).
  POSSIBLE, ///< Possible but not likely (p <= ~50%).
  UNLIKELY, ///< Not expected to occur (p ~ 0).
  UNKNOWN,  ///< Certainty unknown.
  INVALID   ///< Indicates an invalid value was passed in the <certainty> field.
};

/**
 * @brief The CAPMsgTypeEnum enum holding the valid values for a CAP <msgType> field.
 */
enum class CAPMsgTypeEnum
{
  ALERT,  ///< Initial information requiring attention by targeted recipients.
  UPDATE, ///< Updates and supercedes the earlier message(s) identified in <references>.
  CANCEL, ///< Cancels the earlier message(s) identified in <references>.
  ACK,    ///< Acknowledges receipt and acceptance of the message(s) identified in <references>.
  ERROR,  ///< Indicates rejection of the message(s) identified in <references>; explanation SHOULD appear in <note>.
  INVALID ///< Indicates an invalid value was passed in the <msgtype> field.
};

/**
 * @brief The CAPResponseTypeEnum enum holds the valid values possible for the <responseType> field.
 */
enum class CAPResponseTypeEnum
{
  SHELTER,  ///< Take shelter in place or per <instruction>.
  EVACUATE, ///< Relocate as instructed in the <instruction>.
  PREPARE,  ///< Make preparations per the <instruction>.
  EXECUTE,  ///< Execute a pre-planned activity identified in <instruction>.
  MONITOR,  ///< Attend to information sources as described in <instruction>.
  ASSESS,   ///< Evaluate the information in this message. (This value SHOULD NOT be used in public warning applications.).
  NONE,     ///< No action recommended.
  INVALID   ///< Indicates an invalid value was passed in the <responseType> field.
};

/**
 * @brief The CAPScopeEnum enum contains the valid values for the <scope> field in the CAP.
 */
enum class CAPScopeEnum
{
  PUBLIC,     ///< For general dissemination to unrestricted audiences.
  RESTRICTED, ///< For dissemination only to users with a known operational requirement (see <restriction>, below).
  PRIVATE,    ///< For dissemination only to specified addresses (see , below).
  INVALID     ///< Indicates an invalid value was passed in the <scope> field.
};

/**
 * @brief The CAPSeverityEnum enum contains the valid values for the <severity> field.
 */
enum class CAPSeverityEnum
{
  EXTREME,  ///< Extraordinary threat to life or property.
  SEVERE,   ///< Significant threat to life or property.
  MODERATE, ///< Possible threat to life or property.
  MINOR,    ///< Minimal threat to life or property.
  UNKNOWN,  ///< Severity unknown.
  INVALID   ///< Indicates an invalid value was passed in the <severity> field.
};

/**
 * @brief The CAPStatusEnum enum contains all the valid values for the <status> field in a CAP.
 */
enum class CAPStatusEnum
{
  ACTUAL,   ///< Actionable by all targeted recipients.
  EXERCISE, ///< Actionable only by designated exercise participants; exercise identifier should appear in <note>.
  SYSTEM,   ///< For messages that support alert network internal functions.
  TEST,     ///< Technical testing only, all recipients disregard.
  DRAFT,    ///< A preliminary template or draft, not actionable in its current form.
  INVALID   ///< Indicates an invalid value was passed in the <status> field.
};

/**
 * @brief The CAPUrgencyEnum enum represents the valid values for the <urgency> field.
 */
enum class CAPUrgencyEnum
{
  IMMEDIATE, ///< Responsive action SHOULD be taken immediately.
  EXPECTED,  ///< Responsive action SHOULD be taken soon (within next hour).
  FUTURE,    ///< Responsive action SHOULD be taken in the near future.
  PAST,      ///< Responsive action is no longer required.
  UNKNOWN,   ///< Urgency not known.
  INVALID    ///< Indicates an invalid value was passed in the <status> field.
};

// Functions to convert enums to strings
std::string CAPEnumToString(const CAPCategoryEnum &inCategoryEnum);
std::string CAPEnumToString(const CAPCertaintyEnum &inCertaintyEnum);
std::string CAPEnumToString(const CAPMsgTypeEnum &inMsgTypeEnum);
std::string CAPEnumToString(const CAPResponseTypeEnum &inResponseTypeEnum);
std::string CAPEnumToString(const CAPScopeEnum &inScopeEnum);
std::string CAPEnumToString(const CAPSeverityEnum &inSeverityEnum);
std::string CAPEnumToString(const CAPStatusEnum &inStatusEnum);
std::string CAPEnumToString(const CAPUrgencyEnum &inUrgencyEnum);


} // namespace CAPLib

#endif // CAPLIBENUMS_H

