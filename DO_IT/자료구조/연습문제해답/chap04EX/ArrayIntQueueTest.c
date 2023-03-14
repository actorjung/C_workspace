// 연습4-3 int형 큐 ArrayIntQueue를 사용하는 프로그램
#include <stdio.h>
#include "ArrayIntQueue.h"

int main(void)
{
    ArrayIntQueue que;

    if (Initialize(&que, 64) == -1) {
        puts("큐의 생성에 실패했습니다.");
        return 1;
    }

    while (1) {
        int m, x;
        int idx;

        printf("현재 데이터 수:%d / %d\n", Size(&que), Capacity(&que));
        printf("(1)인큐 (2)디큐 (3)피크 (4)출력 (5)검색 (6)클리어 (7)비어 있는지 판정 (0) 종료: ");
        scanf("%d", &m);

        if (m == 0) break;

        switch (m) {
         case 1: /*--- 인큐 ---*/
                 printf("데이터: ");   scanf("%d", &x);
                 if (Enque(&que, x) == -1)
                    puts("\a오류: 인큐에 실패했습니다.");
                 break;

         case 2: /*--- 디큐 ---*/
                 if (Deque(&que, &x) == -1)
                    puts("\a오류: 디큐에 실패했습니다.");
                 else
                    printf("디큐한 데이터는 %d입니다.\n", x);
                 break;

         case 3: /*--- 피크 ---*/
                 if (Peek(&que, &x) == -1)
                    puts("\a오류: 피크에 실패했습니다.");
                 else
                    printf("피크한 데이터는 %d입니다.\n", x);
                 break;

         case 4: /*--- 출력 ---*/
                 Print(&que);
                 break;

         case 5: /*--- 검색 ---*/
                 printf("검색할 데이터: ");
                 scanf("%d", &x);
                 if ((idx = Search(&que, x)) == -1)
                    puts("\a오류: 검색에 실패했습니다.");
                 else
                     printf("그 데이터는 인덱스%d의 위치에 있습니다.\n", idx);
                 break;

         case 6: /*--- 클리어 ---*/
                 Clear(&que);
                 break;

         case 7: /*--- 비어 있는지 판정 ---*/
                 printf("스택은 %s。\n",   IsEmpty(&que) ? "비어 있습니다" : "비어 있지 않습니다");
                 printf("스택은 %s。\n", IsFull(&que)  ? "가득 찼습니다" : "가득 차지 않았습니다");
                 break;
        }
    }

    Terminate(&que);

    return 0;
}
