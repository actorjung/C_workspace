// 연습1-3　네 정수의 최솟값 출력
#include <stdio.h>

/*--- a, b, c, d의 최솟값 반환 ---*/
int min4(int a, int b, int c, int d)
{
    int min = a;    // 최솟값

    if (b < min) min = b;
    if (c < min) min = c;
    if (d < min) min = d;

    return min;
}

int main(void)
{
    int a, b, c, d;

    printf("네 정수의 최솟값을 구하세요.\n");
    printf("a값:");   scanf("%d", &a);
    printf("b값:");   scanf("%d", &b);
    printf("c값:");   scanf("%d", &c);
    printf("d값:");   scanf("%d", &d);

    printf("최솟값은 %d입니다.\n", min4(a, b, c, d));

    return 0;
}
