// 문자열 표시 및 읽기
#include <stdio.h>

int main(void)
{
    char st[128];
    printf("문자열: ");
    scanf("%s", st);    // st는 첫 번째 문자에 대한 포인터이므로 & 연산자가 불필요
    printf("%s", st);   // st는 첫 번째 문자에 대한 포인터이므로 & 연산자가 불필요

    return 0;
}
