//곱셈이 아니라 덧셈을 출력하는 프로그램을 작성하세요.
#include<stdio.h>
int main(){
    printf("   |");
    for(int i=1; i<=9; i++)
        printf("%3d",i);
    printf("\n---+-----------------------------\n");
    for (int i = 1; i <= 9; i++){
        printf("%2d |",i,i);
        for (int j = 1; j <= 9; j++)
            printf("%3d", i+j);
        putchar('\n');
    }
    return 0;
}