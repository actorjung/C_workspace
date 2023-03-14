// 연습 6-20　힙 정렬(정렬 과정을 트리 형식으로 출력)
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- 2의 n승을 반환 ---*/
static int pow2(int n)
{
    int k = 1;

    while (n--)
        k *= 2;
    return (k);
}

/*--- 힙을 출력 ---*/
static void disp_heap(int a[], int n)
{
    int i, w, level;
    int height = 1;     // 트리의 높이

    i = n;
    while (i /= 2)
        height++;

    i = 0;
    w = 1;
    for (level = 0; level < height; level++) {
        int k;
        printf("%*s", pow2(height - level) - 2 , "");
        for (k = 0; k < w; k++) {
            printf("%02d", a[i++]);
            if (i >= n) goto Exit;
            printf("%*s", pow2(height - level + 1) - 2, "");
        }
        putchar('\n');

        printf("%*s", pow2(height - level) - 3 , "");
        for (k = 0; k < w; k++) {
            if (2 * k + i     < n) printf("／");
            if (2 * k + i + 1 < n) printf("＼");
            printf("%*s", pow2(height - level + 1) - 4, "");
        }
        putchar('\n');
        w *= 2;
    }
Exit:
    putchar('\n');
    putchar('\n');
}

/*--- a[left] ~ a[right]를 힙으로 만들기 ---*/
static void downheap(int a[], int left, int right)
{
    int temp = a[left];             // 루트
    int child;
    int parent;

    for (parent = left; parent < (right + 1) / 2; parent = child) {
        int cl = parent * 2 + 1;    // 왼쪽 자식
        int cr = cl + 1;            // 오른쪽 자식
        child = (cr <= right && a[cr] > a[cl]) ? cr : cl;   // 큰 값을 선택
        if (temp >= a[child])
            break;
        a[parent] = a[child];
    }
    a[parent] = temp;
}

/*--- 힙 정렬(정렬 과정을 트리 형식으로 출력)---*/
void heapsort(int a[], int n)
{
    int i;

    puts("배열로 힙을 만듭니다.\n");
    for (i = (n - 1) / 2; i >= 0; i--) {
        disp_heap(a, n);
        downheap(a, i, n - 1);
    }

    puts("힙을 바탕으로 정렬합니다.\n");
    for (i = n - 1; i > 0; i--) {
        swap(int, a[0], a[i]);
        disp_heap(a, n);
        downheap(a, 0, i - 1);
    }
}

int main(void)
{
    int nx;

    puts("힙 정렬");
    printf("요소 개수: ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));   // 요소 개수가 nx인 int형 배열 x를 생성

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    heapsort(x, nx);    // 배열 x를 힙 정렬

    puts("오름차순으로 정렬했습니다.");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);            // 배열 x를 해제

    return 0;
}
