#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

#include "test_cpp_secrecy.h"

int main(void)
{
    CU_initialize_registry();

    run_int_suite();
    run_float_suite(); 
    run_vector_suite(); // has problems
    run_string_suite(); // just boilerplate
    run_array_suite(); // just boilerplate
    
    CU_cleanup_registry();

    return 0;
}