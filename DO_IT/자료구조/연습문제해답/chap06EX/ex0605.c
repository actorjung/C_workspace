// 연습 6-5　버블 정렬(버전 3: 교환 과정을 자세히 출력)
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- 버블 정렬(버전 3: 스캔 범위를 제한) ---*/
void bubble(int a[], int n)
{
    int ccnt = 0;       // 비교 횟수
    int scnt = 0;       // 비교 횟수
    int i = 0;          // 패스
    int k = 0;          // a[k]보다 앞쪽의 요소는 정렬을 마친 상태

    while (k < n - 1) {
        int j;
        int last = n - 1;           // 마지막으로 교환을 수행한 위치를 저장

        printf("패스%d：\n", ++i);
        for (int j = n - 1; j > k; j--) {
            for (int m = 0; m < n - 1; m++)
                printf("%3d %c" , a[m], (m != j-1) ? ' ' :
                                        (a[j - 1] > a[j]) ? '+' : '-');
            printf("%3d\n", a[n - 1]);

            ccnt++;
            if (a[j - 1] > a[j]) {
                swap(int, a[j - 1], a[j]);
                last = j;
                scnt++;
            }
        }
        k = last;
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
