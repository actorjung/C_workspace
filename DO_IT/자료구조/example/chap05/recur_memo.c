// 재귀 함수 recur를 메모이제이션으로 구현

#include <stdio.h>

static char memo[128][1024];        // 메모용 문자열 배열

/*--- 메모이제이션을 도입한 recur 함수 ---*/
void recur(int n) {
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

    printf("정수를 입력하세요: ");
    scanf("%d", &x);

    recur(x);

    return 0;
}
