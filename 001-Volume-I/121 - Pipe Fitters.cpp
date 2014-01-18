/****
 * 121 - Pipe Fitters
 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
const float sqrt3_2 = 0.86602540378443864675;

int get_skew(float w, float h)
{
    if (h < 1.0 || w < 1.0)
        return 0;

    int ph =  1 + (int)((h - 1) / sqrt3_2);
    int pw = (int)w;
    return ph * pw - (w - pw < 0.5 ? ph/2 : 0);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    float x, y;

    while (scanf("%f %f", &x, &y) != EOF)
    {
        int grid  = (int)x * (int)y;
        int skew  = max(get_skew(x, y), get_skew(y, x));

        if (grid >= skew)
            printf("%d grid\n", grid);
        else
            printf("%d skew\n", skew);
    }
    
    return 0;
}

