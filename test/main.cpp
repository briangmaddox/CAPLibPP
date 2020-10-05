#include "tst_caplibpp_unit_test.h"
#include "tst_caplibpp_noaaatomeventobject_test.h"
#include "tst_caplibpp_noaacapalertobject_test.h"
#include "tst_caplibpp_capinfoobject_test.h"
#include "tst_caplibpp_capareaobject_test.h"
#include "tst_caplibpp_capeventcodeobject_test.h"
#include "tst_caplibpp_capgeocodeobject_test.h"
#include "tst_caplibpp_capparameterobject_test.h"

#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
