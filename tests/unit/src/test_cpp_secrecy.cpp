#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

#include "test_cpp_secrecy.h"

int main(void)
{
    CU_initialize_registry();

    run_int_suite();
    run_array_suite();
    run_float_suite();
    run_string_suite();
    
    CU_cleanup_registry();

    return 0;
}