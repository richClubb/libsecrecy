#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

#include "cpp_secrecy.h"

void test_basic_int_array(void)
{
    int initial[3] = {1, 2, 3};

    int *ptr;
    SecretValue<int> value(initial, 3);

    initial[0] = 0;
    initial[1] = 0;
    initial[2] = 0;

    int val = value.expose_value()[2];
    // check that the exposed value is correct
    CU_ASSERT(value.expose_value()[0] == 1);
    CU_ASSERT(value.expose_value()[1] == 2);
    CU_ASSERT(value.expose_value()[2] == 3);

    // get the pointer to the secret values
    ptr = value.expose_value();

    // check the value at the pointer is correct
    CU_ASSERT(*ptr == 1);

    // destroy the secret value
    value.~SecretValue();

    // check the value at the old memory location is correct
    CU_ASSERT(*ptr == 0); 
}

void test_basic_char_array(void)
{
    char initial[3] = {'a', 'b', 'c'};

    char *ptr;
    SecretValue<char> value(initial, 3);

    initial[0] = 0;
    initial[1] = 0;
    initial[2] = 0;

    // check that the exposed value is correct
    CU_ASSERT(value.expose_value()[0] == 'a');
    CU_ASSERT(value.expose_value()[1] == 'b');
    CU_ASSERT(value.expose_value()[2] == 'c');

    // get the pointer to the secret values
    ptr = value.expose_value();

    // check the value at the pointer is correct
    CU_ASSERT(*ptr == 'a');

    // destroy the secret value
    value.~SecretValue();

    // check the value at the old memory location is correct
    CU_ASSERT(*ptr == 0); 
}

// currently causes a segfault
void test_basic_char_array_2(void)
{
    char *initial = "abc";

    char *ptr;
    SecretValue<char> value(initial, 3);

    // check that the exposed value is correct
    CU_ASSERT(value.expose_value()[0] == 'a');
    CU_ASSERT(value.expose_value()[1] == 'b');
    CU_ASSERT(value.expose_value()[2] == 'c');

    // get the pointer to the secret values
    ptr = value.expose_value();

    // check the value at the pointer is correct
    CU_ASSERT(*ptr == 'a');

    // destroy the secret value
    value.~SecretValue();

    // check the value at the old memory location is correct
    CU_ASSERT(*ptr == 0); 
}

void run_array_suite(void){

    CU_pSuite suite = CU_add_suite("C++ secrecy array tests", 0, 0);

    CU_add_test(suite, "test of basic int arrays operation", test_basic_int_array);
    CU_add_test(suite, "test of basic char arrays operation", test_basic_char_array);
    CU_add_test(suite, "test of basic char arrays operation 2", test_basic_char_array_2);
    
    CU_basic_run_tests();
}