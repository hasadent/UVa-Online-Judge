/****
 * 256 - Quirksome Squares
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int v2 [5] = {0,100,10000,1000000,100000000};
const int v1 [5] = {0, 10,  100,   1000,    10000};
const char * fmt[5] = {0,"%02d\n","%04d\n","%06d\n","%8d\n"};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    int n;
    while (scanf("%d", &n) != EOF)
    {
        n >>= 1;

        for (int i = 0; i < v2[n]; i++)
        {
            int x = i / v1[n];
            int y = i % v1[n];


            if ((x+y)*(x+y) == i)
                printf(fmt[n], i);
        }
    }

    return 0;
}

