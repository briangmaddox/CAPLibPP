#ifndef TST_CAPLIBPP_CAPEVENCODEOBJECT_TEST_H
#define TST_CAPLIBPP_CAPEVENCODEOBJECT_TEST_H
#include "CAPLibpp/CAPInfoObject.h"
#include "CAPLibpp/NOAACAPAlertObject.h"
#include "CAPLibpp/CAPLibEnums.h"
#include "CAPLibpp/CAPAreaObject.h"
#include "CAPLibpp/CAPEventCodeObject.h"
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <vector>
#include <string>

using namespace testing;

TEST(CAPLibppTest, caplibpp_capeventcodeobject_test)
{
    CAPLib::NOAACAPAlertObject capAlertOBject;
    CAPLib::CAPInfoObject capInfoObject;
    CAPLib::CAPAreaObject capAreaObject;
    CAPLib::CAPEventCodeObject capEventCodeObject;
    std::string infile("../../test/cap_entry.xml");
    std::vector<CAPLib::CAPInfoObject> capInfos;
    boost::property_tree::ptree testTree;

    boost::property_tree::read_xml(infile, testTree);
    ASSERT_THAT(capAlertOBject.ProcessXML(testTree), Eq(1));
    capInfos = capAlertOBject.Infos();
    ASSERT_EQ(capInfos.size(), 1);
    capInfoObject = capInfos[0];
    ASSERT_EQ(capInfoObject.EventCodes().size(), 1);
    capEventCodeObject = capInfoObject.EventCodes()[0];

    ASSERT_EQ(capEventCodeObject.ValueName(), "SAME");
    ASSERT_EQ(capEventCodeObject.Value(), "FLW");
}
#endif // TST_CAPLIBPP_CAPEVENCODEOBJECT_TEST_H
