/*
 * File:   newcunittest3.c
 * Author: Samuel
 *
 * Created on 4 sep. 2021, 23:39:37
 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
/*
 * CUnit Test Suite
 */

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

void testContarAlumnos() {
    char* nombreArchivo;
    int result = contarAlumnos(nombreArchivo);
    CU_ASSERT_EQUAL(result,59);
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("newcunittest3", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testContarAlumnos", testContarAlumnos))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
