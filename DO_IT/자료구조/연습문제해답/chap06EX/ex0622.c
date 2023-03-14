// 연습 6-22　도수 정렬(최솟값과 최댓값을 지정)
#include <stdio.h>
#include <stdlib.h>

/*--- 도수 정렬（배열 요솟값은 min 이상 max 이하） ---*/
void counting(int a[], int n, int min, int max)
{
    int *f = calloc(max - min + 2, sizeof(int));    // 누적 도수
    int *b = calloc(n, sizeof(int));                // 작업용 목적 배열

    for (int i=0;   i <= max-min+1; i++) f[i] = 0;                  // [Step0]
    for (int i=0;   i < n;          i++) f[a[i]-min]++;             // [Step1]
    for (int i=1;   i <= max-min+1; i++) f[i] += f[i - 1];          // [Step2]
    for (int i=n-1; i >= 0;         i--) b[--f[a[i]-min]] = a[i];   // [Step3]
    for (int i=0;   i < n;          i++) a[i] = b[i];               // [Step4]

    free(b);
    free(f);
}
int main(void)
{
    int nx;
    int min, max;           // 최솟값과 최댓값

    puts("도수 정렬");
    printf("요소 개수: ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));   // 요소 개수가 nx인 int형 배열 x를 생성

    printf("최솟값: ");
    scanf("%d", &min);

    while (1) {
        printf("최댓값: ");
        scanf("%d", &max);
        if (max > min) break;
        printf("%d보다 큰 값을 입력하세요.\n", min);
    }

    printf("%d ~ %d의 정수를 입력하세요.\n", min, max);
    for (int i = 0; i < nx; i++) {
        do {
            printf("x[%d] : ", i);
            scanf("%d", &x[i]);
        } while (x[i] < min || x[i] > max);
    }

    counting(x, nx, min, max);          // 배열 x를 도수 정렬

    puts("오름차순으로 정렬했습니다.");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);                            // 배열 x를 해제

    return 0;
}
