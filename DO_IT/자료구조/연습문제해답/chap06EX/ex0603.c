// 연습 6-3　배열이 정렬을 마쳤는지를 검사
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- 배열이 정렬을 마쳤는가? ---*/
int is_sorted(int a[], int n)
{
    for (int i = n - 1; i > 0; i--)
        if (a[i - 1] > a[i])
            return 0;
    return 1;
}

int main(void)
{
    int nx, sorted;

    puts("정렬 완료 확인");
    printf("요소 개수: ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));   // 요소 개수가 nx인 int형 배열 x를 생성

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    sorted = is_sorted(x, nx);          // 배열 x는 정렬을 마쳤는가?

    if (sorted)
        puts("배열은 정렬을 마친 상태입니다.");
    else
        puts("배열은 정렬을 마치지 않은 상태입니다.");

    free(x);                            // 배열 x를 해제

    return 0;
}
