// 연습1-7　1, 2, …, n의 합을 구하여 출력(for 문: 식을 표시)
#include <stdio.h>

int main(void)
{
    int n;

    puts("1부터 n까지의 합을 구하세요.");

    printf("n값: ");
    scanf("%d", &n);

    int sum = 0;        // 총합

    for (int  i = 1; i <= n; i++)   // i = 1, 2, …, n
        sum += i;                   // sum에 i를 추가

    for (int i = 1; i < n; i++)
        printf("%d + ", i);
    printf("%d = %d\n", n, sum);

    return 0;
}
