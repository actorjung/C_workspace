// 연습 5-3　배열의 모든 요소의 최대공약수를 구하여 출력
#include <stdio.h>

/*--- 정수 x, y의 최대공약수를 반환 ---*/
int gcd(int x, int y)
{
    if (y == 0)
        return (x);
    else
        return (gcd(y, x % y));
}

/*--- 요소 개수가 n인 배열 a의 모든 요소의 최대공약수 ---*/
int gcd_array(const int a[], int n)
{
    if (n == 1)
        return (a[0]);
    else if (n == 2)
        return (gcd(a[0], a[1]));
    else
        return (gcd(a[0], gcd_array(&a[1], n - 1)));
}

int main(void)
{
    int nx;

    printf("요소 개수: ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));   // 요소 개수가 nx인 int형 배열 x를 생성

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    printf("최대공약수는 %d입니다.\n", gcd_array(x, nx));

    free(x);                            // 배열을 해제

    return 0;
}
