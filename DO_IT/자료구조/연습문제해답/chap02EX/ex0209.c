// 연습2-9　배열의 모든 요소를 뒤섞어서 나열
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

/*--- type형 x값과 y값을 교 ---*/
#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- 요소 개수가 n인 배열 a의 모든 요소 순서를 뒤섞어서 나열 ---*/
void shuffle(int a[], int n)
{
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--) {   // 배열 a를 뒤섞음
        int j = rand() % (i + 1);
        if (i != j)
            swap(int, a[i], a[j]);
    }
}

int main(void)
{
    int nx;     // 배열 x의 요소 개수

    printf("요소 개수: ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));   // 요소 개수가 nx인 int형 배열 x를 생성

    printf("%d개의 정수를 입력하세요.\n", nx);
    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    shuffle(x, nx);                     // 배열 x의 요소의 순서를 뒤섞기

    printf("배열의 모든 요소의 순서를 뒤섞었습니다.\n");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);                            // 배열 x를 해제

    return 0;
}