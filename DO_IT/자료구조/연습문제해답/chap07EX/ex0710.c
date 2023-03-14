// 연습 7-10　브루트-포스법으로 문자열을 검색(가장 뒤쪽의 인덱스를 검색)
#include <stdio.h>
#include <string.h>

/*--- 브루트-포스법으로 문자열을 검색(가장 뒤쪽의 인덱스를 검색) ---*/
int bf_matchr(const char txt[], const char pat[])
{
    int txt_len = strlen(txt);      // txt 문자 수
    int pat_len = strlen(pat);      // pat 문자 수
    int pt = txt_len - pat_len;     // txt 커서
    int pp;                         // pat 커서

    
    while (pt >= 0) {
        pp = 0;
        while (txt[pt] == pat[pp]) {
            if (pp == pat_len - 1)
                return pt - pp;
            pp++;
            pt++;
        }
        pt = pt - pp - 1;
    }

    return -1;
}

int main(void)
{
    char s1[256];       // 텍스트
    char s2[256];       // 패턴

    puts("브루트-포스법(가장 뒤쪽을 검색)");

    printf("텍스트: ");
    scanf("%s", s1);

    printf("패턴: ");
    scanf("%s", s2);

    int idx = bf_matchr(s1, s2);    // 문자열 s1에서 문자열 s2를 브루트-포스법으로 맨 뒤에서부터 검색

    if (idx == -1)
        puts("텍스트에 패턴이 없습니다.");
    else
        printf("%d번째 문자부터 match합니다.\n", idx + 1);

    return 0;
}
