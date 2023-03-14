// 난수 생성(2: 현재 시각에 따라 난수 종류 변경)

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    srand(time(NULL));
    int x = rand();     // 0~RAND_MAX 난수
    int y = rand();     // 0~RAND_MAX 난수
    printf("x는 %d이고 y는 %d입니다.\n", x, y);

    return 0;
}
