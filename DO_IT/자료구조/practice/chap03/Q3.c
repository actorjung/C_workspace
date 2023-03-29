/*요소의 개수가 n인 배열 a에서 key와 일ㅊ하는 모든 요소의 인덱스를 배열 idx의 맨 앞부터 순서대로 저장하고 
일치한 요소의 개수를 반환하는 함수를 작성하세요.
예를 들어, 요소의 개수가 8인 배열 a의 요소가 {1,9,2,9,4,6,7,9}이고 key가 9면 배열 idx에 {1,3,7}을 저장하고 3을 반환합니다.*/

#include <stdio.h>
#include <stdlib.h>

int search_idx(const int a[],int n, int key, int idx[]){
    int j=0;
    for(int i =0; i<n; i++){
        if(a[i]==key){
            idx[j] = i;
            j++;
        }
    }
    return j;
}


int main(void)
{
    int nx, ky;

    puts("선형 검색");
    printf("요소 개수: ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));
    int *y = calloc(nx, sizeof(int));    // 요소의 개수가 (nx)인 int형 배열을 생성
    for (int i = 0; i < nx; i++) {         
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }
    printf("검색값 : ");
    scanf("%d", &ky);
    int result = search_idx(x, nx, ky, y);          
    if (result == 0)
        puts("검색에 실패했습니다.。");
    else
        printf("%d은 %d개있습니다。\n", ky, result);
    free(x);                              
    free(y); 
    return 0;
}