/****
 * 10327 - Flip Sort
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    vector<int> v;

    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            int x;
            scanf("%d", &x);
            v.push_back(x);
        }

        int sum = 0;
        while (!v.empty())
        {
            int d = distance(v.begin(), min_element(v.begin(), v.end()));
            sum += d;
            v.erase(v.begin() + d);
        }

        printf("Minimum exchange operations : %d\n", sum);
    }

    return 0;
}

