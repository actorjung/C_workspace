#include<stdio.h>
int fibonacci(int n);

int main(){
    int t;
    int a;
    int result0=0;
    int result1=0;
    scanf("%d",&t);
    for(int i =0;i<t;i++){
        scanf("%d",&a);
        if(fibonacci(a)==0)
            result0 += 1;
        else if(fibonacci(a)==1)
            result1 += 1;  
    }
    printf("%d %d",result0,result1);
    return 0;

}

int fibonacci(int n){
    if (n == 0) {
        printf("0");
        return 0;
    } else if (n == 1) {
        printf("1");
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n‐2);
    }
}