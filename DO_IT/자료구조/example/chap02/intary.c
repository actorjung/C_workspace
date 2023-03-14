// int[5]형 배열(자료형이 int형이고 요소가 5개)에 값을 입력해 출력
#include <stdio.h>

#define N   5                       // 배열의 요소 개수
int main()
{
    int a[N];                       // 배열의 선언
    for (int i = 0; i < N; i++) {   // 각 요소에 값을 입력
        printf("a[%d] : ", i);
        scanf("%d", &a[i]);
    }
    puts("각 요소의 값");
    for (int i = 0; i < N; i++) {   // 각 요소의 값을 출력
        printf("a[%d] = %d\n", i, a[i]);
    }

    return 0;
}
