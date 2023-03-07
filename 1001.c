#include<stdio.h>
int subtraction(int a,int b);

int subtraction(int a,int b){
    
    return a-b ;
}

int main(){
    int num1 = 0;
    int num2 = 0;
    int answer = 0;
    printf("계산하고자 하는 두 정수를 입력하세요: ");
    scanf("%d %d",&num1,&num2);
    answer = subtraction(num1,num2);
    printf("%d",answer);
    return 0;
}