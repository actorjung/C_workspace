// 두 변수 a,b에 정수를 입력하고 b-a를 출력하는 프로그램을 작성하시오 단, 변수 b에 입력한 값이 a이하면 변수 b값을 다시 입력하세요.
#include<stdio.h>
int main(){
    int num1, num2 = 0;

    printf("a값: ");
    scanf("%d", &num1);
    do {
    printf("b값: ");
    scanf("%d", &num2);
    puts("a보다 큰 값을 입력하세요!");
    } while(num2 <= num1);

    printf("%d - %d는 %d 입니다.\n", num2, num1, num2-num1);

    return 0;
}