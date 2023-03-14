// 연습 7-4　문자열의 길이를 구해서 출력(버전 3)
#include <stdio.h>

/*
이 프로그램(버전 3)의 str_len 함수가 반환하는 값은, 포인터를 서로 감산한 s-p의 연산 결과입니다.
이 연산에 의해 생성되는 것은 부호 있는 정수형인 ptrdiff_t형입니다.
한편, 함수가 반환하는 size_t형은 부호 없는 정수형입니다. 
양쪽이 서로 표현 가능한 값의 범위는 다르므로 불편할 수 있습니다.
따라서 버전 1이나 버전 2가 더 낫다고 할 수 있습니다

*/

/*--- 문자열의 길이를 반환(버전 3) ---*/
size_t str_len(const char *s)
{
    const char *p = s;

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
