//아래를 향한 n단의 숫자 피라미드를 출력하는 함수를 작성하세요.
#include<stdio.h>

void nrpira(int n){
     for(int i=1;i<=n;i++){
        for(int j=1;j<=i-1;j++){
            printf(" ");
        }   
        for(int j=1; j<=2*n-2*(i-1)-1;j++){
            printf("%d",i);
        }
        for(int j=1; j<=i-1; j++){
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
    nrpira(num);
    return 0;
}