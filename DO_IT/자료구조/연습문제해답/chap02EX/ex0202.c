// 연습2-2　배열 요소의 합계를 구해서 출력
#include <stdio.h>

/*--- 요소 개수가 n인 배열 a의 요소의 합계 ---*/
int sumof(const int a[], int n)
{
    int sum = 0;                // 합계

    for (int i = 0; i < n; i++)
        sum += a[i];

    return sum;
}

int main(void)
{
    int number;                 // 인원 = 배열 height의 요소 개수

    printf("사람 수: ");
    scanf("%d", &number);

    int *height = calloc(number, sizeof(int));  // 요소 개수 number개인 배열을 생성

    printf("%d명의 키를 입력하세요.\n", number);
    for (int i = 0; i < number; i++) {
        printf("height[%d] : ", i);
        scanf("%d", &height[i]);
    }

    printf("합계는 %d입니다.\n", sumof(height, number));

    free(height);                               // 배열 height를 해제

    return 0;
}
