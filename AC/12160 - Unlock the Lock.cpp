/****
 * 12160 - Unlock the Lock
 */
#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;

#define MAX_R     10
int L, U, R;
int RV[MAX_R];
int pc[10000];

#define Q_SIZE  8192
int _Q[Q_SIZE];
int _QF = 0, _QR = 0;
#define Q_RESET()       _QF = _QR = 0;
#define Q_ENQUEUE(v0)   { _Q[_QR] = (v0); _QR = (_QR + 1) & (Q_SIZE-1) ; }
#define Q_DEQUEUE(v0)   { v0 = _Q[_QF]; _QF = (_QF + 1 ) & (Q_SIZE-1); }
#define Q_IS_EMPTY()    (_QF == _QR)


int main()
{
    int i, j, k;
    int found;
    int T = 0;

    for (T = 1; ; T += 1)
    {
        scanf("%d %d %d", &L, &U, &R);
        if (L== 0 && U == 0 && R == 0)
            break;
        for (i = 0; i < R; i++)
            scanf("%d", &RV[i]);

        for (i = 0; i < 10000; i++)
            pc[i] = -1;

        Q_RESET();
        Q_ENQUEUE(L);
        pc[L] = 0;
        found = 0;
        while (!Q_IS_EMPTY())
        {
            Q_DEQUEUE(i);

            if (i == U)
            {
                found = 1;
                break;
            }

            for (j = 0; j < R; j++)
            {
                k = (i + RV[j]) % 10000;
                if (pc[k] == -1)
                {
                    Q_ENQUEUE(k);
                    pc[k] = pc[i] + 1;
                }
            }
        }/* while (!Q_IS_EMPTY()) */

        if (found == 0)
        {
            printf("Case %d: Permanently Locked\n", T);
        }
        else{
            printf("Case %d: %d\n", T, pc[i]);
        }
    }

#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}

