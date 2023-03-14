// 재귀에 대한 이해를 높이기 위한 진정한 재귀적 함수(말미 재귀 제거)
#include <stdio.h>

/*--- 말미 재귀를 제거한 recur 함수 ---*/
void recur(int n)
{
Top:
    if (n > 0) {
        recur(n - 1);
        printf("%d\n", n);
        n = n - 2;
        goto Top;
    }
}

int main(void)
{
    int x;

    printf("정수를 입력하세요: ");
    scanf("%d", &x);

    recur(x);

    return 0;
}
