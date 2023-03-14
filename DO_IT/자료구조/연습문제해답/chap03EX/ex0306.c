// 연습3-6　bsearch 함수를 사용하여 내림차순으로 정렬한 long형 배열에서 검색
#include <stdio.h>
#include <stdlib.h>

/*--- 정수를 비교하는 함수(long형 내림차순) ---*/
int long_cmpr(const long *a, const long *b)
{
    if (*a < *b)
        return 1;
    else if (*a > *b)
        return -1;
    else
        return 0;
}

int main(void)
{
    int nx;
    long ky;

    puts("bsearch 함수를 사용하여 검색");
    printf("요소 개수: ");
    scanf("%d", &nx);
    long *x = calloc(nx, sizeof(long)); // 요소의 개수가 nx인 long형 배열 x를 생성

    printf("내림차순으로 입력하세요.\n");

    printf("x[0] : ");
    scanf("%ld", &x[0]);

    for (int i = 1; i < nx; i++) {
        do {
            printf("x[%d] : ", i);
            scanf("%ld", &x[i]);
        } while (x[i] > x[i - 1]);      // 바로 앞의 값보다 크면 다시 입력
    }

    printf("검색값: ");
    scanf("%d", &ky);

    long *p = bsearch(
                &ky,                            // 검색값에 대한 포인터
                x,                              // 배열
                nx,                             // 요소의 개수
                sizeof(int),                    // 요소의 크기
                (int (*)(const void *, const void *))long_cmpr  // 비교 함수
             );

    if (p == NULL)
        puts("검색에 실패했습니다.");
    else
        printf("%d는(은) x[%d]에 있습니다.\n", ky, (int)(p - x));

    free(x);                            // 배열 x를 해제

    return 0;
}
