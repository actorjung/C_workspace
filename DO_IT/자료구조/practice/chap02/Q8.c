//배열 b의 모든 요소를 배열 a에 역순으로 복사하는 함수를 작성하세요(n은 요소 개수입니다).
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

/*--- type형 x값과 y값을 교환 ---*/
#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

void ary_rcopy(int a[], const int b[], int n){
    for(int i=0; i<n; i++){
        a[i] = b[i];
    }
    for(int i=0; i<n/2; i++){
        swap(int, a[i], a[n-i-1]);
    }
}

int main(){
    puts("arr2배열의 요소를 arr1배열에 역순으로 복사합니다.");
    int number;
    srand(time(NULL));
    number = 3 + rand() % 6;
    int * arr1 = calloc(number, sizeof(int));
    int * arr2 = calloc(number, sizeof(int));
    for (int i = 0; i < number; i++) {
        arr2[i] = rand() % 100;          // ~100의 난수를 생성, 대입
        printf("arr2[%d] = %d\n", i, arr2[i]);
    }
    printf("arr2 : ");
    for (int i = 0; i < number; i++){
        printf("%d ",arr2[i]);
    }
    puts("");
    ary_rcopy(arr1,arr2,number);
    printf("arr1 : ");
    for (int i = 0; i < number; i++){
        printf("%d ",arr1[i]);
    }
    free(arr1); 
    free(arr2); 
    return 0;
}