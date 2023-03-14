// 문자열을 배열로 저장해서 출력
#include <stdio.h>

int main(void)
{
    char st[8];
    st[0] = 'A';
    st[1] = 'B';
    st[2] = 'C';
    st[3] = 'D';
    st[4] = '\0';
    printf("문자열 st에는 \"%s\"가 들어 있습니다.\n", st);

    return 0;
}
