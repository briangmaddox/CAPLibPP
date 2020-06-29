#ifndef NOAAATOMEVENTOBJECT_H
#define NOAAATOMEVENTOBJECT_H

#include <string>
#include <vector>
#include <boost/property_tree/ptree.hpp>
#include <CAPLibpp/NOAACAPAlertObject.h>

namespace CAPLib
{

/**
 * @brief The NOAAAtomEventObject class represents an entry from the NOAA ATOM feeds, both state and national level.
 * This is the main class to instantiate when using the library.
 */
class NOAAAtomEventObject
{
public:

  /**
   * @brief NOAAAtomEventObject default constructor
   */
  NOAAAtomEventObject() = default;

  /**
   * @brief Identifier returns the mIdentifier field.
   * @return std::string of the identifier
   */
  std::string Identifier() const;

  /**
   * @brief SetIdentifier Sets the mIdentifier field
   * @param inIdentifier std::string of the input identifier field
   */
  void SetIdentifier(const std::string &inIdentifier);

  /**
   * @brief Logo Returns the mLogo field
   * @return QUrl with the logo URL
   */
  std::string Logo() const;

  /**
   * @brief SetLogo Sets the mLogo field
   * @param inLogo QUrl of the input logo location
   */
  void SetLogo(const std::string &inLogo);

  /**
   * @brief Generator Returns the mGenerator field
   * @return std::string with the generator
   */
  std::string Generator() const;

  /**
   * @brief SetGenerator Sets the mGenerator field
   * @param inGenerator std::string with the generator information
   */
  void SetGenerator(const std::string &inGenerator);

  /**
   * @brief Updated returns the date the entry was updated
   * @return QDate object with the date and time
   */
  std::string Updated() const;

  /**
   * @brief SetUpdated sets the value of mUpdated (the date the entry was updated)
   * @param inUpdated QDate object with the date and time
   */
  void SetUpdated(const std::string &inUpdated);

  /**
   * @brief Published returns the mPublished field (the date the entry was published)
   * @return QDate object with the date and time
   */
  std::string Published() const;

  /**
   * @brief SetPublished sets the mPublished field (the date the entry was published)
   * @param inPublished QDate object with the date and time
   */
  void SetPublished(const std::string &inPublished);

  /**
   * @brief Author returns the mAuthor entry (individual or entity that issued the alert)
   * @return std::string with the author
   */
  std::string Author() const;

  /**
   * @brief SetAuthor sets the mAuthor field (individual or entity that issued the alert)
   * @param inAuthor std::string with the author
   */
  void SetAuthor(const std::string &inAuthor);

  /**
   * @brief Title gets the mTitle field (Title of the entry)
   * @return std::string with the title
   */
  std::string Title() const;

  /**
   * @brief SetTitle sets the mTitle field (Title of the entry)
   * @param inTitle std::string with the title
   */
  void SetTitle(const std::string &inTitle);

  /**
   * @brief Link returns the mLink field (full URI for the alert)
   * @return QUrl with the URI
   */
  std::string Link() const;

  /**
   * @brief SetLink sets the mLink field (full URI for the alert)
   * @param inLink QUrl object with the URI
   */
  void SetLink(const std::string &inLink);

  /**
   * @brief Summary returns the mSummary field (textual summary of the event)
   * @return std::string with the summary
   */
  std::string Summary() const;

  /**
   * @brief SetSummary sets the mSummary field (textual summary of the event)
   * @param inSummary std::string with the input summary
   */
  void SetSummary(const std::string &inSummary);

  /**
   * @brief CAPAlertObject gets the internal NOAACAPAlertObject
   * @return NOAACAPAlertObject std::vector of NOAACAPAlertObjects
   */
  std::vector<NOAACAPAlertObject> CAPAlertObjects() const;

  /**
   * @brief SetCAPAlertObject sets the internal NOAACAPAlertObject
   * @param inCAPObject NOAACAPAlertObject with the input
   */
  void AddCAPAlertObject(const NOAACAPAlertObject &inCAPObject);

  /**
   * @brief ProcessXML processes the XML that is downloaded from a NOAA ATOM feed
   * @param inXML input boost::property_tree::ptree downloaded
   * @return bool indicating success in parsing and creating the object.
   */
  bool ProcessXML(const boost::property_tree::ptree &inXML);

private:

  /**
   * @brief GetCAPURL Downloads the passed-in URL string using curlpp/libcurl.
   * @param inURL std::string with the URL to download
   * @return std::string containing the CAP XML
   */
  std::stringstream GetCAPURL(const std::string &inURL);

  /**
   * @brief mIdentifier A std::string uniquely identifying this message, assigned by the sender.
   * MUST NOT include spaces, commas or restricted characters (< and &).
   */
  std::string mIdentifier;

  /**
   * @brief mLogo A QUrl that points to where the official logo for the alert is
   */
  std::string mLogo;

  /**
   * @brief mGenerator std::string that contains the generator of the Atom Event
   */
  std::string mGenerator;

  /**
   * @brief mUpdated The date and time that the entry was updated.
   */
  std::string mUpdated;

  /**
   * @brief mPublished The date the entry was published.
   */
  std::string mPublished;

  /**
   * @brief mAuthor The individual or entity that issued the alert.
   */
  std::string mAuthor;

  /**
   * @brief mTitle The title of the entry.
   */
  std::string mTitle;

  /**
   * @brief link The full URI for the alert.
   */
  std::string mLink;

  /**
   * @brief mSummary Textual summary of the event.
   */
  std::string mSummary;

  /**
   * @brief mCAPObject Internal CAP object that holds various entries.
   */
  std::vector<NOAACAPAlertObject> mCAPObjects;
};

} // namespace

#endif // NOAAATOMEVENTOBJECT_H
