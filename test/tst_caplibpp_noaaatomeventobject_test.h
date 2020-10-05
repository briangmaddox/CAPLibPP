#ifndef TST_CAPLIBPP_NOAAATOMEVENTOBJECT_TEST_H
#define TST_CAPLIBPP_NOAAATOMEVENTOBJECT_TEST_H
#include "CAPLibpp/NOAAAtomEventObject.h"
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

using namespace testing;

TEST(CAPLibppTest, caplibpp_noaaatomeventobject_test)
{
    CAPLib::NOAAAtomEventObject atomEventObject;
    std::string infile("../../test/us_atom.xml");
    boost::property_tree::ptree testTree;

    boost::property_tree::read_xml(infile, testTree);
    ASSERT_THAT(atomEventObject.ProcessXML(testTree), Eq(1));
    ASSERT_EQ(atomEventObject.Identifier(), "https://alerts.weather.gov/cap/us.php?x=0");
    ASSERT_EQ(atomEventObject.Logo(), "http://alerts.weather.gov/images/xml_logo.gif");
    ASSERT_EQ(atomEventObject.Generator(), "NWS CAP Server");
    ASSERT_EQ(atomEventObject.Updated(), "2020-09-28T12:57:00-06:00");
    ASSERT_EQ(atomEventObject.Published(), "");
    ASSERT_EQ(atomEventObject.Author(), "w-nws.webmaster@noaa.gov");
    ASSERT_EQ(atomEventObject.Title(), "Current Watches, Warnings and Advisories for the United States Issued by the National Weather Service");
    ASSERT_EQ(atomEventObject.Link(), "https://alerts.weather.gov/cap/us.php?x=0");
    ASSERT_EQ(atomEventObject.CAPAlertObjects().size(), 77);
}

#endif // TST_CAPLIBPP_NOAAATOMEVENTOBJECT_TEST_H
