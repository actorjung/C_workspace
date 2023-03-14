// 네 정수의 최소값을 구하는 프로그램

#include <stdio.h>

/*--- a, b, c, d의 최소값을 구하여 반환 ---*/
int min4(int a, int b, int c, int d)
{
    int min = a;    // 최소값

    if (b < min) min = b;
    if (c < min) min = c;
    if (d < min) min = d;

    return min;
}

int main(){
    printf("min4(%d,%d,%d,%d) = %d\n", 3, 2, 1, 4, min4(3, 2, 1, 4));  

    return 0;
}