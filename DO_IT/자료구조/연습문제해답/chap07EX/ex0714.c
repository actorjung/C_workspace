// 연습 7-14　strstr 함수와 같은 기능을 하는 함수(단, 일치한 가장 끝 문자에 대한 포인터를 반환)
#include <stdio.h>
#include <string.h>

/*--- strstr 함수와 같은 기능을 하는 함수(단, 일치한 가장 끝 문자에 대한 포인터를 반환) ---*/
char *str_rstr(const char *s1, const char *s2)
{
    int s1_len = strlen(s1);        // txt 문자 수
    int s2_len = strlen(s2);        // pat 문자 수
    int pt = s1_len - s2_len;       // txt 커서
    int pp;                         // pat 커서

    while (pt >= 0) {
        pp = 0;
        while (s1[pt] == s2[pp]) {
            if (pp == s2_len - 1)
                return &s1[pt - pp];
            pp++;
            pt++;
        }
        pt = pt - pp - 1;
    }

    return NULL;
}

int main(void)
{
    char s1[256], s2[256];

    puts("strstr 함수");

    printf("텍스트: ");
    scanf("%s", s1);

    printf("패턴: ");
    scanf("%s", s2);

    char *p = str_rstr(s1, s2);     // 문자열 s1에서 문자열 s2를 끝에서부터 검색

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