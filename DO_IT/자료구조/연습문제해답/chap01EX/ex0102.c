// 연습1-2　세 정수의 최솟값 출력
#include <stdio.h>

/*--- a, b, c의 최솟값 반환 ---*/
int min3(int a, int b, int c)
{
    int min = a;    // 최솟값

    if (b < min) min = b;
    if (c < min) min = c;

    return min;
}

int main(void)
{
    int a, b, c;

    printf("세 정수의 최솟값을 구하세요.\n");
    printf("a값: ");   scanf("%d", &a);
    printf("b값: ");   scanf("%d", &b);
    printf("c값: ");   scanf("%d", &c);

    printf("최솟값은 %d입니다.\n", min3(a, b, c));

    return 0;
}
