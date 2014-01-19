/****
 * 144 - Student Grants
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

queue <int> q;
int r[25];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    for (;;)
    {
        int n, k;
        scanf("%d %d", &n, &k);
        if (n ==0 && k ==0)
            break;

        for (int i = 0; i< n; i++)
        {
            r[i] = 40;
            q.push(i);
        }

        int m = 0, f = 1;
        while (!q.empty())
        {
            if (m == 0)
            {
                m = f;
                f = (f) % k + 1;
            }

            int p = q.front();
            q.pop();
            if (r[p] > m)
            {
                r[p] -= m;
                m = 0;
                q.push(p);
            }
            else if (r[p] < m)
            {
                m = m - r[p];
                r[p] = 0;
                printf("%3d", p+1);
            }
            else
            {
                m = 0;
                r[p] = 0;
                printf("%3d", p+1);
            }
        }
        printf("\n");
    }

    return 0;
}

