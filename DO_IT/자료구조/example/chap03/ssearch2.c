// 선형 검색(for 문）
#include <stdio.h>
#include <stdlib.h>

/*--- 요소의 개수가 n인 배열 a에서 key와 일치하는 요소를 선형 검색(for 문)---*/
int search(const int a[], int n, int key)
{
    for (int i = 0; i < n; i++)
        if (a[i] == key)
            return i;           // 검색 성공

    return -1;                  // 검색 실패
}

int main(void)
{
    int nx, ky;

    puts("선형 검색");
    printf("요소 개수 : ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));   // 요소의 개수가 nx인 int형 배열 x를 생성
    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }
    printf("검색값: ");
    scanf("%d", &ky);
    int idx = search(x, nx, ky);        // 배열 x의 값이 ky인 요소를 선형 검색
    if (idx == -1)
        puts("검색에 실패했습니다.");
    else
        printf("%d(은)는 x[%d]에 있습니다.\n", ky, idx);
    free(x);                            // 배열 x를 해제

    return 0;
}
