/****
 * 191 - Intersection
 *
 *  Reference:
 *   Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, and Clifford Stein. 2001. 
 *    Introduction to Algorithms, Second Edition. The MIT Press.
 */
#include <stdio.h>
#include <stdlib.h>

#define MIN(a, b)  (a > b ? b : a)
#define MAX(a, b)  (a > b ? a : b)

typedef struct point{
    int x;
    int y;
}point;

point p0, p1;
point rect[4];

#define IS_IN_RANGE(_lb, _ub, _p)    ((_lb) <= (_p) && (_p) <= (_ub))
#define IS_IN_RECT(_x_lb, _x_ub, _y_lb, _y_ub, _x, _y) \
    (IS_IN_RANGE(_x_lb, _x_ub, _x) && IS_IN_RANGE(_y_lb, _y_ub, _y))
#define SET_INTERSECTION_TRUE   { puts("T"); continue; }
#define SET_INTERSECTION_FALSE  { puts("F"); continue; }
#define DIRECTION(_pi, _pj, _pk) \
    ((_pj.x - _pi.x) * (_pk.y - _pi.y) - (_pj.y - _pi.y) * (_pk.x - _pi.x))

int segments_intersect(point p1, point p2, point p3, point p4)
{
    int d1, d2, d3, d4;
    int x_lb, x_ub, y_lb, y_ub;
    d1 = DIRECTION(p3, p4, p1);
    d2 = DIRECTION(p3, p4, p2);
    d3 = DIRECTION(p1, p2, p3);
    d4 = DIRECTION(p1, p2, p4);

    if (d1 * d2 < 0 && d3 * d4 < 0)
    {
        return 1;
    }

    x_lb = MIN(p3.x, p4.x);
    x_ub = MAX(p3.x, p4.x);
    y_lb = MIN(p3.y, p4.y);
    y_ub = MAX(p3.y, p4.y);

    if (d1 == 0 && IS_IN_RECT(x_lb, x_ub, y_lb, y_ub, p1.x, p1.y))
        return 1;
    if (d2 == 0 && IS_IN_RECT(x_lb, x_ub, y_lb, y_ub, p2.x, p2.y))
        return 1;
    if (d3 == 0 && IS_IN_RECT(p1.x, p2.x, p1.y, p2.y, p3.x, p3.y))
        return 1;
    if (d4 == 0 && IS_IN_RECT(p1.x, p2.x, p1.y, p2.y, p4.x, p4.y))
        return 1;

    return 0;
}

int main()
{
    int n;
    int r0, r1, r2, r3;

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &n);
    while (n-- > 0)
    {
        scanf("%d %d %d %d %d %d %d %d",
              &p0.x, &p0.y, &p1.x, &p1.y,
              &r0, &r1, &r2, &r3);

        rect[0].x = rect[1].x = MIN(r0, r2);
        rect[0].y = rect[3].y = MIN(r1, r3);
        rect[2].x = rect[3].x = MAX(r0, r2);
        rect[1].y = rect[2].y = MAX(r1, r3);


        if (IS_IN_RECT(rect[0].x, rect[2].x, rect[0].y, rect[2].y, p0.x, p0.y)
            || IS_IN_RECT(rect[0].x, rect[2].x, rect[0].y, rect[2].y, p1.x, p1.y))
        {
            SET_INTERSECTION_TRUE;
        }
        else
        {
            if (segments_intersect(rect[0], rect[1], p0, p1) == 1)
                SET_INTERSECTION_TRUE;
            if (segments_intersect(rect[1], rect[2], p0, p1) == 1)
                SET_INTERSECTION_TRUE;
            if (segments_intersect(rect[2], rect[3], p0, p1) == 1)
                SET_INTERSECTION_TRUE;
            if (segments_intersect(rect[0], rect[3], p0, p1) == 1)
                SET_INTERSECTION_TRUE;
        }

       SET_INTERSECTION_FALSE;
    }

#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}

