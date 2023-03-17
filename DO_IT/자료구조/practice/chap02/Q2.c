// 키의 합계를 구하는 프로그램을 작성하세요
#include <stdio.h>
#include <stdlib.h>

/*--- 요소 개수가 n인 배열 a의 요소의 합 ---*/
int sumof(const int a[], int n)
{
    int sum = a[0];             // 합
    for (int i = 1; i < n; i++)
        sum += a[i]; 
    return sum;
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
    printf("키의 합은 %d입니다.\n",  sumof(height, number));
    free(height);                               // 배열 height를 해제

    return 0;
}