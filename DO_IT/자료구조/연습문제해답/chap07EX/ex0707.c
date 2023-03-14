// 연습 7-7　strncmp 함수와 동등한(같은 동작을 하는) 함수로 문자열 비교
#include <stdio.h>
#include <string.h>

/*--- strncmp 함수와 같은 동작을 하는 함수 ---*/
int str_ncmp(const char *s1, const char *s2, size_t n)
{
    while (n && *s1 && *s2) {
        if (*s1 != *s2)         // 같지 않음
            return (unsigned char)*s1 - (unsigned char)*s2;
        s1++;
        s2++;
        n--;
    }
    if (!n)  return 0;
    if (*s1) return 1;
    return -1;
}

int main(void)
{
    char st[128];

    puts("\"STRING\"의 처음 3개의 문자와 비교합니다");
    puts("\"XXXX\"면 종료합니다.");

    while (1) {
        printf("문자열 st：");
        scanf("%s", st);

        if (str_ncmp("XXXX", st, 3) == 0)
            break;
        printf("str_ncmp(\"STRING\", st, 3) = %d\n", str_ncmp("STRING", st, 3));
    }

    return 0;
}
