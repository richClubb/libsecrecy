#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <stdint.h>

#include "cpp_secrecy.h"

void test_basic_float(void)
{
    float *ptr;
    SecretValue<float> value(1.0);

    // check that the exposed value is correct
    CU_ASSERT(*value.expose_value() == 1.0);

    // get the pointer to the secret values
    ptr = value.expose_value();

    // check the value at the pointer is correct
    CU_ASSERT(*ptr == 1.0);

    // destroy the secret value
    value.~SecretValue();

    // check the value at the old memory location is correct
    CU_ASSERT(*ptr == 0);    
}

void run_float_suite(void)
{
    CU_pSuite suite = CU_add_suite("C secrecy float tests", 0, 0);
    
    CU_add_test(suite, "test of basic float creation and destruction", test_basic_float);
    
    CU_basic_run_tests();
}