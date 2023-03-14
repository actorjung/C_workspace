// 왼쪽 아래가 직각인 이등변 삼각형을 출력
#include <stdio.h>

int main(void)
{
    int n;
    do {
        printf("몇 단 삼각형입니까?: ");
        scanf("%d", &n);
    } while (n <= 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++)
            putchar('*');
        putchar('\n');
    }

    return 0;
}
