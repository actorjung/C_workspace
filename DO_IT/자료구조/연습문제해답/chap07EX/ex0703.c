// 연습 7-3　두 문자열의 내용을 서로 교환
#include <stdio.h>

/*--- 두 문자열 x와 y를 서로 교환 ---*/
void swap_str(char *x, char *y)
{
    char *temp;
    while (*x && *y) {  // 짧은 쪽의 맨 끝까지 문자열을 교환
        char t = *x; *x++ = *y; *y++ = t;
    }
    if (*x) {                           // x 쪽이 길면
        temp = x;
        while (*x) { *y++ = *x++; }     // x의 나머지를 y로 복사
        *temp = *y = '\0';
    } else if (*y) {                    // y 쪽이 길면
        temp = y;
        while (*y) { *x++ = *y++; }     // y의 나머지를 x로 복사
        *temp = *x = '\0';
    } else {
        *x = *y = '\0';
    }
}

int main(void)
{
    char s1[128], s2[128];

    printf("문자열 s1: ");   scanf("%s", s1);
    printf("문자열 s2: ");   scanf("%s", s2);

    swap_str(s1, s2);   // s1과 s2를 교환

    printf("두 문자열을 교환합니다.\n");
    printf("문자열 s1：%s\n", s1);
    printf("문자열 s2：%s\n", s2);

    return 0;
}
