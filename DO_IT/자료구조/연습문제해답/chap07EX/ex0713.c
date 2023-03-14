// 연습 7-13　strstr 함수와 같은 기능을 하는 함수
#include <stdio.h>
#include <string.h>

/*--- strstr 함수와 같은 기능을 하는 str_str 함수 ---*/
char *str_str(const char *s1, const char *s2)
{
    const char *p1 = s1;
    const char *p2 = s2;

    while (*p1 && *p2) {
        if (*p1 == *p2) {
            p1++;
            p2++;
        } else {
            p1 -= p2 - s2 - 1;
            p2 = s2;
        }
    }
    return *p2 ? NULL : (char *)(p1 - (p2 - s2));
}

int main(void)
{
    char s1[256], s2[256];

    puts("str_str 함수");

    printf("텍스트: ");
    scanf("%s", s1);

    printf("패턴: ");
    scanf("%s", s2);

    char *p = str_str(s1, s2);      // 문자열 s1에서 문자열 s2를 검색

    if (p == NULL)
        printf("텍스트에 패턴이 없습니다.\n");
    else {
        int ofs = p - s1;
        printf("\n%s\n",  s1);
        printf("%*s|\n",  ofs, "");
        printf("%*s%s\n", ofs, "", s2);
    }

    return 0;
}