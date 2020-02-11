#include <unity.h>
#include "add.h"

#define UNITY_OUTPUT_FOR_ECLIPSE

void setUp(void){}

void tearDown(void){}


void test_IF_add_is_called_WHEN_two_positive_numbers_provided_THEN_positive_result_returned(){
    
    int value1 = 5;
    int value2 = 7;
    TEST_ASSERT_EQUAL_INT(10, add(&value1, &value1));
    TEST_ASSERT_EQUAL_INT(12, add(&value1, &value2));
    
}

void this_test_will_fail_when_called(){

    int value_1 = 5;
    char* value_2 = "2";
    TEST_ASSERT_EQUAL_INT(12, add(&value_1, &value_2));
}

void this_test_is_ignored(){

    TEST_IGNORE_MESSAGE("IGNORED: For testing Purposes");
}

int main(void){

    UNITY_BEGIN();
    RUN_TEST(test_IF_add_is_called_WHEN_two_positive_numbers_provided_THEN_positive_result_returned);
    RUN_TEST(this_test_will_fail_when_called);
    RUN_TEST(this_test_is_ignored);
    return UNITY_END();


}

