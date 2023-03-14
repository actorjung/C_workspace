// 연습2-6　정수를 2진수~36진수로 기수 변환(변환 과정을 출력)
#include <stdio.h>

/*--- type형 x값과 y값을 교환 ---*/
#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- 정수 x를 n진수로 변환하여 배열 d에 하위 자리부터 저장 ---*/
int card_conv(unsigned x, int n, char d[])
{
    char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int  digits = 0;                        // 변환 후 자릿수

    if (x == 0)                             // 0이면
        d[digits++] = dchar[0];             // 변환 후에도 0
    else {
        while (x) {
            printf("%2d  |%7d   … %c\n", n, x, dchar[x % n]);
            printf("    +----------\n");
            d[digits++] = dchar[x % n];     // n으로 나눈 나머지를 저장
            x /= n;
        }
        printf("       %5d\n", x);
    }

    for (int i = 0; i < digits / 2; i++)    // 배열 d를 역순으로 정렬
        swap(char, d[i], d[digits - i - 1]);

    return digits;
}

int main(void)
{
    puts("10진수를 기수 변환합니다.");

    int retry;              // 다시?

    do {
        unsigned no;        // 변환하는 정수
        int      cd;        // 기수
        char     cno[512];  // 변환한 값의 각 자리의 숫자를 저장하는 문자 배열 

        printf("변환하는 음이 아닌 정수: ");
        scanf("%u", &no);

        do {
            printf("어떤 진수로 변환할까요?(2-36): ");
            scanf("%d", &cd);
        } while (cd < 2 || cd > 36);

        int dno = card_conv(no, cd, cno);   // no를 dno자리의 cd진수로 변환

        printf("%d진수로는", cd);
        for (int i = 0; i < dno; i++)       // 각 자리의 문자를 차례로 출력
            printf("%c", cno[i]);
        printf("입니다.\n");

        printf("한 번 더 할까요?(1…예/0…아니오): ");
        scanf("%d", &retry);
    } while (retry == 1);

    return 0;
}
