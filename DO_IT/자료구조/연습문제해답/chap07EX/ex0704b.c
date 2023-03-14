// 연습 7-4　문자열의 길이를 구해서 출력(버전 2)
#include <stdio.h>

/*--- 문자열의 길이를 구해서 반환(버전 2)---*/
size_t str_len(const char *s)
{
    size_t len = 0;

    while (*s++)
        len++;
    return len;
}

int main(void)
{
    char str[256];

    printf("문자열: ");
    scanf("%s", str);

    printf("이 문자열의 길이는 %d입니다.\n", str_len(str));

    return 0;
}
