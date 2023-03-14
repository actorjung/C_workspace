// 연습4-6 int형 디큐 IntDequeue를 사용하는 프로그램
#include <stdio.h>
#include "IntDequeue.h"

int main(void)
{
    IntDequeue que;

    if (Initialize(&que, 64) == -1) {
        puts("큐의 생성에 실패했습니다.");
        return 1;
    }

    while (1) {
        int m, x;
        int idx;

        printf("현재 데이터 수:%d/%d\n", Size(&que), Capacity(&que));
        printf("(1)맨 앞에 인큐 (2)맨 앞에서부터 디큐 (3)맨 앞에서부터 피크 (4)출력\n"
               "(5)맨 뒤에 인큐 (6)맨 뒤에서부터 디큐 (7)맨 뒤에서부터 피크 (8)검색\n"
               "(9)클리어          (10)비어 있는지 판정       (0) 종료: ");
        scanf("%d", &m);

        if (m == 0) break;

        switch (m) {
         case 1: /*--- 맨 앞에 인큐 ---*/
                 printf("데이터: ");   scanf("%d", &x);
                 if (EnqueFront(&que, x) == -1)
                    puts("\a오류: 인큐에 실패했습니다.");
                 break;

         case 2: /*--- 맨 앞에서부터 디큐 ---*/
                 if (DequeFront(&que, &x) == -1)
                    puts("\a오류: 디큐에 실패했습니다.");
                 else
                    printf("디큐 데이터는 %d입니다.\n", x);
                 break;

         case 3: /*--- 맨 앞에서부터 피크 ---*/
                 if (PeekFront(&que, &x) == -1)
                    puts("\a오류: 피크에 실패했습니다.");
                 else
                    printf("피크 데이터는 %d입니다.\n", x);
                 break;

         case 4: /*--- 출력 ---*/
                 Print(&que);
                 break;

         case 5: /*--- 맨 뒤에 인큐 ---*/
                 printf("데이터: ");   scanf("%d", &x);
                 if (EnqueRear(&que, x) == -1)
                    puts("\a오류: 인큐에 실패했습니다.");
                 break;

         case 6: /*--- 맨 뒤에서부터 디큐 ---*/
                 if (DequeRear(&que, &x) == -1)
                    puts("\a오류: 디큐에 실패했습니다.");
                 else
                    printf("디큐 데이터는 %d입니다.\n", x);
                 break;

         case 7: /*--- 맨 뒤에서부터 피크 ---*/
                 if (PeekRear(&que, &x) == -1)
                    puts("\a오류: 피크에 실패했습니다.");
                 else
                    printf("피크 데이터는 %d입니다.\n", x);
                 break;

         case 8: /*--- 검색 ---*/
                 printf("검색할 데이터: ");
                 scanf("%d", &x);
                 if ((idx = Search(&que, x)) == -1)
                    puts("\a오류: 검색에 실패했습니다.");
                 else {
                     printf("그 데이터는 인덱스%d의 위치에 있습니다.\n", idx);
                     printf("큐의 맨 앞 요소로부터 %d개 뒤의 위치입니다.\n", Search2(&que, x));
                 }
                 break;

         case 9: /*--- 클리어 ---*/
                 Clear(&que);
                 break;

         case 10: /*--- 비어 있는지 판정 ---*/
                 printf("큐가 %s。\n",   IsEmpty(&que) ? "비어 있습니다" : "비어 있지 않습니다");
                 printf("큐가 %s。\n", IsFull(&que)  ? "가득 찼습니다" : "가득 차지 않았습니다");
                 break;
        }
    }

    Terminate(&que);

    return 0;
}
