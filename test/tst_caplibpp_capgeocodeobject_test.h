#ifndef TEST_CAPLIBPP_CAPGEOCODEOBJECT_TEST_H
#define TEST_CAPLIBPP_CAPGEOCODEOBJECT_TEST_H
#include "CAPLibpp/CAPInfoObject.h"
#include "CAPLibpp/NOAACAPAlertObject.h"
#include "CAPLibpp/CAPLibEnums.h"
#include "CAPLibpp/CAPAreaObject.h"
#include "CAPLibpp/CAPGeocodeObject.h"
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <vector>
#include <string>

using namespace testing;

TEST(CAPLibppTest, caplibpp_capgeocodeobject_test)
{
    CAPLib::NOAACAPAlertObject capAlertOBject;
    CAPLib::CAPInfoObject capInfoObject;
    CAPLib::CAPAreaObject capAreaObject;
    CAPLib::CAPGeocodeObject capGeocodeObject;
    std::string infile("../../test/cap_entry.xml");
    std::vector<CAPLib::CAPInfoObject> capInfos;
    boost::property_tree::ptree testTree;

    boost::property_tree::read_xml(infile, testTree);
    ASSERT_THAT(capAlertOBject.ProcessXML(testTree), Eq(1));
    capInfos = capAlertOBject.Infos();
    ASSERT_EQ(capInfos.size(), 1);
    capInfoObject = capInfos[0];
    ASSERT_EQ(capInfoObject.Areas().size(), 1);
    capAreaObject = capInfoObject.Areas()[0];
    ASSERT_EQ(capAreaObject.Geocodes().size(), 2);

    capGeocodeObject = capAreaObject.Geocodes()[0];
    ASSERT_EQ(capGeocodeObject.ValueName(), "FIPS6");
    ASSERT_EQ(capGeocodeObject.Value(), "005027");

    capGeocodeObject = capAreaObject.Geocodes()[1];
    ASSERT_EQ(capGeocodeObject.ValueName(), "UGC");
    ASSERT_EQ(capGeocodeObject.Value(), "ARC027");
}
#endif // TEST_CAPLIBPP_CAPGEOCODEOBJECT_TEST_H
