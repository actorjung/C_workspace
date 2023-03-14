// 연습4-3 int형 큐 ArrayIntQueue(헤더)
#ifndef ___ArrayIntQueue
#define ___ArrayIntQueue

/*--- 큐를 구현하는 구조체 ---*/
typedef struct {
    int max;        // 큐의 최대 용량
    int num;        // 현재의 데이터 수
    int *que;       // 큐의 맨 앞 요소에 대한 포인터
} ArrayIntQueue;

/*--- 큐 초기화 ---*/
int Initialize(ArrayIntQueue *q, int max);

/*--- 큐에 데이터를 인큐 ---*/
int Enque(ArrayIntQueue *q, int x);

/*--- 큐에서 데이터를 디큐 ---*/
int Deque(ArrayIntQueue *q, int *x);

/*--- 큐에서 데이터를 피크 ---*/
int Peek(const ArrayIntQueue *q, int *x);

/*--- 모든 데이터 삭제 ---*/
void Clear(ArrayIntQueue *q);

/*--- 큐의 최대 용량 ---*/
int Capacity(const ArrayIntQueue *q);

/*--- 큐에 저장된 데이터 수 ---*/
int Size(const ArrayIntQueue *q);

/*--- 큐가 비어 있는가? ---*/
int IsEmpty(const ArrayIntQueue *q);

/*--- 큐가 가득 찼는가? ---*/
int IsFull(const ArrayIntQueue *q);

/*--- 큐에서 검색 ---*/
int Search(const ArrayIntQueue *q, int x);

/*--- 모든 데이터 출력 ---*/
void Print(const ArrayIntQueue *q);

/*--- 큐 종료 ---*/
void Terminate(ArrayIntQueue *q);

#endif
