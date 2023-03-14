// 연습1-16　직각 이등변 삼각형을 출력
#include <stdio.h>

/*--- 왼쪽 아래가 직각인 직각 이등변 삼각형을 표시 ---*/
void triangleLB(int n)
{
    for (int i = 1; i <= n; i++) {              // i행（i = 1, 2, … ,n）
        for (int j = 1; j <= i; j++)            // i개의 '*'를 출력
            putchar('*');
        putchar('\n');
    }
}

/*--- 왼쪽 위가 직각인 직각 이등변 삼각형을 표시 ---*/
void triangleLU(int n)
{
    for (int i = 1; i <= n; i++) {              // i행（i = 1, 2, … ,n）
        for (int j = 1; j <= n-i+1; j++)        // n-i+1개의 '*'를 출력
            putchar('*');
        putchar('\n');
    }
}

/*--- 오른쪽 위가 직각인 직각 이등변 삼각형을 표시 ---*/
void triangleRU(int n)
{
    for (int i = 1; i <= n; i++) {              // i행（i = 1, 2, … ,n）
        for (int j = 1; j <= i - 1; j++)        // i-1개의 ' '를 출력
            putchar(' ');
        for (int j = 1; j <= n - i + 1; j++)    // n-i+1개의 '*'를 출력
            putchar('*');
        putchar('\n');                          // 줄바꿈
    }
}

/*--- 오른쪽 아래가 직각인 직각 이등변 삼각형을 표시 ---*/
void triangleRB(int n)
{
    for (int i = 1; i <= n; i++) {              // i행（i = 1, 2, … ,n）
        for (int j = 1; j <= n - i; j++)        // n-i개의 ' '를 출력
            putchar(' ');
        for (int j = 1; j <= i; j++)            // i개의 *'를 출력
            putchar('*');
        putchar('\n');                          // 줄바꿈
    }
}

int main(void)
{
    int n;

    puts("직각 이등변 삼각형을 출력합니다.");
    do {
        printf("크기: ");
        scanf("%d", &n);
    } while (n <= 0);

    printf("\n왼쪽 아래가 직각\n");   triangleLB(n);
    printf("\n왼쪽 위가 직각\n");   triangleLU(n);
    printf("\n오른쪽 위가 직각\n");   triangleRU(n);
    printf("\n오른쪽 아래가 직각\n");   triangleRB(n);

    return 0;
}
