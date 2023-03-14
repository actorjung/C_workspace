// 연습 6-6　양방향 버블 정렬(셰이커 정렬)
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- 양방향 버블 정렬(셰이커 정렬)---*/
void shaker(int a[],int n)
{
    int left = 0;
    int right = n - 1;
    int last = right;

    while (left < right){
        for (int j = right; j > left; j--){
            if (a[j - 1] > a[j]){
                swap(int, a[j - 1], a[j]);
                last = j;
            }
        }
        left = last;

        for (int j = left; j < right; j++){
            if (a[j] > a[j + 1]){
                swap(int, a[j], a[j + 1]);
                last = j;
            }
        }
        right = last;
    }
}

int main(void)
{
    int nx;

    puts("양방향 버블 정렬");
    printf("요소 개수: ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));   // 요소 개수가 nx인 int형 배열 x를 생성

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    shaker(x, nx);                      // 배열 x를 양방향 버블 정렬

    puts("오름차순으로 정렬했습니다.");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);                            // 배열 x를 해제

    return 0;
}
