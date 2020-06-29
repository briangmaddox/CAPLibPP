#ifndef CAPRESOURCEOBJECT_H
#define CAPRESOURCEOBJECT_H

#include <string>
#include <boost/property_tree/ptree.hpp>

namespace CAPLib
{

/**
 * @class CAPResourceObject
 * @brief The CAPResourceObject class container.
 * The container for all component parts of the resource sub-element of the info sub-element of the
 * alert element. Refers to an additional file with supplemental information related to this <info>
 * element; e.g., an image or audio file. Multiple occurrences MAY occur within a single <info> block.
 */
class CAPResourceObject
{

public:
  /**
   * @brief CAPResourceObject default constructor
   */
  CAPResourceObject();

  /**
   * @brief SetResourceDesc Set the value of resourceDesc
   * @param inResourceDesc the new value of resourceDesc
   */
  void SetResourceDesc(const std::string &inResourceDesc);

  /**
   * @brief ResourceDesc Get the value of resourceDesc
   * @return the value of resourceDesc
   */
  std::string ResourceDesc() const;

  /**
   * @brief SetMimeType Set the value of mimeType
   * @param inMIMEType the new value of mimeType
   */
  void SetMimeType(const std::string &inMIMEType);

  /**
   * @brief MimeType Get the value of mimeType
   * @return the value of mimeType
   */
  std::string MimeType() const;

  /**
   * @brief SetSize Set the value of size
   * @param inSize the new value of size
   */
  void SetSize(int inSize);

  /**
   * @brief Size Get the value of size
   * @return the value of size
   */
  int Size() const;

  /**
   * @brief SetURI Set the value of uri
   * @param inURI the new value of URI
   */
  void SetURI(const std::string &inURI);

  /**
   * @brief URI Get the value of URI
   * @return the value of URI
   */
  std::string URI() const;

  /**
   * @brief SetDerefUri Set the value of derefUri
   * @param inDerefURI the new value of derefUri
   */
  void SetDerefURI(const std::string &inDerefURI);

  /**
   * @brief DerefUri Get the value of derefUri
   * @return the value of derefUri
   */
  std::string DerefURI() const;

  /**
   * Set the value of digest
   * The code representing the digital digest (“hash”) computed from the resource
   * file.  Calculated using the Secure Hash Algorithm (SHA-1) per [FIPS 180-2].
   * @param new_var the new value of digest
   */
  void SetDigest(const std::string &inDigest);

  /**
   * @brief Digest Get the value of digest
   * @return the value of digest
   */
  std::string Digest() const;

  /**
   * @brief ProcessXML Processes the input XML to create the object
   * @param inXMLReader const boost::property_tree::ptree
   * @return true if successful, false otherwise
   */
  bool ProcessXML(const boost::property_tree::ptree &inXMLReader);

protected:
// None

private:
  /**
   * @brief resourceDesc The text describing the type and content of the resource file.
   * The human-readable text describing the content and kind, such as “map” or “photo,” of the resource file.
   */
  std::string mResourceDesc;

  /**
   * @brief MIMEType The identifier of the MIME content type and sub-type describing the resource file.
   * MIME content type and sub-type as described in [RFC 2046]. (As of this document, the current IANA
   * registered MIME types are listed at http://www.iana.org/assignments/media-types/)
   */
  std::string mMIMEType;

  /**
   * @brief size The integer indicating the size of the resource file
   * Approximate size of the resource file in bytes.
   */
  int mSize;

  /**
   * @brief URI The identifier of the hyperlink for the resource file.
   * A full absolute URI, typically a Uniform Resource Locator that can be used to retrieve the resource
   * over the Internet OR a relative URI to name the content of a <derefUri> element if one is present in
   * this resource block.
   */
  std::string mURI;

  /**
   * @brief derefURI The base-64 encoded data content of the resource file.
   * MAY be used either with or instead of the <uri> element in messages transmitted over one-way (e.g.,
   * broadcast) data links where retrieval of a resource via a URI is not feasible. Clients intended for
   * use with one-way data links MUST support this element. This element MUST NOT be used unless the
   * sender is certain that all direct clients are capable of processing it.  If messages including this
   * element are forwarded onto a two-way network, the forwarder MUST strip the <derefUri> element and
   * SHOULD extract the file contents and provide a <uri> link to a retrievable version of the file.
   * Providers of one-way data links MAY enforce additional restrictions on the use of this element,
   * including message-size limits and restrictions regarding file types.
   */
  std::string mDerefURI;

  /**
   * @brief digest The code representing the digital digest (“hash”) computed from the resource file.
   * Calculated using the Secure Hash Algorithm (SHA-1) per [FIPS 180-2].
   */
  std::string mDigest;
};

} // namespace CAPLIB
#endif // CAPRESOURCEOBJECT_H
