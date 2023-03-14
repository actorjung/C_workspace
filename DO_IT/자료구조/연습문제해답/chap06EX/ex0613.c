// 연습 6-13　퀵 정렬（(비재귀 버전: 푸시, 팝, 분할을 자세히 출력)
// 이 프로그램을 컴파일하려면 'IntStack.h'와 'IntStack.c' 파일이 필요합니다.
#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

/*--- 퀵 정렬(비재귀 버전)---*/
void quick(int a[], int left, int right)
{
    IntStack lstack;        // 나눌 첫 요소 인덱스의 스택
    IntStack rstack;        // 나눌 끝 요소 인덱스의 스택

    Initialize(&lstack, right - left + 1);
    Initialize(&rstack, right - left + 1);

    Push(&lstack, left);
    Push(&rstack, right);

    printf("a[%d] ~ a[%d]를 나누는 문제를 스택에 푸시합니다.\n", left, right);
    printf("Lstack:");   Print(&lstack);
    printf("Rstack:");   Print(&rstack);

    while (!IsEmpty(&lstack)) {
        int pl = (Pop(&lstack, &left),  left);      // 왼쪽 커서
        int pr = (Pop(&rstack, &right), right);     // 오른쪽 커서
        int x = a[(left + right) / 2];              // 피벗은 가운데 요소
        printf("스택에서 나누는 문제를 꺼냈습니다. a[%d] ~ a[%d]를 나눕니다.\n", left, right);

        do {
            while (a[pl] < x) pl++;
            while (a[pr] > x) pr--;
            if (pl <= pr) {
                swap(int, a[pl], a[pr]);
                pl++;
                pr--;
            }
        } while (pl <= pr);

        if (left < pr) {
            Push(&lstack, left);    // 왼쪽 그룹 범위의
            Push(&rstack, pr);      // 인덱스를 푸시

            printf("a[%d] ~ a[%d]를 나누는 문제를 스택에 푸시합니다.\n", left, pr);
            printf("Lstack:");   Print(&lstack);
            printf("Rstack:");   Print(&rstack);
        }
        if (pl < right) {
            Push(&lstack, pl);      // 오른쪽 그룹 범위의
            Push(&rstack, right);   // 인덱스를 푸시

            printf("a[%d] ~ a[%d]를 나누는 문제를 스택에 푸시합니다.\n", pl, right);
            printf("Lstack:");   Print(&lstack);
            printf("Rstack:");   Print(&rstack);
        }
    }
    Terminate(&lstack);
    Terminate(&rstack);
}

int main(void)
{
    int nx;

    puts("퀵 정렬");
    printf("요소 개수: ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));   // 요소 개수가 nx인 int형 배열 x를 생성

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    quick(x, 0, nx - 1);                // 배열 x를 퀵 정렬

    puts("오름차순으로 정렬했습니다.");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);                            // 배열 x를 해제

    return 0;
}
