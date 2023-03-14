//입력한 수를 한 변으로 하는 정사각형을 *기호로 출력하는 프로그램을 작성하세요.
#include<stdio.h>
int main(){
    int num = 0;
    puts("정사각형을 출력합니다.");
    printf("입력할 수:");
    scanf("%d",&num);

    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++)
            printf("*");
        printf("\n");
    }   
}