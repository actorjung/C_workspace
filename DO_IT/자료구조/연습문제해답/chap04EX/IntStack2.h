// 연습4-2 배열 공유 int형 스택 IntStack2(헤더)
#ifndef ___IntStack2
#define ___IntStack2

enum {StackA, StackB};

/*--- 배열 공유 스택을 구현하는 구조체 ---*/
typedef struct {
    int max;        // 스택 용량
    int ptrA;       // 스택 포인터 Ａ
    int ptrB;       // 스택 포인터 Ｂ
    int *stk;       // 스택의 첫 요소에 대한 포인터
} IntStack;

/*--- 스택 초기화 ---*/
int Initialize(IntStack *s, int max);

/*--- 스택에 데이터를 푸시 ---*/
int Push(IntStack *s, int sw, int x);

/*--- 스택에서 데이터를 팝 ---*/
int Pop(IntStack *s, int sw, int *x);

/*--- 스택에서 데이터를 피크 ---*/
int Peek(const IntStack *s, int sw, int *x);

/*--- 스택 비우기 ---*/
void Clear(IntStack *s, int sw);

/*--- 스택 용량 ---*/
int Capacity(const IntStack *s);

/*--- 스택에 쌓여 있는 데이터 개수---*/
int Size(const IntStack *s, int sw);

/*--- 스택은 비어 있는가? ---*/
int IsEmpty(const IntStack *s, int sw);

/*--- 스택은 가득 찼는가? ---*/
int IsFull(const IntStack *s);

/*--- 스택에서 검색 ---*/
int Search(const IntStack *s, int sw, int x);

/*--- 모든 데이터 출력 ---*/
void Print(const IntStack *s, int sw);

/*--- 스택 종료 ---*/
void Terminate(IntStack *s);

#endif
