// 1, 2, …, n의 합을 구하여 출력(do 문에서 양수만 n값으로 입력)
#include <stdio.h>

int main(void)
{
    int n;

    puts("1부터 n까지의 총합을 구합니다.");

    do {
        printf("n값: ");
        scanf("%d", &n);
    } while (n <= 0);

    int sum = 0;        // 총합

    for (int i = 1; i <= n; i++)    // i = 1, 2, …, n
        sum += i;                   // sum에 i를 추가

    printf("1부터 %d까지의 총합은 %d입니다.\n", n, sum);

    return 0;
}
