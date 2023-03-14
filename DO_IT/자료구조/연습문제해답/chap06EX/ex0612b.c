// 연습 6-12　셸 정렬(버전 2: 요소의 이동 횟수를 출력)
#include <stdio.h>
#include <stdlib.h>

/*--- 셸 정렬(버전 2: 요소의 이동 횟수를 반환) ---*/
int shell(int a[], int n)
{
    int h;
    int count = 0;                  // 이동 횟수

    for (h = 1; h < n; h = h * 3 + 1)
        ;

    for ( ; h > 0; h /= 3)
        for (int i = h; i < n; i++) {
            int tmp = a[i];
            int j;
            for (j = i - h; j >= 0 && a[j] > tmp; j -= h) {
                a[j + h] = a[j];
                count++;
            }
            a[j + h] = tmp;
            count++;
        }
    return count;
}

int main(void)
{
    int nx;

    puts("셸 정렬");
    printf("요소 개수: ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));   // 요소 개수가 nx인 int형 배열 x를 생성

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    int count = shell(x, nx);           // 배열 x를 셸 정렬

    puts("오름차순으로 정렬했습니다.");
    for (int i =0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    printf("요소는 %d회 이동했습니다.\n", count);

    free(x);                            // 배열 x를 해제

    return 0;
}
