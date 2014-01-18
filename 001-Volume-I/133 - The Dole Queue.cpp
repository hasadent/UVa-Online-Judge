/****
 * 133 - The Dole Queue
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, k, m;

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while(scanf("%d %d %d", &n, &k, &m) != EOF && n != 0)
    {
        int i;
        bool first = true;
        vector<int> cw, ccw;


        for (i = 1; i <= n; i++)
            {cw.push_back(i);}
        for (i = n; i >= 1; i--)
            ccw.push_back(i);

        while (!cw.empty())
        {
            for (i = 1; i < k; i++)
            {
                int x = cw.front();
                cw.erase(cw.begin());
                cw.push_back(x);
            }

            for (i = 1; i < m; i++)
            {
                int x = ccw.front();
                ccw.erase(ccw.begin());
                ccw.push_back(x);
            }

            int x = cw.front();   cw.erase(cw.begin());
            int y = ccw.front();  ccw.erase(ccw.begin());

            if (x != y)
            {
                cw.erase(std::find(cw.begin(), cw.end(), y));
                ccw.erase(std::find(ccw.begin(), ccw.end(), x));
                if(!first)
                    printf(",");
                first = false;
                printf("%3d%3d", x, y);
            }
            else{
                if(!first)
                    printf(",");
                first = false;
                printf("%3d", y);
            }
        }
        puts("");
    }

    return 0;
}
