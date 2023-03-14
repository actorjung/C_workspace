// 연습 6-18　범용 퀵 정렬(qsort 함수와 같은 형식)
#include <stdio.h>
#include <stdlib.h>

/*--- x, y가 가리키는 n바이트의 영역을 교환 ---*/
static void memswap(void *x, void *y, size_t n)
{
    unsigned char *a = (unsigned char *)x;
    unsigned char *b = (unsigned char *)y;

    for ( ; n--; a++, b++) {
        unsigned char c = *a;
        *a = *b;
        *b = c;
    }
}

/*--- 범용 퀵 정렬(qsort 함수와 같은 형식)---*/
void q_sort(void *base, size_t nmemb, size_t size,
            int (*compar)(const void *, const void *))
{
    if (nmemb > 0) {
        size_t pl = 0;                  // 왼쪽 커서
        size_t pr = nmemb - 1;          // 오른쪽 커서
        size_t pv = nmemb;              // 피벗
        size_t pt = (pl + pr) / 2;      // 피벗 갱신값
        char *v = (char *)base;         // 맨 앞 요소에 대한 포인터

        do {
            char *x = &v[(pv = pt) * size];     // 피벗에 대한 포인터
            while (compar((const void *)&v[pl * size], x) < 0) pl++;
            while (compar((const void *)&v[pr * size], x) > 0) pr--;
            if (pl <= pr) {
                pt = (pl == pv) ? pr : (pr == pv) ? pl : pv;
                memswap(&v[pl * size], &v[pr * size], size);
                pl++;
                if (pr == 0)    // 부호 없는 정수 0으로부터의 감소 방지
                    goto QuickRight;
                pr--;
            }
        } while (pl <= pr);

        if (0  < pr)      q_sort(&v[0],         pr + 1,     size, compar);
    QuickRight:
        if (pl < nmemb-1) q_sort(&v[pl * size], nmemb - pl, size, compar);
    }
}

/*--- int형 비교 함수(오름차순 정렬) ---*/
int int_cmp(const int *a, const int *b)
{
    return *a < *b ? -1 : *a > *b ? 1 : 0;
}

int main(void)
{
    int nx;

    printf("q_sort로 정렬\n");
    printf("요소 개수: ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));   // 요소 개수가 nx인 int형 배열 x를 생성

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    q_sort(x,                                           // 배열
           nx,                                          // 요소 개수
           sizeof(int),                                 // 요소 크기
           (int (*)(const void *, const void *))int_cmp // 비교 함수
          );

    puts("오름차순으로 정렬했습니다.");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);                            // 배열 x를 해제

    return 0;
}
