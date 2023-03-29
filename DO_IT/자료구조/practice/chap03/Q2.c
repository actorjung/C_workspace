// 선형 검색(보초법) 선형 검색의 스캐닝 과정을 상세하게 표시하는 프로그램을 작성하세요. 이때 각 행의 맨 왼쪽에 현재 검색하는 요소의 인덱스를 표시하고, 현재 검색하고 있는 요소위에 별표 기호 *를 표시하세요
#include <stdio.h>
#include <stdlib.h>

/*--- 요소의 개수가 n인 배열 a에서 key와 일치하는 요소를 선형 검색(보초법) ---*/
int search(int a[], int n, int key)
{
    int i;
    a[n] = key;    // 보초를 추가
    printf("  |");
    for(int j=0;j<n;j++){
        printf("%3d",j);
    }
    puts("");
    printf("--+");
    for(int j = 0; j<=n; j++){
        printf("---");    
    }
    puts("");

    for(i =0; i<n; i++){
        printf("  |");
        printf("%*s",2+3*(i),""); //갯수만큼 ""공백문자 추가.
        printf("*\n");
        printf("%2d|",i);
    for(int j =0; j<n; j++){
        printf("%3d",a[j]);
    }
        puts("");
        printf("  |");
        puts("");
        if(a[i]==key)
            break;
    }
    return i == n ? -1 : i;
}

int main(void)
{
    int nx, ky;

    puts("선형 검색(보초법)");
    printf("요소 개수: ");
    scanf("%d", &nx);
    int *x = calloc(nx + 1, sizeof(int));   // 요소의 개수가 (nx + 1)인 int형 배열을 생성
    for (int i = 0; i < nx; i++) {          // 주의: 값을 읽은 것은 nx개
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }
    printf("검색값 : ");
    scanf("%d", &ky);
    int idx = search(x, nx, ky);            // 배열 x에서 값이 ky인 요소를 선형 검색
    if (idx == -1)
        puts("검색에 실패했습습니다.。");
    else
        printf("%d은 x[%d]에 존재합니다。\n", ky, idx);
    free(x);                                // 배열 x를 해제

    return 0;
}
