// 연습 7-2　포인터값을 교환
#include <stdio.h>

/*--- type형 x와 y의 값을 교환 ---*/
#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

int main(void)
{
    char *s1 = "ABCD";      // s1은 "ABCD"의 첫 글자 'A'를 가리킴
    char *s2 = "EFGH";      // s2는 "EFGH"의 첫 글자 'E'를 가리킴

    printf("포인터 s1은 \"%s\"를 가리킵니다.\n", s1);
    printf("포인터 s2은 \"%s\"를 가리킵니다.\n", s2);

    swap(char*, s1, s2);

    puts("\n포인터 s1과 s2의 값을 서로 교환했습니다.\n");

    printf("포인터 s1은 \"%s\"를 가리킵니다.\n", s1);
    printf("포인터 s2은 \"%s\"를 가리킵니다.\n", s2);

    return 0;
}
