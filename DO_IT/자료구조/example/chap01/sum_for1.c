// 1, 2, …, n의 값을 구하여 출력(for 문)
#include <stdio.h>

int main(void)
{
    int n;

    puts("1부터 n까지의 총합을 구합니다.");

    printf("n값: ");
    scanf("%d", &n);

    int sum = 0;        // 総和

    for (int i = 1; i <= n; i++)    // i = 1, 2, …, n
        sum += i;                   // sum에 i를 추가

    printf("1부터 %d까지의 총합은 %d입니다.\n", n, sum);

    return 0;
}
