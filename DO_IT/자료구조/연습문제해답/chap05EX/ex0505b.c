// 연습 5-5 진정한 재귀적 함수 recur를 메모이제이션으로 구현
#include <stdio.h>

int counter = 0;    // recur 함수의 호출 횟수

static char memo[128][1024];        // 메모용 문자열 배열

/*--- 메모이제이션을 도입한 recur 함수 ---*/
void recur(int n) {
    counter++;
    if (memo[n + 1][0] != '\0')
        printf("%s", memo[n + 1]);              // 메모 출력
    else {
        if (n > 0) {
            recur(n - 1);
            printf("%d\n", n);
            recur(n - 2);
            sprintf(memo[n + 1], "%s%d\n%s", memo[n], n, memo[n - 1]);
        }
        else {
            strcpy(memo[n + 1], "");
        }
    }
}

int main(void)
{
    int x;

    printf("정수를 입력하세요.: ");
    scanf("%d", &x);

    recur(x);

    printf("recur 함수는 %d회 출력되었습니다.\n", counter);

    return 0;
}
