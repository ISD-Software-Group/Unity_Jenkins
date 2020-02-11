#include <stdio.h>
#include "add.h"
#include "subtract.h"

int main(){

    int add_answer, sub_answer;
    int value1 = 1;
    int value2 = 10;
    add_answer = add(&value1, &value2);
    sub_answer = subtract(&value2, &value1);
    printf("Addition Answer is %d\n", add_answer);
    printf("Subtraction Answer is %d\n", sub_answer);
    return 0;
}