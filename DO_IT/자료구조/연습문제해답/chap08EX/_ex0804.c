// 연습 8-4　원형 이중 연결 리스트(소스)
#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "CircDblLinkedList.h"

/*--- 노드를 동적으로 생성 ---*/
static Dnode* AllocDnode(void)
{
    return calloc(1, sizeof(Dnode));
}

/*--- 노드의 각 멤버에 값을 설정 ----*/
static void SetDnode(Dnode* n, const Member* x, const Dnode* prev,
    const Dnode* next)
{
    n->data = *x;       // 데이터
    n->prev = prev;     // 앞쪽 노드에 대한 포인터
    n->next = next;     // 다음 노드에 대한 포인터
}

/*--- 리스트가 비어 있는지 검사 ---*/
static int IsEmpty(const Dlist* list)
{
    return list->head->next == list->head;
}

/*--- 리스트를 초기화 ---*/
void Initialize(Dlist* list)
{
    Dnode* dummyNode = AllocDnode();            // 더미 노드 생성
    list->head = list->crnt = dummyNode;
    dummyNode->prev = dummyNode->next = dummyNode;
}

/*--- 선택한 노드의 데이터 출력 ---*/
void PrintCurrent(const Dlist* list)
{
    if (IsEmpty(list))
        printf("선택한 노드가 없습니다.");
    else
        PrintMember(&list->crnt->data);
}

/*--- 선택한 노드의 데이터 출력(줄 바꿈 문자 포함)---*/
void PrintLnCurrent(const Dlist* list)
{
    PrintCurrent(list);
    putchar('\n');
}

/*--- 함수 compare로 x와 같은 노드를 검색 ---*/
Dnode* Search(Dlist* list, const Member* x,
    int compare(const Member* x, const Member* y))
{
    Dnode* ptr = list->head->next;

    while (ptr != list->head) {
        if (compare(&ptr->data, x) == 0) {
            list->crnt = ptr;
            return ptr;                 // 검색 성공
        }
        ptr = ptr->next;
    }
    return NULL;                        // 검색 실패
}

/*--- 앞에서부터 n개 뒤의 노드를 가리키는 포인터 ---*/
Dnode *Retrieve(Dlist *list, int n)
{
    Dnode *ptr = list->head->next;

    while (n >= 0 && ptr != list->head) {
        if (n-- == 0) {
            list->crnt = ptr;
            return ptr;                 // 검색 성공
        }
        ptr = ptr->next;                // 다음 노드를 선택
    }
    return NULL;                        // 검색 실패
}

/*--- 모든 노드의 데이터를 리스트 순서대로 출력 ---*/
void Print(const Dlist* list)
{
    if (IsEmpty(list))
        puts("노드가 없습니다.");
    else {
        Dnode* ptr = list->head->next;

        puts("【모두 보기】");
        while (ptr != list->head) {
            PrintLnMember(&ptr->data);
            ptr = ptr->next;            // 다음 노드를 선택
        }
    }
}

/*--- 모든 노드의 데이터를 리스트 역순으로 출력 ---*/
void PrintReverse(const Dlist* list)
{
    if (IsEmpty(list))
        puts("노드가 없습니다.");
    else {
        Dnode* ptr = list->head->prev;

        puts("【모두 보기】");
        while (ptr != list->head) {
            PrintLnMember(&ptr->data);
            ptr = ptr->prev;            // 앞쪽 노드 선택
        }
    }
}

/*--- 선택한 노드를 다음으로 진행 ---*/
int Next(Dlist* list)
{
    if (IsEmpty(list) || list->crnt->next == list->head)
        return 0;                       // 진행할 수 없음
    list->crnt = list->crnt->next;
    return 1;
}

/*--- 선택한 노드를 앞쪽으로 진행 ---*/
int Prev(Dlist* list)
{
    if (IsEmpty(list) || list->crnt->prev == list->head)
        return 0;                       // 되돌아갈 수 없음
    list->crnt = list->crnt->prev;
    return 1;
}

/*--- p가 가리키는 노드의 바로 다음 노드를 삽입 ---*/
void InsertAfter(Dlist* list, Dnode* p, const Member* x)
{
    Dnode* ptr = AllocDnode();
    Dnode* nxt = p->next;

    p->next = p->next->prev = ptr;
    SetDnode(ptr, x, p, nxt);
    list->crnt = ptr;                       // 삽입한 노드를 선택
}

/*--- 머리에 노드를 삽입 ---*/
void InsertFront(Dlist* list, const Member* x)
{
    InsertAfter(list, list->head, x);
}

/*--- 꼬리에 노드를 삽입 ---*/
void InsertRear(Dlist* list, const Member* x)
{
    InsertAfter(list, list->head->prev, x);
}

/*--- p가 가리키는 노드를 삭제 ---*/
void Remove(Dlist* list, Dnode* p)
{
    p->prev->next = p->next;
    p->next->prev = p->prev;
    list->crnt = p->prev;       //  삭제한 노드의 앞쪽 노드 선택
    free(p);
    if (list->crnt == list->head)
        list->crnt = list->head->next;
}

/*--- 머리 노드를 삭제 ---*/
void RemoveFront(Dlist* list)
{
    if (!IsEmpty(list))
        Remove(list, list->head->next);
}

/*--- 꼬리 노드를 삭제 ---*/
void RemoveRear(Dlist* list)
{
    if (!IsEmpty(list))
        Remove(list, list->head->prev);
}

/*--- 선택한 노드를 삭제 ---*/
void RemoveCurrent(Dlist* list)
{
    if (list->crnt != list->head)
        Remove(list, list->crnt);
}

/*--- 비교 함수에 따라 같다고 볼 수 있는 노드를 삭제 ---*/
void Purge(Dlist *list, int compare(const Member *x, const Member *y))
{
    Dnode *ptr = list->head->next;

    while (ptr != list->head) {
        Dnode *ptr2 = ptr;
        Dnode *pre = ptr;

        while (pre->next != list->head) {
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
void Clear(Dlist* list)
{
    while (!IsEmpty(list))          // 빌 때까지
        RemoveFront(list);          // 머리 노드를 삭제
}

/*--- 원형 이중 연결 리스트 종료 ---*/
void Terminate(Dlist* list)
{
    Clear(list);                    // 모든 노드를 삭제
    free(list->head);               // 더미 노드를 삭제
}
