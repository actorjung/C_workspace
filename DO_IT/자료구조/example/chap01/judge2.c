// 읽어온 정숫값 판정(2)

#include <stdio.h>

int main(void)
{
    int n;

    printf("정수: ");
    scanf("%d", &n);

    if (n == 1)
        puts("Ａ");
    else if (n == 2)
        puts("Ｂ");
    else if (n == 3)
        puts("Ｃ");

    return 0;
}
