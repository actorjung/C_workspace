// 연습 6-7　단순 선택 정렬(교환 과정을 자세히 출력)
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- 단순 선택 정렬(교환 과정을 자세히 출력)---*/
void selection(int a[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;
        for (int m = 0; m < n; m++)
            printf((m == i) ? "  * " : (m == min) ? "  + " : "    ");
        putchar('\n');

        for (int m = 0; m < n; m++)
            printf("%3d ", a[m]);
        putchar('\n');

        swap(int, a[i], a[min]);
    }
    putchar('\n');
    for (int m = 0; m < n; m++)
        printf("%3d ", a[m]);
    putchar('\n');
}

int main(void)
{
    int nx;

    puts("단순 선택 정렬");
    printf("요소 개수: ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));   // 요소 개수가 nx인 int형 배열 x를 생성

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    selection(x, nx);                   // 배열 x를 단순 선택 정렬

    puts("오름차순으로 정렬했습니다.");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);                            // 배열 x를 해제

    return 0;
}

