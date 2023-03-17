// 배열 요소를 역순으로 정렬하는 과정을 일일이 출력하는 프로그램을 작성하세요
#include <stdio.h>
#include <stdlib.h>

/*--- type형 x값과 y값을 교환 ---*/
#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- 요소 개수가 n인 배열 a의 요소를 역순으로 정렬 ---*/
void ary_reverse(int a[], int n)
{   
    for(int i=0; i<n; i++){
        printf("%d ",a[i]);
    }
    for (int i = 0; i < n / 2; i++){
        printf("\na[%d]과 a[%d]를 교환합니다.\n",i,n-i-1);
        swap(int, a[i], a[n - i - 1]);
        for(int i=0; i<n; i++){
        printf("%d ",a[i]);
    }
}
}

int main(void)
{
    int nx;     // 배열 x의 요소 개수

    printf("요소 개수: ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));   // 요소 개수 nx의 int형 배열 x를 생성
    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }
    ary_reverse(x, nx);                 // 배열 x의 요소를 역순으로 정렬
    printf("\n역순 정렬을 종료합니다.\n");
    free(x);                            // 배열 x를 해제

    return 0;
}
