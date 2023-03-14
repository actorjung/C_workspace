// 연습 9-1 ~ 연습 9-2　이진검색트리를 사용하는 프로그램
#include <stdio.h>
#include "Member.h"
#include "BinTree.h"

/*--- 메뉴 ---*/
typedef enum {
    TERMINATE, ADD, REMOVE, SEARCH, PRINT, PRINT_REV, GET_MIN, GET_MAX
} Menu;

/*--- 메뉴 선택 ---*/
Menu SelectMenu(void)
{
    int ch;

    do {
        printf("\n(1)삽입 (2)삭제 (3)검색 (4)출력 (5)역순 출력 (6)최소 (7)최대 (0) 종료: ");
        scanf("%d", &ch);
    } while (ch < TERMINATE || ch > GET_MAX);
    return (Menu)ch;
}

/*--- 메인 함수 ---*/
int main(void)
{
    Menu    menu;
    BinNode *root = NULL;       // 이진검색트리의 루트 노드 포인터

    do {
        Member x;
        BinNode *temp;

        switch (menu = SelectMenu()) {
         /*--- 노드 삽입 ---*/
         case ADD :
                x = ScanMember("삽입", MEMBER_NO | MEMBER_NAME);
                root = Add(root, &x);
                break;

         /*--- 노드 삭제 ---*/
         case REMOVE :
                x = ScanMember("삭제", MEMBER_NO);
                Remove(&root, &x);
                break;

         /*--- 노드 검색 ---*/
         case SEARCH :
                x = ScanMember("검색", MEMBER_NO);
                if ((temp = Search(root, &x)) != NULL)
                    PrintLnMember(&temp->data);
                break;

         /*--- 모든 노드를 출력 ---*/
         case PRINT :
                puts("【모든 노드 출력】");
                PrintTree(root);
                break;

         /*--- 모든 노드를 역순으로 출력 ---*/
         case PRINT_REV :
                puts("【모든 노드를 역순으로 출력】");
                PrintTreeReverse(root);
                break;

         /*--- 가장 작은 키값 ---*/
         case GET_MIN :
                if ((temp = GetMinNode(root)) != NULL)
                    PrintLnMember(&temp->data);
                break;

         /*--- 가장 큰 키값 ---*/
         case GET_MAX :
                if ((temp = GetMaxNode(root)) != NULL)
                    PrintLnMember(&temp->data);
        }
    } while (menu != TERMINATE);

    FreeTree(root);

    return 0;
}
