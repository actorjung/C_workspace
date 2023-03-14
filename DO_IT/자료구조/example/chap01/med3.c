// 세 정수를 입력하고 중앙값을 구하여 출력

#include <stdio.h>

/*--- a, b, c의 중앙값 ---*/
int med3(int a, int b, int c)
{
    if (a >= b)
        if (b >= c)
            return b;
        else if (a <= c)
            return a;
        else
            return c;
    else if (a > c)
        return a;
    else if (b > c)
        return c;
    else
        return b;
}

int main(void)
{
    int a, b, c;

    printf("세 정수의 중앙값을 구합니다.\n");
    printf("a값: ");   scanf("%d", &a);
    printf("b값: ");   scanf("%d", &b);
    printf("c값: ");   scanf("%d", &c);

    printf("중앙값은%d입니다.\n", med3(a, b, c));

    return 0;
}
