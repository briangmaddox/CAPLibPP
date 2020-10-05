#ifndef TST_CAPLIBPP_CAPINFOOBJECT_TEST_H
#define TST_CAPLIBPP_CAPINFOOBJECT_TEST_H
#include "CAPLibpp/CAPInfoObject.h"
#include "CAPLibpp/NOAACAPAlertObject.h"
#include "CAPLibpp/CAPLibEnums.h"
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <vector>
#include <string>

using namespace testing;

TEST(CAPLibppTest, caplibpp_capinfoobject_test)
{
    CAPLib::NOAACAPAlertObject capAlertOBject;
    CAPLib::CAPInfoObject capInfoObject;
    std::string infile("../../test/cap_entry.xml");
    std::vector<CAPLib::CAPInfoObject> capInfos;
    boost::property_tree::ptree testTree;
    std::string descriptionString = "...The Flood Warning continues for the following bayou in\n\t\t\tLouisiana..."
                                    "Arkansas...\n\t\t\tBayou Dorcheat Near Springhill affecting Webster Parish and\n\t\t\tColumbia\n\t\t\tCounty";
    std::string instructionString = "Do not drive cars through flooded areas.\n\t\t\tCaution is urged when walking near riverbanks.\n\t\t\t"
                                    "Turn around, don`t drown when encountering flooded roads. Most flood\n\t\t\tdeaths occur in vehicles."
                                    "\n\t\t\tA Flood Warning means that flooding is imminent or occurring. All\n\t\t\tinterested parties "
                                    "should take necessary precautions immediately.\n\t\t\tFor more hydrologic information, copy and paste "
                                    "the following website\n\t\t\taddress into your favorite web browser URL bar:\n\t\t\twater.weather.gov/"
                                    "ahps2/index.php?wfo=shv\n\t\t\tARC027-LAC119-291715-\n\t\t\t/O.EXT.KSHV.FL.W.0145.000000T0000Z-201004T0000Z/"
                                    "\n\t\t\t/SPHL1.1.ER.200924T0845Z.200927T0000Z.201003T0600Z.NO/\n\t\t\t1101 AM CDT Mon Sep 28 2020\n\t\t\t"
                                    "...The Flood Warning is now in effect until Saturday evening...\n\t\t\tThe Flood Warning continues for"
                                    "\n\t\t\tthe Bayou Dorcheat Near Springhill.\n\t\t\t* Until Saturday evening.\n\t\t\t"
                                    "* At 10:00 AM CDT Monday the stage was 13.3 feet.\n\t\t\t* Flood stage is 11 feet.\n\t\t\t"
                                    "* Minor flooding is occurring and minor flooding is forecast.\n\t\t\t* Recent Activity..."
                                    "The maximum bayou stage in the 24 hours ending\n\t\t\tat 10:00 AM CDT Monday was 13.6 feet."
                                    "\n\t\t\t* Forecast...The bayou is expected to fall below flood stage early\n\t\t\tSaturday morning "
                                    "and continue falling to 10.8 feet by late\n\t\t\tSaturday morning.\n\t\t\t* Impact...At 13.0 feet, "
                                    "Minor lowland flooding of private boat\n\t\t\tramps. Move livestock to higher ground.";

    boost::property_tree::read_xml(infile, testTree);
    ASSERT_THAT(capAlertOBject.ProcessXML(testTree), Eq(1));
    capInfos = capAlertOBject.Infos();
    ASSERT_EQ(capInfos.size(), 1);
    capInfoObject = capInfos[0];

    ASSERT_EQ(capInfoObject.Areas().size(), 1);
    ASSERT_EQ(capInfoObject.Language(), "");
    ASSERT_EQ(capInfoObject.Categories().size(), 1);
    ASSERT_EQ(capInfoObject.Categories()[0], CAPLib::CAPCategoryEnum::MET);
    ASSERT_EQ(capInfoObject.Event(), "Flood Warning");
    ASSERT_EQ(capInfoObject.ResponseTypes().size(), 0);
    ASSERT_EQ(capInfoObject.Urgency(), CAPLib::CAPUrgencyEnum::EXPECTED);
    ASSERT_EQ(capInfoObject.Severity(), CAPLib::CAPSeverityEnum::MODERATE);
    ASSERT_EQ(capInfoObject.Certainty(), CAPLib::CAPCertaintyEnum::LIKELY);
    ASSERT_EQ(capInfoObject.Audience(), "");
    ASSERT_EQ(capInfoObject.EventCodes().size(), 1);
    ASSERT_EQ(capInfoObject.Effective(), "2020-09-28T11:01:00-05:00");
    ASSERT_EQ(capInfoObject.Onset(), "");
    ASSERT_EQ(capInfoObject.Expires(), "2020-10-03T19:00:00-05:00");
    ASSERT_EQ(capInfoObject.SenderName(), "NWS Shreveport (Shreveport)");
    ASSERT_EQ(capInfoObject.Headline(), "Flood Warning issued September 28 at 11:01AM CDT until October 03 at 7:00PM CDT by NWS Shreveport");
    ASSERT_EQ(capInfoObject.Description(), descriptionString);
    ASSERT_EQ(capInfoObject.Instruction(), instructionString);
    ASSERT_EQ(capInfoObject.Web(), "");
    ASSERT_EQ(capInfoObject.Contact(), "");
    ASSERT_EQ(capInfoObject.Parameters().size(), 4);
    ASSERT_EQ(capInfoObject.Resources().size(), 0);
}
#endif // TST_CAPLIBPP_CAPINFOOBJECT_TEST_H
