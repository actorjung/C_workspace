// 연습 5-5 재귀에 대해 깊이 이해하기 위한 진정한 재귀적 함수(호출 횟수를 카운트)
#include <stdio.h>

int counter = 0;    // recur 함수의 호출 횟수

/*--- 재귀 함수 recur ---*/
void recur(int n)
{
    counter++;
    if (n > 0) {
        recur(n - 1);
        printf("%d\n", n);
        recur(n - 2);
    }
}

int main(void)
{
    int x;

    printf("정수를 입력하세요.: ");
    scanf("%d", &x);

    recur(x);

    printf("recur 함수는 %d회 호출되었습니다.\n", counter);

    return 0;
}
