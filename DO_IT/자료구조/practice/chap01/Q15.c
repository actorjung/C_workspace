//입력한 높이와 너비에 맞는 직사각형을 *기호로 출력하는 프로그램을 작성하세요.
#include<stdio.h>
int main(){
    int num1=0, num2=0;
    puts("직사각형을 출력합니다.");
    printf("높이 : ");
    scanf("%d",&num1);
    printf("너비 : ");
    scanf("%d",&num2);
3
    for(int i=0; i<num1; i++){
        for(int j=0;j<num2;j++){
            printf("*");
        }
        printf("\n");
    }
