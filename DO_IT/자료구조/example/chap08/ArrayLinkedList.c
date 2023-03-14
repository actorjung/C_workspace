// 커서로 만든 연결 리스트(소스)
#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "ArrayLinkedList.h"

/*--- 삽입할 레코드의 인덱스를 구한 다음 반환 ---*/
static Index GetIndex(List *list)
{
    if (list->deleted == Null)              // 삭제할 레코드가 없는 경우
        return ++(list->max);
    else {
        Index rec = list->deleted;
        list->deleted = list->n[rec].Dnext;
        return rec;
    }
}

/*--- 지정된 레코드를 삭제 리스트에 등록 ---*/
static void DeleteIndex(List *list, Index idx)
{
    if (list->deleted == Null) {            // 삭제할 레코드가 없는 경우
        list->deleted = idx;
        list->n[idx].Dnext = Null;
    } 
    else {
        Index ptr = list->deleted;
        list->deleted = idx;
        list->n[idx].Dnext = ptr;
    }
}

/*--- n이 가리키는 노드의 각 멤버에 값을 설정 ----*/
static void SetNode(Node *n, const Member *x, Index next)
{
    n->data = *x;                           // 데이터
    n->next = next;                         // 다음 커서
}

/*--- 연결 리스트를 초기화 ---*/
void Initialize(List *list, int size)
{
    list->n = calloc(size, sizeof(Node));
    list->head = Null;                      // 머리 노드
    list->crnt = Null;                      // 선택한 노드
    list->max = Null;
    list->deleted = Null;
}

/*--- compare 함수로 x와 일치하는 노드 검색 ---*/
Index Search(List *list, const Member *x, int compare(const Member *x, const Member *y))
{
    Index ptr = list->head;
    while (ptr != Null) {
        if (compare(&list->n[ptr].data, x) == 0) {
            list->crnt = ptr;
            return ptr;                 // 검색 성공
        }
        ptr = list->n[ptr].next;
    }
    return Null;                        // 검색 실패
}

/*--- 머리에 노드를 삽입 ---*/
void InsertFront(List *list, const Member *x)
{
    Index ptr = list->head;
    list->head = list->crnt = GetIndex(list);
    SetNode(&list->n[list->head], x, ptr);
}

/*--- 꼬리에 노드를 삽입 ---*/
void InsertRear(List *list, const Member *x)
{
    if (list->head == Null)                 // 비어 있는 경우
        InsertFront(list, x);               // 머리에 삽입
    else {
        Index ptr = list->head;
        while (list->n[ptr].next != Null)
            ptr = list->n[ptr].next;
        list->n[ptr].next = list->crnt = GetIndex(list);
        SetNode(&list->n[list->n[ptr].next], x, Null);
    }
}

/*--- 머리 노드를 삭제 ---*/
void RemoveFront(List *list)
{
    if (list->head != Null) {
        Index ptr = list->n[list->head].next;
        DeleteIndex(list, list->head);
        list->head = list->crnt = ptr;
    }
}

/*--- 꼬리 노드를 삭제 ---*/
void RemoveRear(List *list)
{
    if (list->head != Null) {
        if (list->n[list->head].next == Null)   // 노드가 1개만 있으면
            RemoveFront(list);                  // 머리 노드를 삭제
        else {
            Index ptr = list->head;
            Index pre;

            while (list->n[ptr].next != Null) {
                pre = ptr;
                ptr = list->n[ptr].next;
            }
            list->n[pre].next = Null;
            DeleteIndex(list, ptr);
            list->crnt = pre;
        }
    }
}

/*--- 선택한 노드를 삭제 ---*/
void RemoveCurrent(List *list)
{
    if (list->head != Null) {
        if (list->crnt == list->head)       // 머리 노드가 선택되어 있으면
            RemoveFront(list);              // 머리 노드를 삭제
        else {
            Index ptr = list->head;

            while (list->n[ptr].next != list->crnt)
                ptr = list->n[ptr].next;
            list->n[ptr].next = list->n[list->crnt].next;
            DeleteIndex(list, list->crnt);
            list->crnt = ptr;
        }
    }
}

/*--- 모든 노드를 삭제 ---*/
void Clear(List *list)
{
    while (list->head != Null)          // 텅 빌 때까지
        RemoveFront(list);              // 머리 노드를 삭제
    list->crnt = Null;
}

/*--- 선택한 노드의 데이터를 출력 ---*/
void PrintCurrent(const List *list)
{
    if (list->crnt == Null)
        printf("선택한 노드가 없습니다.");
    else
        PrintMember(&list->n[list->crnt].data);
}

/*--- 선택한 노드의 데이터를 출력(줄 바꿈 문자 추가) ---*/
void PrintLnCurrent(const List *list)
{
    PrintCurrent(list);
    putchar('\n');
}

/*--- 모든 노드의 데이터를 출력 ---*/
void Print(const List *list)
{
    if (list->head == Null)
        puts("노드가 없습니다.");
    else {
        Index ptr = list->head;
        puts("【모두 보기】");
        while (ptr != Null) {
            PrintLnMember(&list->n[ptr].data);
            ptr = list->n[ptr].next;        // 다음 노드
        }
    }
}

/*--- 연결 리스트 종료 ---*/
void Terminate(List *list)
{
    Clear(list);                    // 모든 노드를 삭제
    free(list->n);
}
