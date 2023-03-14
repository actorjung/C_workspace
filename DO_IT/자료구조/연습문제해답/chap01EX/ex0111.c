// 연습1-11　양의 정수의 자릿수를 구하여 출력
#include <stdio.h>

int main(void)
{
    int n;

    do {
        printf("양의 정수: ");
        scanf("%d", &n);
    } while (n <= 0);

    int digits = 0;     // 자릿수
    while (n > 0) {
        n /= 10;        // x를 10으로 나누기
        digits++;
    }

    printf("그 수는 %d자리입니다.\n", digits);

    return 0;
}
