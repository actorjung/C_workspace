// 위쪽과 왼쪽에 곱하는 수 있는 곱셈표를 출력하는 프로그램을 작성하시오.
#include<stdio.h>
int main(){
    printf("   |");
    for(int i=1; i<=9; i++)
        printf("%3d",i);
    printf("\n---+-----------------------------\n");
    for (int i = 1; i <= 9; i++){
        printf("%2d |",i,i);
        for (int j = 1; j <= 9; j++)
            printf("%3d", i*j);
        putchar('\n');
    }
    return 0;
}