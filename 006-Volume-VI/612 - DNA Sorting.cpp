/****
 * 612 - DNA Sorting
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

char input[100][51];
char g [] = "ACGT";

int cost[100];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t, n, m;
    scanf("%d", &t);
    while (t-- > 0)
    {
        scanf("%d %d\n", &n, &m);
        for (int i = 0; i < m ; i++)
        {
            gets(input[i]);

            vector<char> v;

            for (int j = 0; j < n; j++)
                v.push_back(input[i][j]);

            cost[i] = 0;
            for (int j = 0; j < 4; j++)
            {
                vector<char>::iterator it;
                while ((it = find(v.begin(), v.end(), g[j])) != v.end())
                {
                    cost[i] += distance(v.begin(), it);
                    v.erase(it);
                }
            }
            //cout << "cost[" << i <<  "]= " << cost[i] << endl;

        }

        for (int i = 0; i < m ; i++)
        {
            int c = 2000, k;
            for (int j = 0; j < m; j++)
                if (c > cost[j])
                {
                    c = cost[j];
                    k = j;
                }

            cost[k] = 20000;
            puts(input[k]);
        }

        if (t > 0)
            puts("");
    }

    return 0;
}
