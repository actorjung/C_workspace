// 1~n의 합을 구하여 출력(while문)
#include <stdio.h>

int main(void)
{
    int n;

    puts("1부터 n까지의 총합을 구합니다.");

    printf("n값: ");
    scanf("%d", &n);

    int sum = 0;        // 총합
    int i = 1;

    while (i <= n) {    // i가 n 이하이면 반복
        sum += i;       // sum에 i를 추가
        i++;            // i값을 1 증가
    }
    printf("1부터 %d까지의 총합은 %d입니다.\n", n, sum);

    return 0;
}
