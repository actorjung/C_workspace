// int형 배열을 초기화하고 출력
#include <stdio.h>

int main(void)
{
    int a[5] = {1, 2, 3, 4, 5};
    int na = sizeof(a) / sizeof(a[0]);  // 요소의 개수
    printf("배열 a의 요소 개수는 %d입니다.\n", na);

    for (int i = 0; i < na; i++)
        printf("a[%d] = %d\n", i, a[i]);

    return 0;
}
