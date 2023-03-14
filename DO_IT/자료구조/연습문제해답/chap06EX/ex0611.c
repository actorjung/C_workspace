// 연습 6-11　이진 삽입 정렬(요소 이동에 memmove 함수 사용)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*--- 이진 삽입 정렬(요소 이동에 memmove 함수 사용)---*/
void bin_insertion(int a[], int n)
{
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int pl = 0;         // 검색 범위 맨 앞의 인덱스
        int pr = i - 1;     // 검색 범위 맨 끝의 인덱스
        int pc;             // 검색 범위 한가운데의 인덱스

        do {
            pc = (pl + pr) / 2;
            if (a[pc] == key)       // 검색 성공
                break;
            else if (a[pc] < key)
                pl = pc + 1;
            else
                pr = pc - 1;
        } while (pl <= pr);
        int pd = (pl <= pr) ? pc + 1 : pr + 1;      // 삽입할 위치의 인덱스

        memmove(&a[pd + 1], &a[pd], (i - pd) * sizeof(int)); 
        a[pd] = key;
    }
}

int main(void)
{
    int nx;

    puts("이진 삽입 정렬");
    printf("요소 개수: ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));   // 요소 개수가 nx인 int형 배열 x를 생성

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    bin_insertion(x, nx);               // 배열 x를 단순 삽입 정렬

    puts("오름차순으로 정렬했습니다.");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);                            // 배열 x를 해제

    return 0;
}
