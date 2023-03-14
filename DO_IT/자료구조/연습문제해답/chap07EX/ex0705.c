// 연습 7-5　문자열에서 문자를 검색
#include <stdio.h>

/*--- 문자열 s에서 문자 c를 검색 ---*/
char *str_chr(const char *s, int c)
{
    c = (char)c;
    while (*s != c) {
        if (*s == '\0')             // 검색 실패
            return NULL;
        s++;
    }
    return (char *)s;
}

int main(void)
{
    char str[64];               // 이 문자열에서 검색
    char tmp[64];
    int  ch;                    // 검색할 문자
    char *idx;

    printf("문자열: ");
    scanf("%s", str);

    printf("검색할 문자: ");
    scanf("%s", tmp);           // 먼저 문자열로 검색할 문자를 읽음
    ch = tmp[0];                // 첫 번째 문자를 검색할 문자로 지정

    if ((idx = str_chr(str, ch)) == -1)             // 처음 나오는 문자를 검색
        printf("문자 '%c'은(는) 문자열中에 없습니다.\n", ch);
    else
        printf("문자 '%c'은(는) %d번째에 있습니다.\n", ch, (idx - str) + 1);

    return 0;
}
