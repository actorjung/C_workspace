// 문자열 s의 길이를 구하는 함수(버전 3)
#include <stdio.h>

/*--- 문자열 s의 길이를 구하는 함수(버전 3) ---*/
int str_len(const char* s)
{
    const char* p = s;
    while (*s)
        s++;
    return s - p;
}

int main(void)
{
    char str[256];
    printf("문자열: ");
    scanf("%s", str);
    printf("이 문자열의 길이는 %d입니다.\n", str_len(str));

    return 0;
}
