/****
 * 151 - Power Crisis
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define Q_SIZE      105
int _Q[Q_SIZE];
int _QF = 0, _QR = 0;
#define Q_RESET()       _QF = _QR = 0;
#define Q_ENQUEUE(v0)   { _Q[_QR] = (v0); _QR = (_QR + 1) % Q_SIZE; }
#define Q_DEQUEUE(v0)   { v0 = _Q[_QF]; _QF = (_QF + 1 ) % Q_SIZE; }
#define Q_IS_EMPTY()    (_QF == _QR)

int josephus(int n, int m)
{
    int x = 0, y, i;

    Q_RESET();
    for (i = 2; i <= n; i++)
        Q_ENQUEUE(i);

    while (!Q_IS_EMPTY())
    {
        for (i = 0; i < m-1; i++)
        {
            Q_DEQUEUE(y);
            Q_ENQUEUE(y);
        }

        Q_DEQUEUE(x);
    }
    return x;
}

int main()
{
    int n, m;
    int i, j;
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (scanf("%d", &n) != 0 && n != 0)
    {
        if (n == 13)
        {
            puts("1");
            continue;
        }

        for (m = 2; ; m++)
        {
            if (josephus(n, m) == 13)
                break;
        }

        printf("%d\n", m);
    }

#ifndef ONLINE_JUDGE
    /*system("pause");*/
#endif
    return 0;
}

