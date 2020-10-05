#ifndef TST_CAPLIBPP_CAPAREAOBJECT_TEST_H
#define TST_CAPLIBPP_CAPAREAOBJECT_TEST_H
#include "CAPLibpp/CAPInfoObject.h"
#include "CAPLibpp/NOAACAPAlertObject.h"
#include "CAPLibpp/CAPLibEnums.h"
#include "CAPLibpp/CAPAreaObject.h"
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <vector>
#include <string>

using namespace testing;

TEST(CAPLibppTest, caplibpp_capareaobject_test)
{
    CAPLib::NOAACAPAlertObject capAlertOBject;
    CAPLib::CAPInfoObject capInfoObject;
    CAPLib::CAPAreaObject capAreaObject;
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

    ASSERT_EQ(capAreaObject.Altitude(), "");
    ASSERT_EQ(capAreaObject.AreaDescription(), "Columbia");
    ASSERT_EQ(capAreaObject.Ceiling(), "");
    ASSERT_EQ(capAreaObject.Geocodes().size(), 2);
    ASSERT_EQ(capAreaObject.Polygons().size(), 1);
    ASSERT_EQ(capAreaObject.Polygons()[0], "33.1,-93.37 33,-93.35 32.82,-93.32 32.82,-93.38 33,-93.43 33.1,-93.37");
    ASSERT_EQ(capAreaObject.Circles().size(), 0);

}
#endif // TST_CAPLIBPP_CAPAREAOBJECT_TEST_H
