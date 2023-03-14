//n단의 피라미드를 출력하는 함수를 작성하세요.
#include<stdio.h>
void spira(int n){
    for(int i =1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            printf(" ");
        }   
        for(int j=1; j<=2*i-1;j++){
            printf("*");
        }
        for(int j=1; j<=n-i; j++){
            printf(" ");
        }
        printf("\n");
    }
}

int main(){
    int num;
    puts("피라미드를 출력합니다.");
    printf("단 : ");
    scanf("%d",&num);
    spira(num);
    return 0;
}