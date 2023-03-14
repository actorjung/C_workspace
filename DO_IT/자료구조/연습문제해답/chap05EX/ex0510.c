// 연습 5-10　8퀸 문제를 비재귀적으로 풀이
// 주의: 이 프로그램을 컴파일하려면 'IntStack.h'와 'IntStack.c'가 필요합니다.
#include <stdio.h>
#include "IntStack.h"

int flag_a[8];      // 각 행에 퀸을 배치했는지 체크하는 배열
int flag_b[15];     // 대각선 /에 퀸을 배치했는지 체크하는 배열
int flag_c[15];     // 대각선 \에 퀸을 배치했는지 체크하는 배열
int pos[8];         // 각 열에서 퀸의 위치 */

/*--- 각 열에서 퀸의 위치를 출력 ---*/
void print(void)
{
    for (int i = 0; i < 8; i++)
        printf("%2d", pos[i]);
    putchar('\n');
}

/*--- i열에서 알맞은 위치에 퀸을 배치(비재귀 버전)---*/
void set(int i)
{
    IntStack jstk;
    Initialize(&jstk, 8);

Start :
    while (1) {
        int j = 0;
        while (1) {
            while (j < 8) {
                if (!flag_a[j] && !flag_b[i + j] && !flag_c[i - j + 7]) {
                    pos[i] = j;
                    if (i == 7)             // 모든 열에 배치를 마침
                        print();
                    else {
                        flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 1;
                        i++;
                        Push(&jstk, j);     // i열의 행을 푸시
                        goto Start;
                    }
                }
                j++;
            }
            if (--i == -1) return;
            Pop(&jstk, &j);                 // i열의 행을 팝
            flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 0;
            j++;
        }
    }
    Terminate(&jstk);
}

int main(void)
{
    for (int i = 0; i <  8; i++)
        flag_a[i] = 0;
    for (int i = 0; i < 15; i++)
        flag_b[i] = flag_c[i] = 0;

    set(0);                     // 0열에 배치

    return 0;
}
