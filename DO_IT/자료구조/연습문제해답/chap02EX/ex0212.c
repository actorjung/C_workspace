// 연습2-12　날짜를 나타내는 구조체
#include <stdio.h>

typedef struct {
    int y;  // 년
    int m;  // 월(1~12)
    int d;  // 일(1~31)
} Date;

Date Before(Date x, int n);
Date After( Date x, int n);

/*--- 각 달의 날 수 ---*/
static int  mdays[2][13] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},   // 평년
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},   // 윤년
};

/*--- year년이 윤년인가? ---*/
int isleap(int year)
{
    return year % 4 == 0  &&  year % 100 != 0  ||  year % 400 == 0;
}

/*--- y년 m월 d일을 나타내는 구조체를 반환하는 DateOf 함수 ---*/
Date DateOf(int y, int m, int d)
{
    Date temp;

    temp.y = y;
    temp.m = m;
    temp.d = d;

    return temp;
}

/*--- 날짜 x의 n일 뒤의 날짜를 반환하는 함수 ---*/
Date After(Date x, int n)
{
    if (n < 0)
        return Before(x, -n);

    x.d += n;

    while (x.d > mdays[isleap(x.y)][x.m - 1]) {
        x.d -= mdays[isleap(x.y)][x.m - 1];
        if (++x.m > 12) {
            x.y++;
            x.m = 1;
        }
    }
    return x;
}

/*--- 날짜 x의 n일 앞의 날짜를 반환하는 함수 ---*/
Date Before(Date x, int n)
{
    if (n < 0)
        return After(x, -n);

    x.d -= n;

    while (x.d < 1) {
        if (--x.m < 1) {
            x.y--;
            x.m = 12;
        }
        x.d += mdays[isleap(x.y)][x.m - 1];
    }

    return x;
}

/*--- 날짜를 표시 ---*/
int Print(Date x)
{
    int y = x.y;
    int m = x.m;
    int d = x.d;

    char *ws[] = {"일", "월", "화", "수", "목", "금", "토"};
    if (m == 1 || m == 2) {
        y--;
        m += 12;
    }
    printf("%04d년%02d월%02d일(%s)", x.y, x.m, x.d, 
                ws[(y + y/4 - y/100 + y/400 + (13*m+8)/5 + d) % 7]);
}

int main(void)
{
    int y, m, d;

    printf("날짜를 입력하세요.\n");
    printf("년: ");  scanf("%d", &y);
    printf("월: ");  scanf("%d", &m);
    printf("일: ");  scanf("%d", &d);

    Date x = DateOf(y, m, d);

    int n;

    printf("며칠 전/후의 날짜를 원합니까?: ");
    scanf("%d", &n);

    printf("%d일 후의 날짜: ", n);   Print(After(x, n));   putchar('\n');

    printf("%d일 전의 날짜: ", n);   Print(Before(x, n));  putchar('\n');

    return 0;
}
