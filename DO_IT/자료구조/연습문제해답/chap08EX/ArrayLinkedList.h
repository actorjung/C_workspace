// 연습 8-3 커서로 만든 선형 리스트(헤더)
#ifndef ___ArrayLinkedList
#define ___ArrayLinkedList

#include "Member.h"

#define Null    -1          // 빈 커서

typedef int Index;          // 커서의 자료형

/*--- 노드 ---*/
typedef struct {
    Member data;            // 데이터
    Index next;             // 다음 커서
    Index Dnext;            // 프리 리스트의 다음 커서
} Node;

/*--- 선형 리스트 ---*/
typedef struct {
    Node* n;                // 리스트 본체(배열)
    Index head;             // 머리 커서
    Index max;              // 사용 중인 꼬리 레코드
    Index deleted;          // 프리 리스트의 머리 커서
    Index crnt;             // 선택한 커서
} List;

/*--- 선형 리스트를 초기화(최대 요소 수는 size)---*/
void Initialize(List *list, int size);

/*--- 함수 compare로 x와 같은 노드를 검색 ---*/
Index Search(List *list, const Member *x,
                         int compare(const Member *x, const Member *y));

/*--- 앞에서부터 n개 뒤의 노드에 대한 커서 ---*/
Index Retrieve(List *list, int n);

/*--- 머리에 노드를 삽입 ---*/
void InsertFront(List *list, const Member *x);

/*--- 꼬리에 노드를 삽입 ---*/
void InsertRear(List *list, const Member *x);

/*--- 머리 노드를 삭제 ---*/
void RemoveFront(List *list);

/*--- 꼬리 노드를 삭제 ---*/
void RemoveRear(List *list);

/*--- 선택한 노드를 삭제 ---*/
void RemoveCurrent(List *list);

/*--- 비교 함수에 따라 같다고 볼 수 있는 노드를 삭제 ---*/
void Purge(List *list, int compare(const Member *x, const Member *y));

/*--- 모든 노드를 삭제 ---*/
void Clear(List *list);

/*--- 선택한 노드의 데이터 출력 ---*/
void PrintCurrent(const List *list);

/*--- 선택한 노드의 데이터 출력(줄 바꿈 문자 포함)---*/
void PrintLnCurrent(const List *list);

/*--- 모든 노드의 데이터 출력 ---*/
void Print(const List *list);

/*--- 선형 리스트 종료 ---*/
void Terminate(List *list);

#endif
