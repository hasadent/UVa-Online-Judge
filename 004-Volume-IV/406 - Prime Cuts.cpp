/****
 * 406 - Prime Cuts
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

int prime[1001];
vector<int> p;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    memset(prime, 0, sizeof(prime));
    prime[0] = 1;
    prime[1] = 0;
    prime[2] = 0;

    p.push_back(1);
    for (int i = 2; i <= 1000; i++)
        if (prime[i] == 0)
        {
            p.push_back(i);
            for (int j = i*2; j <= 1000; j+=i)
                prime[j] = 1;
        }


    int n, c;
    while (scanf("%d %d", &n, &c) != EOF)
    {
        size_t k;
        for (k = 0; k < p.size(); k++)
            if (p[k] > n)
                break;
        k --;

        int s, e;
        if ((k & 1) == 1)
        {
            if (k < 2 * c - 1 )
            { s = 0, e = k; }
            else
            {
                s = k / 2 - c + 1;
                e = k / 2 + c ;
            }
        }
        else
        {
            if (k < 2 * c)
            { s = 0, e = k; }
            else
            {
                s = k / 2 - c + 1;
                e = k / 2 + c - 1;
            }
        }

        printf("%d %d:", n, c);
        for (int i = s; i <= e; i++)
            printf(" %d", p[i]);
        printf("\n\n");

    }
    return 0;
}
