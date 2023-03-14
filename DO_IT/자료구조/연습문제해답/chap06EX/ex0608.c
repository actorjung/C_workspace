// 연습 6-8　단순 삽입 정렬(삽입 과정을 자세히 출력)
#include <stdio.h>
#include <stdlib.h>

/*--- 단순 삽입 정렬(삽입 과정을 자세히 출력)---*/
void insertion(int a[], int n)
{
    for (int i = 1; i < n; i++) {
        int tmp = a[i];
        int j;

        for (int m = 0; m < n; m++)
            printf("%3d ", a[m]);
        putchar('\n');

        for (j = i; j > 0 && a[j - 1] > tmp; j--)
            a[j] = a[j - 1];
        a[j] = tmp;

        printf("%*s%s", 4 * j , "", (i != j) ? "^-" : "  ");
        for (int m = 0; m < 4*(i-j); m++)
            putchar('-');
        printf("+\n\n");
    }
    for (int m = 0; m < n; m++)
        printf("%3d ", a[m]);
    putchar('\n');
}

int main(void)
{
    int nx;

    puts("단순 삽입 정렬");
    printf("요소 개수: ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));   // 요소 개수가 nx인 int형 배열 x를 생성

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    insertion(x, nx);                   // 배열 x를 단순 삽입 정렬

    puts("오름차순으로 정렬했습니다.");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);                            // 배열 x를 해제

    return 0;
}
