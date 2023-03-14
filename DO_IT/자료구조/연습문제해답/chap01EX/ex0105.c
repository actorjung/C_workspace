// 연습1-5　세 정수의 중앙값 출력(모든 대소관계에 대해 확인)
#include <stdio.h>

/*
첫 if 문의 다음 판정에 주목합니다.
    if ((b >= a && c<= a) || (b <= a && c >= a)
여기서 b>=a 및 b<=a의 판정을 뒤집는 판정(실질적으로 동일한 판정)이, 뒤이은 else 이후에 다음과 같이 수행됩니다.
    else if ((a > b && c < b) || (a < b && c > b)
즉, 첫 번째 if 문이 성립되지 않은 경우, 두 번째 if 문에서도 (실질적으로) 같은 판정을 하므로 효율이 나빠집니다.
*/

/*--- a, b, c의 중앙값 반환 ---*/
int med3(int a, int b, int c)
{
    if ((b >= a && c <= a) || (b <= a && c >= a))
        return a;
    else if ((a > b && c < b) || (a < b && c > b))
        return b;
    return c;
}

int main(void)
{
    printf("med3(%d,%d,%d) = %d\n", 3, 2, 1, med3(3, 2, 1));    /* [A] a＞b＞c */
    printf("med3(%d,%d,%d) = %d\n", 3, 2, 2, med3(3, 2, 2));    /* [B] a＞b＝c */
    printf("med3(%d,%d,%d) = %d\n", 3, 1, 2, med3(3, 1, 2));    /* [C] a＞c＞b */
    printf("med3(%d,%d,%d) = %d\n", 3, 2, 3, med3(3, 2, 3));    /* [D] a＝c＞b */
    printf("med3(%d,%d,%d) = %d\n", 2, 1, 3, med3(2, 1, 3));    /* [E] c＞a＞b */
    printf("med3(%d,%d,%d) = %d\n", 3, 3, 2, med3(3, 3, 2));    /* [F] a＝b＞c */
    printf("med3(%d,%d,%d) = %d\n", 3, 3, 3, med3(3, 3, 3));    /* [G] a＝b＝c */
    printf("med3(%d,%d,%d) = %d\n", 2, 2, 3, med3(2, 2, 3));    /* [H] c＞a＝b */
    printf("med3(%d,%d,%d) = %d\n", 2, 3, 1, med3(2, 3, 1));    /* [I] b＞a＞c */
    printf("med3(%d,%d,%d) = %d\n", 2, 3, 2, med3(2, 3, 2));    /* [J] b＞a＝c */
    printf("med3(%d,%d,%d) = %d\n", 1, 3, 2, med3(1, 3, 2));    /* [K] b＞c＞a */
    printf("med3(%d,%d,%d) = %d\n", 2, 3, 3, med3(2, 3, 3));    /* [L] b＝c＞a */
    printf("med3(%d,%d,%d) = %d\n", 1, 2, 3, med3(1, 2, 3));    /* [M] c＞b＞a */

    return 0;
}
