#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <string>

#include "cpp_secrecy.h"

void test_basic_string(void)
{
    string comp = "test";
    SecretValue<string> value("test");

    string *ptr = value.expose_value();

    char buffer[4];

    CU_ASSERT("test" == *ptr);

    // I want to try and 
    // CU_ASSERT(0x74 == buffer[0]);
    // CU_ASSERT(0x65 == buffer[1]);
    // CU_ASSERT(0x73 == buffer[2]);
    // CU_ASSERT(0x74 == buffer[3]);

    value.~SecretValue();

    memcpy(buffer, ptr, 4);

    CU_ASSERT(0 == buffer[0]);
    CU_ASSERT(0 == buffer[1]);
    CU_ASSERT(0 == buffer[2]);
    CU_ASSERT(0 == buffer[3]);
    return;
}

void test_basic_string_copy(void)
{
    string comp = string("test");
    SecretValue<string> value(comp);
    comp.erase();

    string *ptr = value.expose_value();

    CU_ASSERT("test" == *ptr);

    value.~SecretValue();

    return;
}

void load_string_suite(void){

    CU_pSuite suite = CU_add_suite("C++ secrecy string tests", 0, 0);

    CU_add_test(suite, "test of basic string operation", test_basic_string);
    CU_add_test(suite, "test of basic string operation copy", test_basic_string_copy);
}

