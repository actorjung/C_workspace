// 난수 생성(1)
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x = rand();     // 0~RAND_MAX 난수
    int y = rand();     // 0~RAND_MAX 난수
    printf("x는 %d이고 y는 %d입니다.\n", x, y);

    return 0;
}
