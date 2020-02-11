#include <unity.h>
#include "subtract.h"


void setUp(void){}

void tearDown(void){}


void test_IF_sub_is_called_WHEN_two_positive_numbers_provided_THEN_positive_result_returned(){
    
    int value1 = 5;
    int value2 = 7;
    TEST_ASSERT_EQUAL_INT(subtract(&value1, &value1), 0);
    TEST_ASSERT_EQUAL_INT(subtract(&value2, &value1), 2);
    
}

void test_IF_sub_is_called_WHEN_second_number_larger_THEN_negative_result_returned(){

    int value1 = 5;
    int value2 = 7;

    TEST_ASSERT_EQUAL_INT(subtract(&value1, &value2), -2);
}

int main(void){

    UNITY_BEGIN();
    RUN_TEST(test_IF_sub_is_called_WHEN_two_positive_numbers_provided_THEN_positive_result_returned);
    RUN_TEST(test_IF_sub_is_called_WHEN_second_number_larger_THEN_negative_result_returned);
    return UNITY_END();


}

