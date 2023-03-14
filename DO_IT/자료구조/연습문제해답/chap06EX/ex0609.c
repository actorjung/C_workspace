// 연습 6-9　단순 삽입 정렬(데이터는 a[1] 이후에 저장됨)
#include <stdio.h>
#include <stdlib.h>

/*--- 단순 삽입 정렬(데이터는 a[1] 이후에 저장됨) ---*/
void insertion(int a[], int n)
{
    for (int i = 2; i <= n; i++) {
        int tmp = a[0] = a[i];
        int j;
        for (j = i; a[j - 1] > tmp; j--)
            a[j] = a[j - 1];
        if (j > 0) a[j] = tmp;
    }
}

int main(void)
{
    int nx;

    puts("단순 삽입 정렬");
    printf("요소 개수: ");
    scanf("%d", &nx);
    int *x = calloc(nx + 1, sizeof(int));   // 요소의 개수가 (nx+1)인 int형 배열 x를 생성

    for (int i = 1; i < nx + 1; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    insertion(x, nx);                   // 배열 x를 단순 삽입 정렬

    puts("오름차순으로 정렬했습니다.");
    for (int i = 1; i < nx + 1; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);                            // 배열 x를 해제

    return 0;
}
