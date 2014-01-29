/****
 * 10107 - What is the Median?
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <list>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    list<int> l;
    int n = 0, x;

    while (scanf("%d", &x) != EOF)
    {
        n++;

        list<int>::iterator it;
        for (it = l.begin(); it != l.end() && *it < x; it++);
        l.insert(it, x);

        it = l.begin();
        advance(it, n/2);
        x = *it;
        if ((n & 1) == 0)
        {
            advance(it, -1);
            x = (x + *it) / 2;
        }
        printf("%d\n", x);
    }

    return 0;
}
