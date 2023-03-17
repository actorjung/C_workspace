//배열 a의 모든 요소의 순서를 뒤섞는 shuffle 함수를 작성하세요(n은 요소 개수입니다).
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

/*--- type형 x값과 y값을 교환 ---*/
#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

void shuffle(int a[], int n){
    int r = 0;
    srand(time(NULL));
    for(int i =0;i<n;i++){
        r = rand() % n;
        swap(int,a[i],a[r]);
    }
}

int main(){
    puts("arr1배열을 무작위로 셔플합니다.");
    int number;
    srand(time(NULL));
    number = 3 + rand() % 6;
    int * arr1 = calloc(number, sizeof(int));
    for (int i = 0; i < number; i++) {
        arr1[i] = rand() % 100;          // ~100의 난수를 생성, 대입
        printf("arr1[%d] = %d\n", i, arr1[i]);
    }
    printf("원래배열 : ");
    for (int i = 0; i < number; i++){
        printf("%d ",arr1[i]);
    }
    puts("");
    shuffle(arr1,number);
    printf("shuffle후 배열 : ");
    for (int i = 0; i < number; i++){
        printf("%d ",arr1[i]);
    }
    free(arr1); 
    return 0;
}