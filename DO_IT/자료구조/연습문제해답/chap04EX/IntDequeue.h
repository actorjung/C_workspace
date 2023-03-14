// 연습4-6 int형 디큐 IntDequeue(헤더)
#ifndef ___IntDequeue
#define ___IntDequeue

/*--- 디큐를 구현하는 구조체 ---*/
typedef struct {
    int max;        // 디큐의 최대 용량
    int num;        // 현재의 데이터 수
    int front;      // 맨 앞 요소 커서
    int rear;       // 맨 뒤 요소 커서
    int *que;       // 디큐의 맨 앞 요소에 대한 포인터
} IntDequeue;

/*--- 디큐  초기화 ---*/
int Initialize(IntDequeue *q, int max);

/*--- 디큐의 맨 앞에 데이터를 인큐 ---*/
int EnqueFront(IntDequeue *q, int x);

/*--- 디큐의 맨 뒤에 데이터를 인큐 ---*/
int EnqueRear(IntDequeue *q, int x);

/*--- 디큐의 맨 앞에서 데이터를 디큐 ---*/
int DequeFront(IntDequeue *q, int *x);

/*--- 디큐의 맨 뒤에서 데이터를 디큐 ---*/
int DequeRear(IntDequeue *q, int *x);

/*--- 디큐의 맨 앞에서 데이터를 피크 ---*/
int PeekFront(const IntDequeue *q, int *x);

/*--- 디큐의 맨 뒤에서 데이터를 피크 ---*/
int PeekRear(const IntDequeue *q, int *x);

/*--- 모든 데이터 삭제 ---*/
void Clear(IntDequeue *q);

/*--- 디큐 의 최대 용량 ---*/
int Capacity(const IntDequeue *q);

/*--- 디큐 에 저장된 데이터 수 ---*/
int Size(const IntDequeue *q);

/*--- 디큐 가 비어 있는가? ---*/
int IsEmpty(const IntDequeue *q);

/*--- 디큐 가 가득 찼는가? ---*/
int IsFull(const IntDequeue *q);

/*--- 디큐 에서 검색 ---*/
int Search(const IntDequeue *q, int x);

/*--- 디큐 에서 검색(논리적 인덱스를 반환) ---*/
int Search2(const IntDequeue *q, int x);

/*--- 모든 데이터 출력 ---*/
void Print(const IntDequeue *q);

/*--- 디큐  종료 ---*/
void Terminate(IntDequeue *q);

#endif
