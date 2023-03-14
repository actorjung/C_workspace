// 연습 6-1　버블 정렬(맨 앞에서부터 진행)
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- 버블 정렬 ---*/
void bubble(int a[], int n)
{
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++)
            if (a[j] > a[j + 1])
                swap(int, a[j], a[j + 1]);
    }
}

int main(void)
{
    int nx;

    puts("버블 정렬");
    printf("요소 개수: ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));   // 요소 개수가 nx인 int형 배열 x를 생성

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    bubble(x, nx);                      // 배열 x를 버블 정렬

    puts("오름차순으로 정렬했습니다.");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);                            // 배열 x를 해제

    return 0;
}
