// 연습 7-6　문자열에서 문자를 검색(맨 뒤에서부터 검색)
#include <stdio.h>

/*--- 문자열 s에서 문자 c를 맨 뒤에서부터 검색 ---*/
char *str_rchr(const char *s, int c)
{
    const char *p = NULL;           // 출현 위치

    c = (char)c;
    while (1) {
        if (*s == c)                // 발견
            p = s;
        if (*s == '\0')             // 스캔 종료
            break;
        s++;
    }
    return (char *)p;
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

    if ((idx = str_rchr(str, ch)) == NULL)          // 마지막에 나오는 문자를 검색
        printf("문자 '%c'은(는) 문자열에 없습니다.\n", ch);
    else
        printf("문자 '%c'은(는) %d번째에 있습니다.\n", ch, (idx - str) + 1);

    return 0;
}
