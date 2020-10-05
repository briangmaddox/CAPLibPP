#ifndef TST_CAPLIBPP_NOAACAPALERTOBJECT_TEST_H
#define TST_CAPLIBPP_NOAACAPALERTOBJECT_TEST_H
#include "CAPLibpp/NOAACAPAlertObject.h"
#include "CAPLibpp/CAPLibEnums.h"
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

using namespace testing;

TEST(CAPLibppTest, caplibpp_noaacapalertobject_test)
{
    CAPLib::NOAACAPAlertObject capAlertOBject;
    std::string infile("../../test/cap_entry.xml");
    boost::property_tree::ptree testTree;

    boost::property_tree::read_xml(infile, testTree);
    ASSERT_THAT(capAlertOBject.ProcessXML(testTree), Eq(1));
    ASSERT_EQ(capAlertOBject.Identifier(), "NOAA-NWS-ALERTS-AR125F6525A964.FloodWarning.125F69AAE300AR.SHVFLSSHV.aeea11ff746252d3e4dcf9d5ba71c6c5");
    ASSERT_EQ(capAlertOBject.Sender(), "w-nws.webmaster@noaa.gov");
    ASSERT_EQ(capAlertOBject.Sent(), "2020-09-28T11:01:00-05:00");
    ASSERT_EQ(capAlertOBject.Status(), CAPLib::CAPStatusEnum::ACTUAL);
    ASSERT_EQ(capAlertOBject.MsgType(), CAPLib::CAPMsgTypeEnum::ALERT);
    ASSERT_EQ(capAlertOBject.Source(), "");
    ASSERT_EQ(capAlertOBject.Scope(), CAPLib::CAPScopeEnum::PUBLIC);
    ASSERT_EQ(capAlertOBject.Restriction(), "");
    ASSERT_EQ(capAlertOBject.Addresses(), "");
    ASSERT_EQ(capAlertOBject.Codes().size(), 0);
    ASSERT_EQ(capAlertOBject.Note(), "Alert for Columbia (Arkansas) Issued by the National Weather Service");
    ASSERT_EQ(capAlertOBject.References(), "");
    ASSERT_EQ(capAlertOBject.Incidents(), "");
    ASSERT_EQ(capAlertOBject.Infos().size(), 1);
}
#endif // TST_CAPLIBPP_NOAACAPALERTOBJECT_TEST_H
