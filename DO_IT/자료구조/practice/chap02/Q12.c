// 한 해의 지난 날 수를 구하여 출력
#include <stdio.h>

typedef struct {
    int y;  //년
    int m;  //월(1~12)
    int d;  //일(1~31)
} Date;

/*- 각 달의 날 수 -*/
int mdays[][12] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, //윤년인 경우
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, //윤년이 아닌경우
};

/*--- year년이 윤년인가? ---*/
int isleap(int year)
{
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

/*--- y년 m월 d일을 나타내는 구조체를 반환하는 함수 ---*/
Date DateOf(int y, int m, int d){
    printf("%d년 %d월 %d일\n",y,m,d);
}

/*--- 날짜 x의 n일 뒤의 날짜를 반환하는 함수---*/
Date After(Date x, int n){

    
}

/*--- 날짜 x의 n일 앞의 날짜를 반환하는 함수 ---*/
Date Before(Date x, int n){



}

int main(void)
{
    Date x[] = {};
    //int year, month, day;       // 년, 월, 일
    printf("년: ");   scanf("%d", &x.y);
    printf("월: ");   scanf("%d", &x.m);
    printf("일: ");   scanf("%d", &x.d);
    //
    DateOf(x.y, x.m, x.d);
    //
    //


    return 0;
}
