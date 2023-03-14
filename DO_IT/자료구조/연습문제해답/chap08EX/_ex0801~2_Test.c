// 연습 8-1 ~ 연습 8-2 선형 리스트를 사용한 프로그램
#include <stdio.h>
#include "Member.h"
#include "LinkedList.h"

/*--- 메뉴 ---*/
typedef enum {
    TERMINATE, INS_FRONT,  INS_REAR,  RMV_FRONT, RMV_REAR, PRINT_CRNT,
    RMV_CRNT,  SRCH_NO,    SRCH_NAME, PRINT_ALL, CLEAR,
    PURGE_NO,  PURGE_NAME, RETRIEVE,
} Menu;

/*--- 메뉴 선택 ---*/
Menu SelectMenu(void)
{
    int ch;
    char *mstring[] = {
        "머리에 노드를 삽입", "꼬리에 노드를 삽입",   "머리 노드를 삭제",
        "꼬리 노드를 삭제",  "선택한 노드를 출력",     "선택한 노드를 삭제",
        "번호로 검색",      "이름으로 검색",       "모든 노드를 출력",
        "모든 노드를 삭제",  "번호가 같은 노드 삭제",   "이름이 같은 노드 삭제",
        "n번째 노드"
    };

    do {
        for (int i = TERMINATE; i < RETRIEVE; i++) {
            printf("(%2d) %-18.18s  ", i + 1, mstring[i]);
            if ((i % 3) == 2)
                putchar('\n');
        }
        printf("(0) 종료: ");
        scanf("%d", &ch);
    } while (ch < TERMINATE || ch > RETRIEVE);

    return (Menu)ch;
}

/*--- 메인 ---*/
int main(void)
{
    Menu menu;
    List list;

    Initialize(&list);              // 선형 리스트를 초기화

    do {
        int n;
        Member x;
        Member *ptr;

        switch (menu = SelectMenu()) {
         /* 머리에 노드를 삽입 */
         case INS_FRONT :
                x = ScanMember("머리에 삽입", MEMBER_NO | MEMBER_NAME);
                InsertFront(&list, &x);
                break;

         /* 꼬리에 노드를 삽입 */
         case INS_REAR :
                x = ScanMember("꼬리에 삽입", MEMBER_NO | MEMBER_NAME);
                InsertRear(&list, &x);
                break;

         /* 머리 노드를 삭제 */
         case RMV_FRONT :
                RemoveFront(&list);
                break;

         /* 꼬리 노드를 삭제 */
         case RMV_REAR :
                RemoveRear(&list);
                break;

         /* 선택한 노드의 데이터를 출력 */
         case PRINT_CRNT :
                PrintLnCurrent(&list);
                break;

         /* 선택한 노드를 삭제 */
         case RMV_CRNT :
                RemoveCurrent(&list);
                break;

         /* 번호로 검색 */
         case SRCH_NO :
                x = ScanMember("검색", MEMBER_NO);
                if (Search(&list, &x, MemberNoCmp) != NULL)
                    PrintLnCurrent(&list);
                else
                    puts("그 번호의 데이터가 없습니다.");
                break;

         /* 이름으로 검색 */
         case SRCH_NAME :
                x = ScanMember("검색", MEMBER_NAME);
                if (Search(&list, &x, MemberNameCmp) != NULL)
                    PrintLnCurrent(&list);
                else
                    puts("그 이름의 데이터가 없습니다.");
                break;

         /* 모든 노드의 데이터 출력 */
         case PRINT_ALL :
                Print(&list);
                break;

         /* 모든 노드를 삭제 */
         case CLEAR :
                Clear(&list);
                break;

        /* 번호가 일치하는 모든 노드를 삭제 */
         case PURGE_NO :
                Purge(&list, MemberNoCmp);
                break;

        /* 이름이 일치하는 모든 노드를 삭제 */
         case PURGE_NAME :
                Purge(&list, MemberNameCmp);
                break;

        /* n번째 노드를 출력 */
         case RETRIEVE :
                printf("앞에서부터 몇 개 뒤: ");
                scanf("%d", &n);
                if ((ptr = Retrieve(&list, n)) != NULL)
                    PrintLnMember(ptr);
                else
                    puts("그 데이터가 없습니다.");
                break;
        }
    } while (menu != TERMINATE);

    Terminate(&list);                           // 선형 리스트 종료

    return 0;
}
