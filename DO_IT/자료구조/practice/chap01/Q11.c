// 양의 정수를 입력하고 자릿수를 출력하는 프로그램을 작성하세요

#include<stdio.h>
int main(){
    int num=0, count=0;
    do{
    printf("양의 정수를 입력하세요 : ");
    scanf("%d",&num);
    } while(num<=0);

    while(num > 0){
        num = num/10;
        count++;
    }

    printf("그 수는 %d자리입니다.",count);
}