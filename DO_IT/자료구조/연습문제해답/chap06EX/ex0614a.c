// 연습 6-14　퀵 정렬(요소 개수가 작은 그룹을 우선 분할: 재귀 버전)
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

/*--- 퀵 정렬(요소 개수가 작은 그룹을 우선 분할) ---*/
void quick(int a[], int left, int right)
{
    int pl = left;              // 왼쪽 커서
    int pr = right;             // 오른쪽 커서
    int x = a[(pl + pr) / 2];   // 피벗은 가운데 요소

    do {
        while (a[pl] < x) pl++;
        while (a[pr] > x) pr--;
        if (pl <= pr) {
            swap(int, a[pl], a[pr]);
            pl++;
            pr--;
        }
    } while (pl <= pr);

    if (pr - left < right - pl) {
        swap(int, pl, left);
        swap(int, pr, right);
    }
    if (left < pr)  quick(a, left, pr);
    if (pl < right) quick(a, pl, right);
}

int main(void)
{
    int nx;

    puts("퀵 정렬");
    printf("요소 개수: ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));   // 요소 개수가 nx인 int형 배열 x를 생성

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    quick(x, 0, nx - 1);                // 배열 x를 퀵 정렬

    puts("오름차순으로 정렬했습니다.");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);                            // 배열 x를 해제

    return 0;
}
