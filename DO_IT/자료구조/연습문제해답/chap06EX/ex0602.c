// 연습 6-2　버블 정렬(교환 과정을 자세히 출력)
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- 버블 정렬 ---*/
void bubble(int a[], int n)
{
    int ccnt = 0;       // 비교 횟수
    int scnt = 0;       // 비교 횟수

    for (int i = 0; i < n - 1; i++) {
        printf("패스%d：\n", i + 1);
        for (int j = n - 1; j > i; j--) {
            for (int m = 0; m < n - 1; m++)
                printf("%3d %c" , a[m], (m != j-1) ? ' ' :
                                        (a[j - 1] > a[j]) ? '+' : '-');
            printf("%3d\n", a[n - 1]);

            ccnt++;
            if (a[j - 1] > a[j]) {
                scnt++;
                swap(int, a[j - 1], a[j]);
            }
        }
        for (int m = 0; m < n; m++)
            printf("%3d  " , a[m]);
        putchar('\n');
    }
    printf("비교를 %d회 했습니다.\n", ccnt);
    printf("교환을 %d회 했습니다.\n", scnt);
}

int main(void)
{
    int nx;

    puts("버블 정렬");
    printf("요소 개수: ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));   // 요소 개수가 nx인 int형 배열 x를 생성

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    bubble(x, nx);                      // 배열 x를 버블 정렬

    puts("오름차순으로 정렬했습니다.");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);                            // 배열 x를 해제

    return 0;
}
