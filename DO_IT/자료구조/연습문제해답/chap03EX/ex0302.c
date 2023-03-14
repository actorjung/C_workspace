// 연습3-2　선형검색(버전 1: 탐색 과정을 출력)*/
#include <stdio.h>
#include <stdlib.h>

/*--- 요소의 개수가 n인 배열 a에서 key와 일치하는 요소를 선형 검색 ---*/
int search(const int a[], int n, int key)
{
    printf("   |");
    for (int i = 0; i < n; i++)
        printf("%3d", i);
    printf("\n---+");
    for (int i = 0; i < n; i++)
        printf("---", i);
    printf("--\n");

    for (int i = 0; i < n; i++) {
        printf("   |");
        printf("%*s", 3 * (i - 1) + 5, "");
        printf("*\n");
        printf("%3d|", i);
        for (int j = 0; j < n; j++)
            printf("%3d", a[j]);
        putchar('\n');

        if (a[i] == key)
            return i;           // 검색 성공

        printf("   |\n");
    }

    return -1;                  // 검색 실패
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
        printf("%d는(은) x[%d]에 있습니다.\n", ky, idx);

    free(x);                                // 배열 x를 해제

    return 0;
}
