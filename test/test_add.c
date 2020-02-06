#include <unity.h>
#include "add.h"


void setUp(void){}

void tearDown(void){}


void test_IF_add_is_called_WHEN_two_positive_numbers_provided_THEN_positive_result_returned(){
    
    int value1 = 5;
    int value2 = 7;
    TEST_ASSERT_EQUAL_INT(add(&value1, &value1), 10);
    TEST_ASSERT_EQUAL_INT(add(&value1, &value2), 12);
    
}

int main(void){

    UNITY_BEGIN();
    RUN_TEST(test_IF_add_is_called_WHEN_two_positive_numbers_provided_THEN_positive_result_returned);
    return UNITY_END();


}

