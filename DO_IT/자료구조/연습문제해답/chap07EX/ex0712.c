// 연습 7-12　보이어-무어법으로 문자열 검색(검색 과정을 자세히 출력)
#include <stdio.h>
#include <string.h>
#include <limits.h>

/*--- 표시 ---*/
int _print(const char txt[], const char pat[], int txt_len, int pat_len, int pt, int pp)
{
    if (pp != pat_len - 1)
        printf("    ");
    else
        printf("%2d  ", pt - pp);

    for (int i = 0; i < txt_len; i++)
        printf("%c ", txt[i]);
    putchar('\n');

    printf("%*s%c\n", pt*2+4, "", (txt[pt] == pat[pp]) ? '+' : '|');

    printf("%*s", (pt-pp)*2+4, "");
    for (int i = 0; i < pat_len; i++)
        printf("%c ", pat[i]);
    printf("\n\n");
}

/*--- 보이어-무어법으로 문자열 검색(검색 과정을 자세히 출력)---*/
int bm_match(const char txt[], const char pat[])
{
    int pt;                         // txt 커서
    int pp;                         // pat 커서
    int txt_len = strlen(txt);      // txt 문자 수
    int pat_len = strlen(pat);      // pat 문자 수
    int skip[UCHAR_MAX + 1];        // 건너뛰기 표

    for (pt = 0; pt <= UCHAR_MAX; pt++)     // 건너뛰기 표 작성
        skip[pt] = pat_len;
    for (pt = 0; pt < pat_len - 1; pt++)
        skip[pat[pt]] = pat_len - pt - 1;
                                            // pt == pat_len - 1
    while (pt < txt_len) {
        pp = pat_len - 1;                   // pat의 마지막 문자부터 검사

        while (_print(txt, pat, txt_len, pat_len, pt, pp), txt[pt] == pat[pp]) {
            if (pp == 0)
                return pt;
            pp--;
            pt--;
        }
        pt += (skip[txt[pt]] > pat_len - pp) ? skip[txt[pt]] : pat_len - pp;
    }

    return -1;
}

int main(void)
{
    char s1[256];       // 텍스트
    char s2[256];       // 패턴

    puts("보이어-무어법");

    printf("텍스트: ");
    scanf("%s", s1);

    printf("패턴: ");
    scanf("%s", s2);

    int idx = bm_match(s1, s2);     // 문자열 s1에서 문자열 s2를 보이어-무어법으로 검색

    if (idx == -1)
        puts("텍스트에 패턴이 없습니다.");
    else
        printf("%d번째 문자부터 match합니다.\n", idx + 1);

    return 0;
}
