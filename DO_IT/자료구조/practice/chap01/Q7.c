//n이 5이면 1 + 2 + 3 + 4 + 5 = 15로 출력하는 프로그램을 작성해라
#include <stdio.h>

int main(void)
{
    int n;

    puts("1부터 n까지의 총합을 구합니다.");

    printf("n값: ");
    scanf("%d", &n);

    int sum = 0;        // 초기화

    for (int i = 1 ; i <= n; i++){   // i = 1, 2, …, n
        sum += i;               // sum에 i를 추가
    }
    for (int i = 1; i <= n; i++){
        if(i==n)
            printf("%d", i);
        else{
            printf("%d", i);
            printf(" + ");
        }
        
    }
    printf(" = %d",sum);
    return 0;
}