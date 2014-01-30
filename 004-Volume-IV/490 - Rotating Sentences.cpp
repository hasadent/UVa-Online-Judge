/****
 * 490 - Rotating Sentences
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

char input[102][102];
char output[102][102];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n, m = 0;
    for (n = 0; gets(input[n]) != NULL; n++)
    {
        int l = strlen(input[n]);
        if (l > m) m = l;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = strlen(input[i]); j < m; j++)
            input[i][j] = ' ';
        input[i][m] = 0;
    }

    for (int i = 0; i < m; i++)
        input[n][i] = 0;

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
        {
            //cout << input[i][j] << " -- " << input[j][i] << endl;
            output[j][n-i-1] = input[i][j];
        }

    for (int i = 0; i < m; i++)
        puts(output[i]);

    return 0;
}
