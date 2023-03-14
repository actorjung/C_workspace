// 셸 정렬(버전 2: h = …, 13, 4, 1)
#include <stdio.h>
#include <stdlib.h>

/*--- 셸 정렬 함수(버전 2: h = …, 13, 4, 1) ---*/
void shell(int a[], int n)
{
    int h;
    for (h = 1; h < n; h = h * 3 + 1)
        ;
    for (; h > 0; h /= 3)
        for (int i = h; i < n; i++) {
            int tmp = a[i];
            int j;
            for (j = i - h; j >= 0 && a[j] > tmp; j -= h)
                a[j + h] = a[j];
            a[j + h] = tmp;
        }
}

int main(void)
{
    int nx;

    puts("셸 정렬");
    printf("요소 개수: ");
    scanf("%d", &nx);
    int* x = calloc(nx, sizeof(int));   // 요소의 개수가 nx인 int형 배열 x를 생성

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }
    shell(x, nx);               // 배열 x를 셸 정렬

    puts("오름차순으로 정렬했습니다.);
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);
    free(x);                    // 배열 x를 해제

    return 0;
}
