/****
 * 143 - Orchard Trees
 */
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef struct {
    int x, y;
} point_t;

#define MULTIPLE 100
#define MAX2(_a, _b)       (_a > _b ? _a : _b)
#define MAX3(_a, _b, _c)   MAX2(_a, MAX2(_b, _c))
#define MIN2(_a, _b)       (_a < _b ? _a : _b)
#define MIN3(_a, _b, _c)   MIN2(_a, MIN2(_b, _c))

inline int cross_product(const point_t &p0, const point_t &p1, const point_t &p2)
{
    return (p1.x - p0.x)*(p2.y - p0.y) - (p1.y - p0.y)*(p2.x - p0.x);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    point_t p[3];

    for (;;)
    {
        double p0x, p0y, p1x, p1y, p2x, p2y;
        scanf("%lf%lf%lf%lf%lf%lf", &p0x, &p0y, &p1x, &p1y, &p2x, &p2y);

        p[0].x = (int)(p0x * MULTIPLE + 0.5);
        p[0].y = (int)(p0y * MULTIPLE + 0.5);
        p[1].x = (int)(p1x * MULTIPLE + 0.5);
        p[1].y = (int)(p1y * MULTIPLE + 0.5);
        p[2].x = (int)(p2x * MULTIPLE + 0.5);
        p[2].y = (int)(p2y * MULTIPLE + 0.5);

        if (p[0].x == 0 && p[0].y == 0
            && p[1].x == 0 && p[1].y == 0
            && p[2].x == 0 && p[2].y == 0)
            break;

        int right  = MAX3(p[0].x, p[1].x, p[2].x);
        int left   = MIN3(p[0].x, p[1].x, p[2].x);
        int top    = MAX3(p[0].y, p[1].y, p[2].y);
        int bottom = MIN3(p[0].y, p[1].y, p[2].y);

        // ceil and floor
        right = right / MULTIPLE * MULTIPLE;
        if (left % MULTIPLE != 0)
            left =  (left / MULTIPLE + 1) * MULTIPLE;
        top = top / MULTIPLE * MULTIPLE;
        if (bottom % MULTIPLE != 0)
            bottom =  (bottom / MULTIPLE + 1) * MULTIPLE;

        // check boundary
        right  = right  > 99 * MULTIPLE ? 99 * MULTIPLE : right;
        left   = left   <  1 * MULTIPLE ?  1 * MULTIPLE : left;
        top    = top    > 99 * MULTIPLE ? 99 * MULTIPLE : top;
        bottom = bottom <  1 * MULTIPLE ?  1 * MULTIPLE : bottom;

        if (cross_product(p[0], p[1], p[2]) < 0)
        {
            point_t t = p[0];
            p[0] = p[1];
            p[1] = t;
        }

        int inside_point = 0;
        for (int i = left; i <= right; i += MULTIPLE)
        {
            for (int j = bottom; j <= top; j += MULTIPLE)
            {
                point_t px = {i, j};

                if ( cross_product(px, p[0], p[1]) < 0
                  || cross_product(px, p[1], p[2]) < 0
                  || cross_product(px, p[2], p[0]) < 0)
                { }
                else
                {
                    inside_point += 1;
                }
            }
        }
        printf("%4d\n", inside_point);
    }

    return 0;
}

