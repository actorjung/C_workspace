// 1,000 이하의 소수를 나열(버전 3)
#include <stdio.h>

int main(void)
{
    int prime[500];                         // 소수를 저장하는 배열
    int ptr = 0;                            // 이미 얻은 소수의 개수
    unsigned long counter = 0;              // 곱셈과 나눗셈의 실행 횟수
    prime[ptr++] = 2;                       // 2는 소수
    prime[ptr++] = 3;                       // 3은 소수
    for (int n = 5; n <= 1000; n += 2) {    // 홀수만을 대상
        int i;
        int flag = 0;
        for (i = 1; counter++, prime[i] * prime[i] <= n; i++) {
            counter++;
            if (n % prime[i] == 0) {        // 나누어떨어지면 소수가 아님
                flag = 1;
                break;                      // 더 이상의 반복은 불필요
            }
        }
        if (!flag)                          // 마지막까지 나누어떨어지지 않음
            prime[ptr++] = n;               // 배열에 저장
    }
    for (int i = 0; i < ptr; i++)
        printf("%d\n", prime[i]);

    printf("곱셈과 나눗셈을 실행한 횟수: %lu\n", counter);

    return 0;
}
