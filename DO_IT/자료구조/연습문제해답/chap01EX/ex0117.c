// 연습1-17　기호 문자(*)를 이용해 피라미드를 출력
#include <stdio.h>

/*--- 기호 문자(*)를 이용해 피라미드를 출력 ---*/
void spira(int n)
{
    for (int i = 1; i <= n; i++) {              // i행（i = 1, 2, … ,n）
        for (int j = 1; j <= n-i; j++)          // n-i개의 ' '를 출력
            putchar(' ');
        for (int j = 1; j <= (i-1)*2+1; j++)    // (i-1)*2+1개의 '*'를 출력
            putchar('*');
        putchar('\n');
    }
}

int main(void)
{
    int n;

    puts("피라미드를 출력합니다.");
    do {
        printf("단 수: ");
        scanf("%d", &n);
    } while (n <= 0);

    spira(n);

    return 0;
}
