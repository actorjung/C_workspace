// 입력받은 정숫값의 부호(양수/음수/0)를 판단

#include <stdio.h>

int main(void)
{
    int n;

    printf("정수: ");
    scanf("%d", &n);

    if (n > 0)
        printf("양수입니다.\n");
    else if (n < 0)
        printf("음수입니다.\n");
    else
        printf("0입니다.\n");

    return 0;
}
