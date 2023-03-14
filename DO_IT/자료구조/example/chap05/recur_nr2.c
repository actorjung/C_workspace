// 재귀에 대한 이해를 높이기 위한 진정한 재귀적 함수(재귀 제거)
#include <stdio.h>
#include "IntStack.h"

/*--- 재귀 호출을 제거한 recur 함수 ---*/
void recur(int n)
{
    IntStack stk;               // 스택
    Initialize(&stk, 100);
Top:
    if (n > 0) {
        Push(&stk, n);          // n값을 푸시
        n = n - 1;
        goto Top;
    }
    if (!IsEmpty(&stk)) {       // 스택이 비어 있지 않으면
        Pop(&stk, &n);          // 값을 저장했던 n을 팝
        printf("%d\n", n);
        n = n - 2;
        goto Top;
    }
    Terminate(&stk);
}

int main(void)
{
    int x;

    printf("정수를 입력하세요: ");
    scanf("%d", &x);

    recur(x);

    return 0;
}
