/****
 * 514 - Rails
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
using namespace std;

int a[1001];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    for (;;)
    {
        int n;
        scanf("%d", &n);
        if (n == 0)
            break;

        for (;;)
        {
            scanf("%d", a);
            if (a[0] == 0)
                break;

            for (int i = 1; i < n; i++)
                scanf("%d", &a[i]);

            stack<int> s;
            int i, x = 0;
            for (i = 1; i <= n; i++)
            {
                s.push(i);

                while (!s.empty() && a[x] == s.top())
                {
                    x++;
                    s.pop();
                }
            }

            if (!s.empty())
                puts("No");
            else
                puts("Yes");
        }
        
        puts("");
    }
    return 0;
}
