// 연습 7-1　문자열 끝의 널 문자 다음 요소에 문자를 대입
#include <stdio.h>

int main(void)
{
    char st[8];

    st[0] = 'A';
    st[1] = 'B';
    st[2] = 'C';
    st[3] = 'D';
    st[4] = '\0';

    // st[5] 이후에 문자를 대입해도 문자열에는 무관
    st[5] = 'E';
    st[6] = 'F';
    st[7] = 'G';

    // 따라서, 반드시 "ABCD"로 출력됨
    printf("문자열 st에는 \"%s\"가 저장되어 있습니다.\n", st);

    return 0;
}
