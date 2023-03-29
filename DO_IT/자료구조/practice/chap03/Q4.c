/*오른쪽처럼 이진 검색의 과정을 자세히 출력하는 프로그램을 작성하세요.
각 행의 맨 왼쪽에 현재 검색하고 있는 요소의 인덱스를 출력하고, 검색 범위의 맨 앞 요소 위에 <-,
맨 끝 요소위에 ->, 현재 검색하고 있는 중앙요소 위에 +를 출력하세요.*/

#include <stdio.h>
#include <stdlib.h>

/*--- 요소의 개수가 n인 배열 a에서 key와 일치하는 요소를 이진 검색 ---*/
int bin_search(const int a[], int n, int key)
{
    printf("   |");
    for(int j=0;j<n;j++){
        printf("%3d",j);   
    }
    puts("");
    printf("---+");
    for(int j=0;j<=n;j++){
        printf("---");
    }
    puts("");
    
    int pl = 0;                     // 검색 범위 맨 앞의 인덱스
    int pr = n - 1;                 // 검색 범위 맨 끝의 인덱스

    do {
        int pc = (pl + pr) / 2;     // 검색 범위 한가운데의 인덱스
        if (a[pc] == key){          // 검색 성공
            printf("   |");
            printf("%*s",1+pl*3,"");
            printf("<-");
            printf("%*s",2+(pc-1)*3,"");
            printf("+");
            printf("%*s",1+(pc-1)*3,"");
            printf("->");
            puts("");
            printf("%3d|",pc);
            for(int j=0;j<n;j++){
                printf("%3d",a[j]);
            }
            puts("");
            return pc;
        }
        else if (a[pc] < key)
            pl = pc + 1;            // 검색 범위를 뒤쪽 절반으로 좁힘
        else
            pr = pc - 1;            // 검색 범위를 앞쪽 절반으로 좁힘
        
        printf("   |");
        printf("%*s",1+pl*3,"");
        printf("<-");
        printf("%*s",2+(pc-1)*3,"");
        printf("+");
        printf("%*s",1+(pc-1)*3,"");
        printf("->");
        puts("");
        printf("%3d|",pc);
        for(int j=0;j<n;j++){
            printf("%3d",a[j]);
        }
        puts("");
        printf("   |\n");

    } while (pl <= pr);
    return -1;                      // 검색 실패
}

int main(void)
{
    int nx, ky;

    puts("이진 검색");
    printf("요소 개수: ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));   // 요소 개수가 nx인 int형 배열 x 생성
    printf("오름차순으로 입력하세요.\n");
    printf("x[0] : ");
    scanf("%d", &x[0]);
    for (int i = 1; i < nx; i++) {
        do {
            printf("x[%d] : ", i);
            scanf("%d", &x[i]);
        } while (x[i] < x[i - 1]);      // 바로 앞의 값보다 작으면 다시 입력
    }
    printf("검색값: ");
    scanf("%d", &ky);
    int idx = bin_search(x, nx, ky);    // 배열 x에서 값이 ky인 요소를 이진 검색
    if (idx == -1)
        puts("검색에 실패했습니다.");
    else
        printf("%d는(은) x[%d]에 있습니다.\n", ky, idx);
    free(x);                            // 배열 x를 해제

    return 0;
}