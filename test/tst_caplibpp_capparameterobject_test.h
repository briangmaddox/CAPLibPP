#ifndef TST_CAPLIBPP_CAPPARAMETEROBJECT_TEST_H
#define TST_CAPLIBPP_CAPPARAMETEROBJECT_TEST_H
#include "CAPLibpp/CAPInfoObject.h"
#include "CAPLibpp/NOAACAPAlertObject.h"
#include "CAPLibpp/CAPLibEnums.h"
#include "CAPLibpp/CAPParameterObject.h"
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <vector>
#include <string>

using namespace testing;

TEST(CAPLibppTest, caplibpp_capparameterobject_test)
{
    CAPLib::NOAACAPAlertObject capAlertOBject;
    CAPLib::CAPInfoObject capInfoObject;
    CAPLib::CAPParameterObject capParameterObject;
    std::string infile("../../test/cap_entry.xml");
    std::vector<CAPLib::CAPInfoObject> capInfos;
    boost::property_tree::ptree testTree;

    boost::property_tree::read_xml(infile, testTree);
    ASSERT_THAT(capAlertOBject.ProcessXML(testTree), Eq(1));
    capInfos = capAlertOBject.Infos();
    ASSERT_EQ(capInfos.size(), 1);
    capInfoObject = capInfos[0];
    ASSERT_EQ(capInfoObject.Parameters().size(), 4);

    capParameterObject = capInfoObject.Parameters()[0];
    ASSERT_EQ(capParameterObject.ValueName(), "WMOHEADER");
    ASSERT_EQ(capParameterObject.Value(), "");

    capParameterObject = capInfoObject.Parameters()[1];
    ASSERT_EQ(capParameterObject.ValueName(), "UGC");
    ASSERT_EQ(capParameterObject.Value(), "ARC027-LAC119");

    capParameterObject = capInfoObject.Parameters()[2];
    ASSERT_EQ(capParameterObject.ValueName(), "VTEC");
    ASSERT_EQ(capParameterObject.Value(), "/O.EXT.KSHV.FL.W.0145.000000T0000Z-201004T0000Z/"
                                          "\n\t\t\t\t/SPHL1.1.ER.200924T0845Z.200927T0000Z.201003T0600Z.NO/");

    capParameterObject = capInfoObject.Parameters()[3];
    ASSERT_EQ(capParameterObject.ValueName(), "TIME...MOT...LOC");
    ASSERT_EQ(capParameterObject.Value(), "");
}
#endif // TST_CAPLIBPP_CAPPARAMETEROBJECT_TEST_H
