#ifndef CAPAREAOBJECT_H
#define CAPAREAOBJECT_H

#include <string>
#include <boost/property_tree/ptree.hpp>
#include <vector>
#include "CAPGeocodeObject.h"

namespace CAPLib
{

/**
  * @class CAPAreaObject
  * @brief The container for the area sub-element of the info sub-element of the alert message.
  * Multiple occurrences permitted, in which case the target area for the <info> block is the union
  * of all the included <area> blocks.  MAY contain one or multiple instances of <polygon>, <circle>
  * or <geocode>. If multiple <polygon>, <circle>, or <geocode> elements are included, the area
  * described by this <area> is the union of those represented by the included elements.
  */
class CAPAreaObject
{
public:

  /**
   * @brief Returns the value of the altitude entry.
   * @return string representing the altitude
   */
  std::string Altitude() const;

  /**
   * @brief Sets the altitude of the object.
   * @param InAltitude Input value for the altitude field.
   */
  void SetAltitude(const std::string &inAltitude);

  /**
   * @brief Returns the areaDesc field.
   * @return string of the areadescription
   */
  std::string AreaDescription() const;

  /**
   * @brief Sets the value of the areaDesc field.
   * @param inAreaDescription Input value for the areaDesc field.
   */
  void SetAreaDescription(const std::string &inAreaDescription);

  /**
   * @brief Gets the ceiling value of the object.
   * @return string representing the ceiling
   */
  std::string Ceiling() const;

  /**
   * @brief Sets the ceiling value of the object.
   * @param inCeiling Input value for the ceiling field.
   */
  void SetCeiling(const std::string &inCeiling);

  /**
   * @brief Gets the geocode values of the object.
   * @return vector<CAPGeocodeObject> of the geocodes
   */
  std::vector<CAPGeocodeObject> Geocodes() const;

  /**
   * @brief Adds an individual geocode object to the internal geocode vector.
   * @param inGeocodeObject Input geocode to add.
   */
  void AddGeocode(const CAPGeocodeObject &inGeocodeObject);

  /**
   * @brief Gets the polygon vector from the object.
   * @return vector<string> of the polygons
   */
  std::vector<std::string> Polygons() const;

  /**
   * @brief Adds an individual polygon entry.
   * @param inPolygonObject Input polygon string to add.
   */
  void AddPolygon(const std::string &inPolygonObject);

  /**
   * @brief Circle Returns the mCircle vector of the entry
   * @return vector<std::string> of the circle
   */
  std::vector<std::string> Circles() const;

  /**
   * @brief AddCircleEntry Adds the entry to the mCircle vector
   * @param inCircleEntry std::string of the entry to add
   */
  void AddCircle(const std::string &inCircleEntry);

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
   * @brief areaDesc The text describing the affected area of the alert message.
   * A text description of the affected area.
   */
  std::string mAreaDesc;

  /**
   * @brief polygon The paired values of points defining a polygon that delineates the affected area of the alert message.
   * Code Values: The geographic polygon is represented by a whitespace-delimited list of [WGS 84] coordinate pairs.
   * (See WGS-84 Note at end of this section.)  The first and last pairs of coordinates MUST be the same. See Coordinate
   * Precision Note at end of this section. Multiple instances MAY occur within an <area>.
   */
  std::vector<std::string> mPolygon;

  /**
   * @brief mCircle Code Values: The circular area is represented by a central point given as a [WGS 84] coordinate pair
   * followed by a space character and a radius value in kilometers. (See WGS 84 Note at end of this section).  Multiple
   * instances MAY occur within an <area> block.
   */
  std::vector<std::string> mCircle;

  /**
   * @brief geocode The geographic code delineating the affected area of the alert message.
   * Multiple instances MAY occur within a single <info> block.
   */
  std::vector<CAPGeocodeObject> mGeocode;

  /**
   * @brief altitude The specific or minimum altitude of the affected area of the alert message.
   * If used with the <ceiling> element this value is the lower limit of a range. Otherwise, this value specifies a
   * specific altitude. The altitude measure is in feet above mean sea level per the [WGS- 84] datum.
   */
  std::string mAltitude;

  /**
   * @brief ceiling The maximum altitude of the affected area of the alert message.
   * MUST NOT be used except in combination with the <altitude> element. The ceiling measure is in feet above mean
   * sea level per the [WGS- 84] datum.
   */
  std::string mCeiling;
}; // class CAPAreaObject

} // namespace CAPLib
#endif // CAPAREAOBJECT_H
