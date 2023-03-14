// 연습 6-21　도수 정렬(정렬 과정을 자세히 출력)
#include <stdio.h>
#include <stdlib.h>

/*--- 도수 정렬（배열 요솟값은 0 이상 max 이하）---*/
void counting(int a[], int n, int max)
{
    int *f = calloc(max + 1, sizeof(int));      // 누적 도수
    int *b = calloc(n,       sizeof(int));      // 작업용 목적 배열

    puts("\n정렬 전 배열");
    for (int i = 0; i < n; i++) printf("%3d", i);       putchar('\n');
    for (int i = 0; i < n; i++) printf("---", i);       putchar('\n');
    for (int i = 0; i < n; i++) printf("%3d", a[i]);    putchar('\n');

    for (int i = 0;     i <= max; i++) f[i] = 0;            // [Step0]
    for (int i = 0;     i < n;    i++) f[a[i]]++;           // [Step1]

    puts("\n도수분포");
    for (int i = 0; i < max; i++) printf("%3d", i);     putchar('\n');
    for (int i = 0; i < max; i++) printf("---", i);     putchar('\n');
    for (int i = 0; i < max; i++) printf("%3d", f[i]);  putchar('\n');

    for (int i = 1;     i <= max; i++) f[i] += f[i - 1];    // [Step2]

    puts("\n누적 도수분포");
    for (int i = 0; i < max; i++) printf("%3d", i);     putchar('\n');
    for (int i = 0; i < max; i++) printf("---", i);     putchar('\n');
    for (int i = 0; i < max; i++) printf("%3d", f[i]);  putchar('\n');

    putchar('\n');
    for (int i = n - 1; i >= 0;   i--) {                    // [Step3]
        b[--f[a[i]]] = a[i];
        printf("a[%2d]의% 2d를 b[%2d]에 저장.\n", i, a[i], f[a[i]]);
    }

    for (int i = 0;     i < n;    i++) a[i] = b[i];         // [Step4]

    puts("\n정렬 후 배열");
    for (int i = 0; i < n; i++) printf("%3d", i);       putchar('\n');
    for (int i = 0; i < n; i++) printf("---", i);       putchar('\n');
    for (int i = 0; i < n; i++) printf("%3d", a[i]);    putchar('\n');
    free(b);
    free(f);
}

int main(void)
{
    int nx;
    const int max = 100;            // 最大値

    puts("도수 정렬");
    printf("요소 개수: ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));

    printf("0～%d의 정수를 입력하세요.\n", max);
    for (int i = 0; i < nx; i++) {
        do {
            printf("x[%d] : ", i);
            scanf("%d", &x[i]);
        } while (x[i] < 0 || x[i] > max);
    }

    counting(x, nx, max);       // 배열 x를 도수 정렬

    puts("오름차순으로 정렬했습니다.");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);                    // 배열 x를 해제

    return 0;
}
