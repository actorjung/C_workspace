// 연습3-7　bsearch 함수와 같은 형식의 선형 탐색 함수
#include <stdio.h>
#include <stdlib.h>

/*--- base가 가리키는 요소의 크기가 size이고 요소의 개수가 nmemb인 배열에서 key와 일치하는 요소를
      비교 함수 compar를 사용해서 선형 검색 ---*/
void *seqsearch(const void *key, const void *base, size_t nmemb, size_t size,
                int (*compar)(const void *, const void *))
{
    char *x = (char *)base;

    for (size_t i = 0; i < nmemb; i++)
        if (!compar((const void *)&x[i * size], key))
            return (&x[i * size]);
    return NULL;                            // 검색 실패
}

/*--- 정수를 비교하는 함수 ---*/
int int_cmp(const int *a, const int *b)
{
    if (*a < *b)
        return -1;
    else if (*a > *b)
        return 1;
    else
        return 0;
}

int main(void)
{
    int nx, ky;

    puts("seqsearch 함수로 검색");
    printf("요소 개수: ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));   // 요소 개수가 nx인 int형 배열 x를 생성

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
            scanf("%d", &x[i]);
    }

    printf("검색값: ");
    scanf("%d", &ky);

    int *p = seqsearch(
                &ky,                            // 검색값에 대한 포인터
                x,                              // 배열
                nx,                             // 요소의 개수
                sizeof(int),                    // 요소의 크기
                (int (*)(const void *, const void *))int_cmp    // 비교 함수
             );

    if (p == NULL)
        puts("검색에 실패했습니다.");
    else
        printf("%d는(은) x[%d]에 있습니다.\n", ky, (int)(p - x));

    free(x);                            // 배열 x를 해제

    return 0;
}
