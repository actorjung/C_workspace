// 연습4-3 int형 큐 ArrayIntQueue(소스)
#include <stdio.h>
#include <stdlib.h>
#include "ArrayIntQueue.h"

/*--- 큐 초기화 ---*/
int Initialize(ArrayIntQueue *q, int max)
{
    q->num = 0;
    if ((q->que = calloc(max, sizeof(int))) == NULL) {
        q->max = 0;                             // 배열 생성에 실패
        return -1;
    }
    q->max = max;
    return 0;
}

/*--- 큐에 데이터를 인큐 ---*/
int Enque(ArrayIntQueue *q, int x)
{
    if (q->num >= q->max)
        return -1;                              // 큐가 가득 참
    else {
        q->que[q->num++] = x;
        return 0;
    }
}

/*--- 큐에서 데이터를 디큐 ---*/
int Deque(ArrayIntQueue *q, int *x)
{
    if (q->num <= 0)                            // 큐가 비어 있음
        return -1;
    else {
        *x = q->que[0];
        for (int i = 0; i < q->num - 1; i++)
            q->que[i] = q->que[i + 1];
        q->num--;
        return 0;
    }
}

/*--- 큐에서 데이터를 피크 ---*/
int Peek(const ArrayIntQueue *q, int *x)
{
    if (q->num <= 0)                            // 큐가 비어 있음
        return -1;
    *x = q->que[0];
    return 0;
}

/*--- 모든 데이터 삭제 ---*/
void Clear(ArrayIntQueue *q)
{
    q->num = 0;
}

/*--- 큐의 최대 용량 ---*/
int Capacity(const ArrayIntQueue *q)
{
    return q->max;
}

/*--- 큐에 쌓여 있는 데이터 수 ---*/
int Size(const ArrayIntQueue *q)
{
    return q->num;
}

/*--- 큐가 비어 있는가? ---*/
int IsEmpty(const ArrayIntQueue *q)
{
    return q->num <= 0;
}

/*--- 큐가 가득 찼는가? ---*/
int IsFull(const ArrayIntQueue *q)
{
    return q->num >= q->max;
}

/*--- 큐에서 검색 ---*/
int Search(const ArrayIntQueue *q, int x)
{
    for (int i = 0; i < q->num; i++) {
        if (q->que[i] == x)
            return i;       // 검색 성공
    }
    return -1;              // 검색 실패
}

/*--- 모든 데이터 출력 ---*/
void Print(const ArrayIntQueue *q)
{
    for (int i = 0; i < q->num; i++)
        printf("%d ", q->que[i]);
    putchar('\n');
}

/*--- 큐 종료 ---*/
void Terminate(ArrayIntQueue *q)
{
    if (q->que != NULL)
        free(q->que);                           // 배열을 해제
    q->max = q->num = 0;
}
