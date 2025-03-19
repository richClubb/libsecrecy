#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

#include <vector>

#include "cpp_secrecy.h"

void test_basic_vector(void)
{

    std::vector<int> *ptr;

    // Initialise the initial vector
    std::vector<int> initial;
    initial.push_back(1);
    initial.push_back(2);
    initial.push_back(3);
    
    // create the secret value which should copy the original vector
    SecretValue< std::vector<int> > value(&initial, initial.size());

    // zero out original vector
    initial[0] = 0;
    initial[1] = 0;
    initial[2] = 0;

    // check value of array is copied correctly
    std::vector<int> *retrieved = value.expose_value();

    //printf("test %d\n", *retrieved);

    return;
}

void run_vector_suite(void)
{
    CU_pSuite suite = CU_add_suite("C++ secrecy vector tests", 0, 0);
    
    //CU_add_test(suite, "test of basic vector creation and destruction", test_basic_vector);
    
    CU_basic_run_tests();
}