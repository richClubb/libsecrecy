#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

#include "cpp_secrecy.h"

void test_basic_string(void)
{

    

}

void run_string_suite(void){

    CU_pSuite suite = CU_add_suite("C++ secrecy string tests", 0, 0);

    CU_add_test(suite, "test of basic string operation", test_basic_string);
    
    CU_basic_run_tests();
}

