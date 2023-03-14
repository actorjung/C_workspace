// 세 정수를 입력하고 최댓값을 구하여 출력

#include <stdio.h>

int main(void)
{
    int a, b, c;

    printf("세 정수의 최댓값을 구합니다.\n");
    printf("a값: ");   scanf("%d", &a);
    printf("b값: ");   scanf("%d", &b);
    printf("c값: ");   scanf("%d", &c);

    int max = a;
    if (b > max) max = b;
    if (c > max) max = c;

    printf("최댓값은 %d입니다.\n", max);

    return 0;
}
