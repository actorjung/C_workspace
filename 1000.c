#include<stdio.h>
int add(int a,int b);

int add(int a,int b){
    
    return a+b ;
}

int main(){
    int num1;
    int num2;
    int answer;
    printf("계산하고자 하는 두 정수를 입력하세요: ");
    scanf("%d %d",&num1,&num2);
    answer = add(num1,num2);
    printf("%d",answer);
    return 0;
}