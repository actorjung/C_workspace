// 연습4-1 int형 스택 IntStack의 사용
#include <stdio.h>
#include "IntStack.h"

int main(void)
{
    IntStack s;

    if (Initialize(&s, 64) == -1) {
        puts("스택 생성에 실패했습니다.");
        return 1;
    }

    while (1) {
        int menu, x;
        int idx;

        printf("현재 데이터 수:%d / %d\n", Size(&s), Capacity(&s));
        printf("(1)푸시 (2)팝 (3)피크 (4)출력 (5)검색 (6) 클리어 (7) 비었는지 판정 (0) 종료: ");
        scanf("%d", &menu);

        if (menu == 0) break;

        switch (menu) {
         case 1: /*--- 푸시 ---*/
                 printf("데이터: ");
                 scanf("%d", &x);
                 if (Push(&s, x) == -1)
                    puts("\a오류: 푸시에 실패했습니다.");
                 break;

         case 2: /*--- 팝 ---*/
                 if (Pop(&s, &x) == -1)
                    puts("\a오류: 팝에 실패했습니다.");
                 else
                    printf("팝 데이터는 %d입니다.\n", x);
                 break;

         case 3: /*--- 피크 ---*/
                 if (Peek(&s, &x) == -1)
                    puts("\a오류: 피크에 실패했습니다.");
                 else
                    printf("피크 데이터는 %d입니다.\n", x);
                 break;

         case 4: /*--- 출력 ---*/
                 Print(&s);
                 break;

         case 5: /*--- 검색 ---*/
                 printf("검색할 데이터: ");
                 scanf("%d", &x);
                 if ((idx = Search(&s, x)) == -1)
                    puts("\a오류: 검색에 실패했습니다.");
                 else
                     printf("그 데이터는 인덱스%d의 위치에 있습니다.\n", idx);
                 break;

         case 6: /*--- 클리어 ---*/
                 Clear(&s);
                 break;

         case 7: /*--- 비어있는지 판정 ---*/
                 printf("스택은 %s。\n",   IsEmpty(&s) ? "비어 있습니다" : "비어 있지 않습니다");
                 printf("스택은 %s。\n", IsFull(&s)  ? "가득 찼습니다" : "가득 차지 않았습니다");
                 break;
        }
    }

    Terminate(&s);

    return 0;
}
