// 문자열 안의 문자를 16진수와 2진수로 출력
#include <stdio.h>
#include <limits.h>

/*--- 문자열 s 안의 문자를 16진수와 2진수로 출력하는 함수 ---*/
void str_dump(const char *s)
{
    for ( ; *s != '\0'; s++) {
        printf("%c  %0*X  ", *s, (CHAR_BIT + 3) / 4, *s);
        for (int i = CHAR_BIT - 1; i >= 0; i--)
            putchar(((*s >> i) & 1U) ? '1' : '0');
        putchar('\n');
    }
}

int main(void)
{
    str_dump("STRING");
    return 0;
}
