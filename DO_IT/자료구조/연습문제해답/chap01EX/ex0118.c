// 연습1-18　숫자 문자로 역방향 피라미드 출력
#include <stdio.h>

/*--- 숫자 문자로 역방향 피라미드 출력 ---*/
void nrpira(int n)
{
    for (int i = 1; i <= n; i++) {              // i행（i = 1, 2, … ,n）
        for (int j = 1; j <= i-1; j++)          // i-1개의 ' '를 출력
            putchar(' ');
        for (int j = 1; j <= (n - i)*2+1; j++)  // (n-i)*2+1개의 숫자를 출력
            printf("%d", i % 10);
        putchar('\n');
    }ㄷ
}

int main(void)
{
    int n;

    puts("피라미드를 출력합니다.");
    do {
        printf("단 수: ");
        scanf("%d", &n);
    } while (n <= 0);

    nrpira(n);

    return 0;
}
