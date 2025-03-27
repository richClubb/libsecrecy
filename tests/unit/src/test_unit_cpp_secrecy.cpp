#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

#include "test_unit_cpp_secrecy.h"

int main(int argc, char **argv)
{
    CU_initialize_registry();

    load_int_suite();
    load_float_suite();
    load_vector_suite(); // has problems
    load_string_suite();
    load_array_suite();
    load_custom_struct_suite();
    
    if (argc == 1)
    {
        CU_basic_run_tests();
    }
    else if (argc == 2)
    {
        printf("not run, trying to sort out automated tests\n");
    }

    CU_cleanup_registry();

    return 0;
}