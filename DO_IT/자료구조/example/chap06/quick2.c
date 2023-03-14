// 퀵 정렬(업데이트 버전)
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

/*--- x[a], x[b], x[c]를 정렬(중앙값의 인덱스를 반환) ---*/
int sort3elem(int x[], int a, int b, int c)
{
    if (x[b] < x[a]) swap(int, x[b], x[a]);
    if (x[c] < x[b]) swap(int, x[c], x[b]);
    if (x[b] < x[a]) swap(int, x[b], x[a]);
    return b;
}

/*--- 퀵 정렬 ---*/
void quick(int a[], int left, int right)
{
    int pl = left;                                // 왼쪽 커서
    int pr = right;                               // 오른쪽 커서
    int m = sort3elem(a, pl, (pl + pr) / 2, pr);  // 처음, 끝, 가운데 요소 정렬
    int x = a[m];                                 // 피벗

    swap(int, a[m], a[right - 1]);          // 가운데와 끝에서 2번째 요소를 교환
    pl++;                                   // 왼쪽 커서를 1 요소만큼 오른쪽으로 이동
    pr -= 2;                                // 오른쪽 커서를 2 요소만큼 왼쪽으로 이동

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

    quick(x, 0, nx - 1);    // 배열 x를 퀵 정렬

    puts("오름차순으로 정렬했습니다.");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);                // 배열 x를 해제

    return 0;
}
