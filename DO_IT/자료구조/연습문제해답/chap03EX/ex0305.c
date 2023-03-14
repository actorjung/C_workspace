// 연습3-5　이진 검색(맨 앞의 요소를 검색)
#include <stdio.h>
#include <stdlib.h>

/*--- 요소 개수가 n인 배열 a에서 key와 일치하는 요소를 이진 검색(맨 앞에 있는 요소를 검색) ---*/
int bin_search2(const int a[], int n, int key)
{
    int pl = 0;                     // 검색 범위 맨 앞의 인덱스
    int pr = n - 1;                 // 검색 범위 맨 끝의 인덱스


    do {
        int pc = (pl + pr) / 2;     // 검색 범위 한가운데의 인덱스
        if (a[pc] == key) {         // 검색 성공
            while (pc > pl && a[pc - 1] == key)
                pc--;
            return pc;
        } else if (a[pc] < key)
            pl = pc + 1;            // 검색 범위를 뒤쪽 절반으로 좁힘
        else
            pr = pc - 1;            // 검색 범위를 앞쪽 절반으로 좁힘
    } while (pl <= pr);

    return -1;                      // 검색 실패
}

int main(void)
{
    int nx, ky;

    puts("이진 검색");
    printf("요소 개수: ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));   // 요소 개수가 nx인 int형 배열 x를 생성

    printf("오름차순으로 입력하세요.\n");
    printf("x[0] : ");
    scanf("%d", &x[0]);

    for (int i = 1; i < nx; i++) {
        do {
            printf("x[%d] : ", i);
            scanf("%d", &x[i]);
        } while (x[i] < x[i - 1]);      // 바로 앞의 값보다 작으면 다시 입력
    }
    printf("검색값: ");
    scanf("%d", &ky);

    int idx = bin_search2(x, nx, ky);   // 배열 x에서 값이 ky인 요소를 이진 검색

    if (idx == -1)
        puts("검색에 실패했습니다.");
    else
        printf("%d은(는) x[%d]에 있습니다.\n", ky, idx);

    free(x);                            // 배열 x를 해제

    return 0;
}
