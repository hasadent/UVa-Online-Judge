/****
 * 138 - Street Numbers
 */
#include <stdio.h>
#include <stdlib.h>

const char output [] = {
"         6         8\n"
"        35        49\n"
"       204       288\n"
"      1189      1681\n"
"      6930      9800\n"
"     40391     57121\n"
"    235416    332928\n"
"   1372105   1940449\n"
"   7997214  11309768\n"
"  46611179  65918161"
};

int main()
{
    long long int n, k;
    double ck;
    double sq = sqrt(2);
    int s;

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

#if CACULATION
    for (n = 8, s = 0; s < 10; n ++)
    {
        ck = ((double)n + 0.5) / sq;
        /*printf("k = %lf\n", ck);*/
        for (k = floor(ck)-1; k <= ceil(ck)+1; k ++)
        {
            if (2 * k * k == n * n + n)
            {
                printf("%10lld", k);
                printf("%10lld\n", n);
                s ++;
                break;
            }
        }
    }
#endif

    puts(output);

#ifndef ONLINE_JUDGE
    /*system("pause");*/
#endif
    return 0;
}

