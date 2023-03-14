// 연습3-1　선형 검색(보초법: for 문)
#include <stdio.h>
#include <stdlib.h>

/*--- 요소의 개수가 n인 배열 a에서 key와 일치하는 요소를 선형 검색(보초법) ---*/
int search(int a[], int n, int key)
{
    int i;

    a[n] = key;         // 보초를 추가

    for (i = 0; i < n; i++)
        if (a[i] == key)
            break;      // 원하는 키값을 찾은 경우

    return i == n ? -1 : i;
}

int main(void)
{
    int nx, ky;

    puts("선형 검색(보초법)");
    printf("요소 개수: ");
    scanf("%d", &nx);
    int *x = calloc(nx + 1, sizeof(int));   // 요소의 개수가 (nx + 1)인 int형 배열 x를 생성

    for (int i = 0; i < nx; i++) {          // 주의: 값을 읽은 것은 nx개
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }
    printf("검색값: ");
    scanf("%d", &ky);

    int idx = search(x, nx, ky);            // 배열 x에서 값이 ky인 요소를 선형 검색

    if (idx == -1)
        puts("검색에 실패했습니다.");
    else
        printf("%d(은)는 x[%d]에 있습니다.\n", ky, idx);

    free(x);                                // 배열 x를 해제

    return 0;
}
