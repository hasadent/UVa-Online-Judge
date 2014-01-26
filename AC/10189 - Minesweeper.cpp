/****
 * 10189 - Minesweeper
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char map[120][120];
char map_n[120][120];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n, m;

    for (int x = 1; ; x++)
    {
        cin >> n >> m;

        if (n == 0 && m == 0)
            break;

        cin.ignore(1);

        for (int i = 1; i <= n; i++)
        {
            cin.getline(map[i]+1, 110);
        }

        memset(map_n, 0, sizeof(map_n));

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (map[i][j] == '*')
                {
                    map_n[i-1][j-1] += 1;
                    map_n[i-1][j+0] += 1;
                    map_n[i-1][j+1] += 1;
                    map_n[i+0][j-1] += 1;
                    map_n[i+0][j+0] += 1;
                    map_n[i+0][j+1] += 1;
                    map_n[i+1][j-1] += 1;
                    map_n[i+1][j+0] += 1;
                    map_n[i+1][j+1] += 1;
                }

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (map[i][j] != '*')
                    map[i][j] = map_n[i][j] + '0';

        if (x != 1)
            cout << "\n";
        cout << "Field #" << x << ":\n";
        for (int i = 1; i <= n; i++)
            cout << map[i]+1 << endl;

    }

    return 0;
}
