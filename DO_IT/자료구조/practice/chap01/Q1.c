// 네 정수의 최댓값을 구하는 프로그램

#include <stdio.h>

/*--- a, b, c, d의 최댓값을 구하여 반환 ---*/
int max4(int a, int b, int c,int d)
{
    int max = a;    // 최댓값

    if (b > max) max = b;
    if (c > max) max = c;
    if (d > max) max = d;

    return max;
}

int main(){
    printf("max4(%d,%d,%d,%d) = %d\n", 3, 2, 1, 4, max4(3, 2, 1, 4));  

    return 0;
}