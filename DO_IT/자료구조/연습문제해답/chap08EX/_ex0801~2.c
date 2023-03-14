// 연습 8-1 ~ 연습 8-2 포인터로 만든 선형 리스트(소스)
#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "LinkedList.h"

/*--- 노드를 동적으로 생성 ---*/
static Node* AllocNode(void)
{
    return calloc(1, sizeof(Node));
}

/*--- n이 가리키는 노드의 각 멤버에 값을 설정 ----*/
static void SetNode(Node* n, const Member* x, const Node* next)
{
    n->data = *x;       // 데이터
    n->next = next;     // 다음 노드에 대한 포인터
}

/*--- 선형 리스트를 초기화 ---*/
void Initialize(List* list)
{
    list->head = NULL;  // 머리 노드
    list->crnt = NULL;  // 선택 노드
}

/*--- 함수 compare로 x와 같은 노드를 검색 ---*/
Node* Search(List* list, const Member* x,
    int compare(const Member* x, const Member* y))
{
    Node* ptr = list->head;

    while (ptr != NULL) {
        if (compare(&ptr->data, x) == 0) {  // 키값이 같은 경우 
            list->crnt = ptr;
            return ptr;                 // 검색 성공
        }
        ptr = ptr->next;                // 다음 노드를 선택
    }
    return NULL;                        // 검색 실패
}

/*--- 앞에서부터 n개 뒤의 노드에 대한 포인터를 반환 ---*/
Node *Retrieve(List *list, int n)
{
    Node *ptr = list->head;

    while (n >= 0 && ptr != NULL) {
        if (n-- == 0) {
            list->crnt = ptr;
            return ptr;                 // 검색 성공
        }
        ptr = ptr->next;                // 다음 노드를 선택
    }
    return NULL;                        // 검색 실패
}

/*--- 머리에 노드를 삽입 ---*/
void InsertFront(List* list, const Member* x)
{
    Node* ptr = list->head;
    list->head = list->crnt = AllocNode();
    SetNode(list->head, x, ptr);
}

/*--- 꼬리에 노드를 삽입 ---*/
void InsertRear(List* list, const Member* x)
{
    if (list->head == NULL)                 // 비어 있는 경우
        InsertFront(list, x);               // 머리에 삽입
    else {
        Node* ptr = list->head;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = list->crnt = AllocNode();
        SetNode(ptr->next, x, NULL);
    }
}

/*--- 머리 노드를 삭제 ---*/
void RemoveFront(List* list)
{
    if (list->head != NULL) {
        Node* ptr = list->head->next;       // 2번째 노드에 대한 포인터
        free(list->head);                   // 머리 노드를 해제
        list->head = list->crnt = ptr;      // 새로운 머리 노드
    }
}

/*--- 꼬리 노드를 삭제 ---*/
void RemoveRear(List* list)
{
    if (list->head != NULL) {
        if (list->head->next == NULL)       // 노드가 1개만 있는 경우
            RemoveFront(list);              // 머리 노드를 삭제
        else {
            Node* ptr = list->head;
            Node* pre;

            while (ptr->next != NULL) {
                pre = ptr;
                ptr = ptr->next;
            }
            pre->next = NULL;               // pre는 꼬리 노드로부터 두 번째 노드
            free(ptr);                      // ptr은 꼬리 노드
            list->crnt = pre;
        }
    }
}

/*--- 선택한 노드를 삭제 ---*/
void RemoveCurrent(List* list)
{
    if (list->head != NULL) {
        if (list->crnt == list->head)   // 머리 노드를 선택한 상태라면
            RemoveFront(list);          // 머리 노드를 삭제
        else {
            Node* ptr = list->head;

            while (ptr->next != list->crnt)
                ptr = ptr->next;
            ptr->next = list->crnt->next;
            free(list->crnt);
            list->crnt = ptr;
        }
    }
}

/*--- 비교 함수에 따라 같다고 볼 수 있는 노드를 삭제 ---*/
void Purge(List *list, int compare(const Member *x, const Member *y))
{
    Node *ptr = list->head;

    while (ptr != NULL) {
        Node *ptr2 = ptr;
        Node *pre = ptr;

        while (pre->next != NULL) {
            ptr2 = pre->next;
            if (!compare(&ptr->data, &ptr2->data)) {
                pre->next = ptr2->next;
                free(ptr2);
            } else {
                pre = ptr2;
            }
        }
        ptr = ptr->next;
    }
    list->crnt = list->head;
}

/*--- 모든 노드를 삭제 ---*/
void Clear(List* list)
{
    while (list->head != NULL)          // 텅 빌 때까지
        RemoveFront(list);              // 머리 노드를 삭제
    list->crnt = NULL;
}

/*--- 선택한 노드의 데이터 출력 ---*/
void PrintCurrent(const List* list)
{
    if (list->crnt == NULL)
        printf("선택한 노드가 없습니다.");
    else
        PrintMember(&list->crnt->data);
}

/*--- 선택한 노드의 데이터 출력(줄 바꿈 문자 포함)---*/
void PrintLnCurrent(const List* list)
{
    PrintCurrent(list);
    putchar('\n');
}

/*--- 모든 노드의 데이터를 리스트 순서대로 출력 ---*/
void Print(const List* list)
{
    if (list->head == NULL)
        puts("노드가 없습니다.");
    else {
        Node* ptr = list->head;

        puts("【모두 보기】");
        while (ptr != NULL) {
            PrintLnMember(&ptr->data);
            ptr = ptr->next;            // 다음 노드를 선택
        }
    }
}

/*--- 선형 리스트 종료 ---*/
void Terminate(List* list)
{
    Clear(list);                        // 모든 노드를 삭제
}
