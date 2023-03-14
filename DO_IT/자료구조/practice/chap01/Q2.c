// 세 정수의 최소값을 구하는 프로그램

#include <stdio.h>

/*--- a, b, c의 최소값을 구하여 반환 ---*/
int min3(int a, int b, int c)
{
    int min = a;    // 최소값

    if (b < min) min = b;
    if (c < min) min = c;

    return min;
}

int main(){
    printf("min3(%d,%d,%d) = %d\n", 3, 2, 1,  min3(3, 2, 1));  

    return 0;
}