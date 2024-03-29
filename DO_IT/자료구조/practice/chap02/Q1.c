// 키의 최소값을 구하는 프로그램을 작성하세요.
#include <stdio.h>
#include <stdlib.h>

/*--- 요소 개수가 n인 배열 a의 요소의 최소값 ---*/
int minof(const int a[], int n)
{
    int min = a[0];             // 최소값
    for (int i = 1; i < n; i++)
        if (a[i] < min) min = a[i];
    return min;
}

int main(void)
{
    int number;                 // 인원 = 배열 height의 요소 개수
    printf("사람 수: ");
    scanf("%d", &number);
    int* height = calloc(number, sizeof(int));  // 요소 개수 number개인 배열을 생성
    printf("%d명의 키를 입력하세요.\n", number);
    for (int i = 0; i < number; i++) {
        printf("height[%d] : ", i);
        scanf("%d", &height[i]);
    }
    printf("최소값은 %d입니다.\n", minof(height, number));
    free(height);                               // 배열 height를 해제

    return 0;
}