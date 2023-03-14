// 연습2-10　한 해의 지난 날 수를 출력(while 문)
#include <stdio.h>

/*- 각 달의 날 수 -*/
int mdays[][12] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

/*--- year년이 윤년인가? ---*/
int isleap(int year)
{
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

/*--- y년 m월 d일의 그 해 지난 날 수를 구해서 반환 ---*/
int dayof_year(int y, int m, int d)
{
    while (--m)
        d += mdays[isleap(y)][m-1];
    return (d);
}

int main(void)
{
    int retry;      // 다시?

    do {
        int year, month, day;       // 년, 월, 일
        printf("년: ");   scanf("%d", &year);
        printf("월: ");   scanf("%d", &month);
        printf("일: ");   scanf("%d", &day);

        printf("한 해의 %d일째입니다.\n", dayof_year(year, month, day));

        printf("다시 할까요?(1 … 예 / 0 … 아니오): ");
        scanf("%d", &retry);
    } while (retry == 1);

    return 0;
}
