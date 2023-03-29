// 날짜를 나타내는 구조체
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
    
    Date temp;

    temp.y = y;
    temp.m = m;
    temp.d = d;
    
    return temp;
}

/*--- 날짜 x의 n일 뒤의 날짜를 반환하는 함수---*/
Date After(Date x, int n){
    
    
}

/*--- 날짜 x의 n일 앞의 날짜를 반환하는 함수 ---*/
Date Before(Date x, int n){



}

int main(void)
{   
    puts("날짜를 입력하세요.");
    int year=0, month=0, day=0;       // 년, 월, 일
    int number; // 날짜
    printf("년: ");   scanf("%d", &year);
    printf("월: ");   scanf("%d", &month);
    printf("일: ");   scanf("%d", &day);
    
    Date x = DateOf(year,month,day);
    
    puts("현재 날짜로 부터 n일 전의 날짜와 n일 후의 날짜를 알려드립니다.");
    printf("현재 날짜 : %d년 %d월 %d일\n",x.y,x.m,x.d);
    printf("n을 입력하세요 : ");
    scanf("%d",&number);

    


    return 0;
}
