/****
 * 484 - The Department of Redundancy Department
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    map<int, int> m;
    vector<int> v;

    int n;
    while (scanf("%d", &n) != EOF)
    {
        if (m.count(n) != 0)
            m[n] += 1;
        else
        {
            m[n] = 1;
            v.push_back(n);
        }
    }

    for (int i : v)
        printf("%d %d\n", i, m[i]);

    return 0;
}
