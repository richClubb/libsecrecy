#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

#include <vector>

#include "cpp_secrecy.h"

void test_basic_array(void)
{
    std::vector<int> initial;
    initial.push_back(1);
    //SecretValue<std::vector<int> > value(initial);
}

void run_array_suite(void)
{
    CU_pSuite suite = CU_add_suite("C secrecy array tests", 0, 0);
    CU_add_test(suite, "test of basic array creation and destruction", test_basic_array);
    CU_basic_run_tests();
}