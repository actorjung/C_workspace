// 배열의 분할 과정을 출력하는 퀵 정렬 프로그램
#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

/*--- 배열의 분할 과정을 출력하는 퀵 정렬 프로그램 ---*/
void quick(int a[], int left, int right)
{
    int pl = left;              // 왼쪽 커서
    int pr = right;             // 오른쪽 커서
    int x = a[(pl + pr) / 2];   // 피벗(가운데 요소)

    printf("a[%d]～a[%d]：{", left, right);
    for (int i = left; i < right; i++)
        printf("%d , ", a[i]);
    printf("%d}\n", a[right]);

    do {
        while (a[pl] < x) pl++;
        while (a[pr] > x) pr--;
        if (pl <= pr) {
            swap(int, a[pl], a[pr]);
            pl++;
            pr--;
        }
    } while (pl <= pr);

    if (left < pr)  quick(a, left, pr);
    if (pl < right) quick(a, pl, right);
}

int main(void)
{
    int nx;
    puts("퀵 정렬");
    printf("요소 개수: ");
    scanf("%d", &nx);
    int* x = calloc(nx, sizeof(int));   // 요소의 개수가 nx인 int형 배열 x를 생성
    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }
    quick(x, 0, nx - 1);                // 배열 x에 대해서 퀵 정렬
    puts("오름차순으로 정렬했습니다.");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);
    free(x);                            // 배열 x를 해제

    return 0;
}
