// 연습1-9　정수 a, b를 포함하여 그 사이의 모든 정수의 총합을 구하여 출력
#include <stdio.h>

/*--- 정수 a, b를 포함하여 그 사이의 모든 정수의 총합을 구하여 출력 ---*/
int sumof(int a, int b)
{
    int min, max;

    if (a < b) {
        min = a;  max = b;
    } else {
        min = b;  max = a;
    }

    int sum = 0;
    for (int i = min; i <= max; i++)
        sum += i;

    return sum;
}

int main(void)
{
    int a, b;

    printf("a값: ");   scanf("%d", &a);
    printf("b값: ");   scanf("%d", &b);

    printf("정수 a,b 사이의 모든 정수의 합은 %d입니다.\n", sumof(a, b));

    return 0;
}
