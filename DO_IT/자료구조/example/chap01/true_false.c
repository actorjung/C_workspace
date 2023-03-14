// 0이 거짓이고 0이외가 참임을 확인

#include <stdio.h>

int main(void)
{
    int a;

    printf("a값: ");
    scanf("%d", &a);

    if (a) printf("ABC");

    return 0;
}
