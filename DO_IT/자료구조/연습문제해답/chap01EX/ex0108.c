// 연습1-8　1, 2, …, n의 합을 구하여 출력(가우스의 덧셈)
#include <stdio.h>

int main(void)
{
    int n;

    puts("1부터 n까지의 합을 구하세요.");

    printf("n값: ");
    scanf("%d", &n);

    int sum = (n + 1) * (n / 2) + (n % 2 == 1 ? (n + 1) / 2 : 0);

    printf("1부터 %d까지의 합은 %d입니다.\n", n, sum);

    return 0;
}
