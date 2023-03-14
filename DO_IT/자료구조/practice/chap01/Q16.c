// 직각 이등변 삼각형을 출력하는 부분을 아래와 같은 형식의 함수로 작성하세요
#include<stdio.h>

void triangleLB(int n){
    for(int i=1; i<=n;i++){
        for(int j=1;j<=i;j++){
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
}

void triangleLU(int n){
    for(int i=1; i<=n;i++){
        for(int j=n;j>=i;j--){
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
}

void triangleRU(int n){
    for(int i=1; i<=n;i++){
        for(int j =1; j<=i-1; j++){
            printf(" ");
        }
        for(int j=1; j<=n-i+1; j++){
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
}

void triangleRB(int n){
    for(int i=1; i<=n;i++){
        for(int j=1; j<=n-i; j++){
            printf(" ");
        }
        for(int j=1; j<=i; j++){
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
}

int main(){
    int num=0;
    puts("직각이등변삼각형을 출력합니다.");
    printf("단수 : ");
    scanf("%d",&num);
    triangleLB(num);
    triangleLU(num);
    triangleRU(num);
    triangleRB(num);
    return 0;
}