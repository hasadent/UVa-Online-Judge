/****
 * 653 - Gizilch
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int visited[101];
long long a, b;
bool second_player;
bool indivisible;

int dfs(long long n, int start)
{
    if (n == 1)
    {
        indivisible = false;

        if (second_player)
            return 1;

        second_player = true;
        if (dfs(a, 2) == 1)
            return 1;
        second_player = false;

        return 0;
    }

    for (int i = start; i <= 100; i++)
        if (visited[i] == 0 && n % i == 0)
        {
            visited[i] = 1;
            if (dfs(n/i, i) != 0)
                return 1;
            visited[i] = 0;
        }

    return 0;

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (cin >> a >> b)
    {
        memset(visited, 0, sizeof(visited));

        if (a < b)
        {
            long long t = b;
            b = a;
            a = t;
        }

        second_player = false;
        indivisible = true;
        /* 1. if b is indivisible ....................... a win
           2. if dfs(b, 2) -> dfs(a, 2) are 1, a and b
              can be divided by non duplicated numbers
              in 1~100 .................................. a win
           3. else ...................................... b win  */
        if (dfs(b, 2) == 1 || indivisible)
            cout << a << endl;
        else
            cout << b << endl;
    }



    return 0;
}
