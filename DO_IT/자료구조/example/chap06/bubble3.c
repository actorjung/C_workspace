// 버블 정렬(버전 3: 스캔 범위를 제한) 
#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- 버블 정렬(버전 3: 스캔 범위를 제한) ---*/
void bubble(int a[], int n)
{
    int k = 0;                              // a[k]보다 앞쪽의 요소는 정렬을 마친 상태

    while (k < n - 1) {
        int last = n - 1;                   // 마지막으로 교환을 수행한 위치를 저장
        for (int j = n - 1; j > k; j--)
            if (a[j - 1] > a[j]) {
                swap(int, a[j - 1], a[j]);
                last = j;
            }
        k = last;
    }
}

int main(void)
{
    int nx;

    puts("버블 정렬");
    printf("요소 개수: ");
    scanf("%d", &nx);
    int* x = calloc(nx, sizeof(int));   // 요소 개수 nx의 int형 배열 x 생성

    for (i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    bubble(x, nx);                      // 배열 x를 버블 정렬

    puts("오름차순으로 정렬했습니다.");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);                            // 배열 해제

    return 0;
}
