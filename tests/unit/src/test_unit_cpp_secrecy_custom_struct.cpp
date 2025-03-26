#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <stdint.h>

#include "cpp_secrecy.h"

struct testStruct {
    char name[30];
    int id;
};
 
void test_basic_custom_struct(void)
{
    struct testStruct *ptr;

    // need to figure out a better way to initialise the class
    struct testStruct rich = {"rich", 1};
    SecretValue<struct testStruct> secret(rich);
    memset(&rich, 0, sizeof(struct testStruct));

    // check the initial struct has been cleared
    CU_ASSERT_EQUAL_FATAL(strncmp(rich.name, "\0\0\0\0", 4), 0)
    CU_ASSERT_EQUAL_FATAL(rich.id, 0);

    // check that the exposed value is correct
    CU_ASSERT_EQUAL(strncmp(secret.expose_value()->name, "rich", 4), 0);
    CU_ASSERT_EQUAL(secret.expose_value()->id, 1);

    // get the pointer to the secret values
    ptr = secret.expose_value();

    // check the value at the pointer is correct
    CU_ASSERT_EQUAL(strncmp(ptr->name, "rich", 4), 0);

    // destroy the secret value
    secret.~SecretValue();

    // check the value at the old memory location is correct
    CU_ASSERT(*ptr->name == 0);    
}

void run_custom_struct_suite(void)
{
    
    CU_pSuite suite = CU_add_suite("C++ secrecy custom struct tests", 0, 0);
    CU_add_test(suite, "test of basic custom struct creation and destruction", test_basic_custom_struct);
    
    CU_basic_run_tests();
}