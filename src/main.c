#include <stdio.h>
#include "add.h"

int main(){

    int answer;
    int value1 = 1;
    int value2 = 3;
    answer = add(&value1, &value2);
    printf("Answer is %d\n", answer);
    return 0;
}