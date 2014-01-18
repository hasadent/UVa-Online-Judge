/****
 * 152 - Tree's a Crowd
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
#define MAX_TREE 5000
#define MIN2(_a, _b)   (_a > _b ? _b : _a)
#define POW2(_a)       ((_a) * (_a))

typedef struct{
    int    set;
    int    x, y, z;
    int    d_square;
} tree;

tree t[MAX_TREE];
int  n;
int  histogram[11];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    for (n = 0; ; n++)
    {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);

        if (x == 0 && y == 0 && z == 0)
            break;

        t[n].x = x; t[n].y = y; t[n].z = z;
        t[n].d_square = 0x40000;
        t[n].set = 0;
    }

    memset(histogram, 0, sizeof(histogram));

    int j;
    for (int i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            if (i != j && t[i].set == 0)
            {
                if (t[i].x == t[j].x && t[i].y == t[j].y && t[i].z == t[j].z)
                {
                    t[i].d_square = t[j].d_square = 0;
                    t[i].set = t[j].set = 1;
                    break;
                }
                else
                {
                    int ds = POW2(t[i].x - t[j].x) + POW2(t[i].y - t[j].y) + POW2(t[i].z - t[j].z);
                    t[i].d_square = MIN2(t[i].d_square, ds);
                }
            }

        int d = sqrt(t[i].d_square);
        if (d < 10)
            histogram[d] += 1;
    }

    for (int i = 0; i < 10; i++)
        printf( "%4d", histogram[i]);
    printf("\n");

    return 0;
}

