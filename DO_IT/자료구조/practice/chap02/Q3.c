// 키의 합의 평균을 구하는 프로그램을 작성하세요
#include <stdio.h>
#include <stdlib.h>

/*--- 요소 개수가 n인 배열 a의 요소의 합의 평균 ---*/
double aveof(const double a[], int n)
{
    double ave = a[0];             // 합
    for (int i = 1; i < n; i++)
        ave += a[i]; 
    return (ave/n); //합의 평균
}

int main(void)
{
    int number;                 // 인원 = 배열 height의 요소 개수
    printf("사람 수: ");
    scanf("%d", &number);
    double* height = calloc(number, sizeof(double));  // 요소 개수 number개인 배열을 생성
    printf("%d명의 키를 입력하세요.\n", number);
    for (int i = 0; i < number; i++) {
        printf("height[%d] : ", i);
        scanf("%lf", &height[i]);
    }
    printf("키의 합의 평균은 %lf입니다.\n",  aveof(height, number));
    free(height);                               // 배열 height를 해제

    return 0;
}