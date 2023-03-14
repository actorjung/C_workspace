// 연습 8-1 ~ 연습 8-2 포인터로 만든 선형 리스트(헤더)
#ifndef ___LinkedList
#define ___LinkedList

#include "Member.h"

/*--- 노드 ---*/
typedef struct __node {
    Member         data;    // 데이터
    struct __node* next;    // 다음 노드에 대한 포인터(다음 노드를 가리키는 포인터)
} Node;

/*--- 선형 리스트 ---*/
typedef struct {
    Node* head;     // 머리 포인터（머리 노드를 가리키는 포인터）
    Node* crnt;     // 선택 포인터（선택한 노드를 가리키는 포인터）
} List;

/*--- 선형 리스트를 초기화 ---*/
void Initialize(List* list);

/*--- 함수 compare로 x와 같은 노드를 검색 ---*/
Node* Search(List* list, const Member* x,
                         int compare(const Member* x, const Member* y));

/*--- 앞에서부터 n개 뒤의 노드를 가리키는 포인터 ---*/
Node *Retrieve(List *list, int n);

/*--- 머리에 노드를 삽입 ---*/
void InsertFront(List* list, const Member* x);

/*--- 꼬리에 노드를 삽입 ---*/
void InsertRear(List* list, const Member* x);

/*--- 머리 노드를 삭제 ---*/
void RemoveFront(List* list);

/*--- 꼬리 노드를 삭제 ---*/
void RemoveRear(List* list);

/*--- 선택한 노드를 삭제 ---*/
void RemoveCurrent(List* list);

/*--- 비교 함수에 따라 같다고 볼 수 있는 노드를 삭제 ---*/
void Purge(List *list, int compare(const Member *x, const Member *y));

/*--- 모든 노드를 삭제 ---*/
void Clear(List* list);

/*--- 선택한 노드의 데이터 출력 ---*/
void PrintCurrent(const List* list);

/*--- 선택한 노드의 데이터 출력(줄 바꿈 문자 포함)---*/
void PrintLnCurrent(const List* list);

/*--- 모든 노드의 데이터를 리스트 순서대로 출력 ---*/
void Print(const List* list);

/*--- 선형 리스트 종료 ---*/
void Terminate(List* list);

#endif
