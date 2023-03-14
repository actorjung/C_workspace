// 연습2-3　배열 요소의 평균 출력
#include <stdio.h>
#include <stdlib.h>

/*--- 요소 개수가 n인 배열 a의 요소의 평균 ---*/
double aveof(const int a[], int n)
{
    double sum = 0;             // 합계

    for (int i = 0; i < n; i++)
        sum += a[i];

    return sum / n;
}

int main(void)
{
    int number;                 // 사람 수 = 배열 height의 요소 개수 

    printf("사람 수: ");
    scanf("%d", &number);

    int *height = calloc(number, sizeof(int));  // 요소 개수가 number인 배열을 생성

    printf("%d명의 키를 입력하세요.\n", number);
    for (int i = 0; i < number; i++) {
        printf("height[%d] : ", i);
        scanf("%d", &height[i]);
    }

    printf("평균은 %f입니다.\n", aveof(height, number));

    free(height);                               // 배열 height를 해제

    return 0;
}
