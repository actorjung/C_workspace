// 정수 a,b를 포함하여 그 사이의 모든 정수의 합을 구하는 함수를 작성해라.
#include <stdio.h>

int sumof(int a, int b){
    int sum=0,temp = 0;        // 초기화
    if(a>b){
        temp = b;
        b = a; 
        a = temp;
    }

    for (int i = a ; i <= b; i++){   // i = 1, 2, …, n
        sum += i;               // sum에 i를 추가
    }
    return sum;
}

int main(void)
{
    int num1, num2 = 0;

    puts("a부터 b까지의 총합을 구합니다.");

    printf("a값: ");
    scanf("%d", &num1);
    printf("b값: ");
    scanf("%d", &num2);

    printf("%d부터 %d까지의 총합은 %d 입니다.\n", num1, num2, sumof(num1,num2));

    return 0;
}