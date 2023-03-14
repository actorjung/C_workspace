// qsort 함수를 이용하여 정수 배열 요소를 값의 내림차순으로 정렬
#include <stdio.h>
#include <stdlib.h>

/*--- int형 비교 함수(내림차순 정렬 사용) ---*/
int int_cmpr(const int *a, const int *b)
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
    printf("qsort에 의한 정렬\n");
    printf("요소 개수: ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));   // 요소의 개수가 nx인 int형 배열 x를 생성
    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }
    qsort(x,                                            // 배열
          nx,                                           // 요소의 개수
          sizeof(int),                                  // 요소의 크기
          (int (*)(const void *, const void *))int_cmpr // 비교 함수
         );

    puts("오름차순으로 정렬했습니다.");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);                            // 배열 x를 해제

    return 0;
}
