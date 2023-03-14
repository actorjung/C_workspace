// 순차곱셈의 결과를 재귀적으로 구하여 출력
#include <stdio.h>

/*--- 정수 n의 순차곱셈값을 반환 ---*/
int factorial(int n)
{
    if (n > 0)
        return n * factorial(n - 1);
    else
        return 1;
}
int main(void)
{
    int x;
    printf("정수를 입력하세요: ");
    scanf("%d", &x);
    printf("%d의 순차곱셈값은 %d입니다.\n", x, factorial(x));

    return 0;
}
