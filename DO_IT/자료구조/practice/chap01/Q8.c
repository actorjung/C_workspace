// 가우스의 덧셈이라는 방법을 이용하여 1부터 n까지의 합을 구하는 프로그램을 작성하라. 
#include <stdio.h>

int main(void)
{
    int n;

    puts("1부터 n까지의 총합을 구합니다.");

    printf("n값: ");
    scanf("%d", &n);

    int sum = 0;        // 초기화

    sum = (1+n)*(n/2);       // sum에 i를 추가
    
    printf("1부터 %d까지의 총합은 %d입니다.\n", n, sum);

    return 0;
}