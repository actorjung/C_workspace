// 연습 8-4　원형 이중 연결 리스트(헤더)
#ifndef ___CircDblLinkedList
#define ___CircDblLinkedList

#include "Member.h"

/*--- 노드 ---*/
typedef struct __node {
    Member        data;         // 데이터
    struct __node *prev;        // 앞쪽 노드에 대한 포인터（앞쪽 노드를 가리키는 포인터）
    struct __node *next;        // 다음 노드에 대한 포인터(다음 노드를 가리키는 포인터)
} Dnode;

/*--- 원형 이중 연결 리스트 ---*/
typedef struct {
    Dnode* head;                // 머리 포인터(더미 노드를 가리키는 포인터）
    Dnode* crnt;                // 선택 포인터(선택한 노드를 가리키는 포인터）
} Dlist;

/*--- 리스트를 초기화 ---*/
void Initialize(Dlist* list);

/*--- 선택한 노드의 데이터 출력 ---*/
void PrintCurrent(const Dlist* list);

/*--- 선택한 노드의 데이터 출력(줄 바꿈 문자 포함)---*/
void PrintLnCurrent(const Dlist* list);

/*--- 함수 compare로 x와 같은 노드를 검색 ---*/
Dnode* Search(Dlist* list, const Member* x,
                           int compare(const Member* x, const Member* y));

/*--- 앞에서부터 n개 뒤의 노드를 가리키는 포인터 ---*/
Dnode *Retrieve(Dlist *list, int n);

/*--- 모든 노드의 데이터를 리스트 순서대로 출력 ---*/
void Print(const Dlist* list);

/*--- 모든 노드의 데이터를 리스트 역순으로 출력 ---*/
void PrintReverse(const Dlist* list);

/*--- 선택한 노드를 다음으로 진행 ---*/
int Next(Dlist* list);

/*--- 선택한 노드를 앞쪽으로 진행 ---*/
int Prev(Dlist* list);

/*--- p가 가리키는 노드의 바로 다음 노드를 삽입 ---*/
void InsertAfter(Dlist* list, Dnode* p, const Member* x);

/*--- 머리에 노드를 삽입 ---*/
void InsertFront(Dlist* list, const Member* x);

/*--- 꼬리에 노드를 삽입 ---*/
void InsertRear(Dlist* list, const Member* x);

/*--- p가 가리키는 노드를 삭제 ---*/
void Remove(Dlist* list, Dnode* p);

/*--- 머리 노드를 삭제 ---*/
void RemoveFront(Dlist* list);

/*--- 꼬리 노드를 삭제 ---*/
void RemoveRear(Dlist* list);

/*--- 선택한 노드를 삭제 ---*/
void RemoveCurrent(Dlist* list);

/*--- 비교 함수에 따라 같다고 볼 수 있는 노드를 삭제 ---*/
void Purge(Dlist *list, int compare(const Member *x, const Member *y));

/*--- 모든 노드를 삭제 ---*/
void Clear(Dlist* list);

/*--- 원형 이중 연결 리스트 종료 ---*/
void Terminate(Dlist* list);

#endif
