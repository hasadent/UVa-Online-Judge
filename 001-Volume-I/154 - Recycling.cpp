/****
 * 154 - Recycling
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int ascii[128];
int city[100][5];


int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ascii['P'] = 0;
    ascii['G'] = 1;
    ascii['S'] = 2;
    ascii['A'] = 3;
    ascii['N'] = 4;
    ascii['r'] = 0;
    ascii['o'] = 1;
    ascii['y'] = 2;
    ascii['g'] = 3;
    ascii['b'] = 4;

   for (bool done = false;;)
    {
        int n;
        char buf[20];
        for (n = 0; ; n++)
        {
            gets(buf);
            if (buf[0] == 'e') break;
            if (buf[0] == '#') { done = true;  break; }

            for (char * p = buf; ;p+=4)
            {
                int color = ascii[p[0]];
                int waste = ascii[p[2]];

                city[n][waste] = color;

                if (p[3] == 0) break;
            }
        }

        if (done)
            break;

        int min = 5000; int min_city = -1;
        for (int i = 0; i < n; i++)
        {
            int noc = 0;
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                for (int k = 0; k < 5; k++)
                    noc += city[i][k] != city[j][k] ? 1 : 0;
            }


            if (noc < min)
            {
                min = noc;
                min_city = i;
            }
        }

        printf("%d\n", min_city+1);

    }

    return 0;
}

