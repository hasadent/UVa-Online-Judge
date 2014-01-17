/****
 * 190 - Circle Through Three Points
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point {
    double x,y;
} point;

int main()
{
    point p1, p2, p3, q1, q2, centre, t;
    double m12, m13, radius;
    double c, d, e;

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (scanf("%lf %lf %lf %lf %lf %lf", &p1.x, &p1.y, &p2.x, &p2.y, &p3.x, &p3.y) != EOF)
    {
        /* mid point of p1 and p2 */
        q1.x = (p1.x + p2.x)/2;
        q1.y = (p1.y + p2.y)/2;

        /* mid point of p1 and p3 */
        q2.x = (p1.x + p3.x)/2;
        q2.y = (p1.y + p3.y)/2;

        if (p1.y == p2.y)
        {
            m13 = (p3.x - p1.x) / (p1.y - p3.y);
            centre.x = q1.x;
            centre.y = m13 * (centre.x - q2.x) + q2.y;
        }
        else if (p1.y == p3.y)
        {
            m12  = (p2.x - p1.x) / (p1.y - p2.y);
            centre.x = q2.x;
            centre.y = m12 * (centre.x - q1.x) + q1.y;
        }
        else
        {
            m12  = (p2.x - p1.x) / (p1.y - p2.y);
            m13  = (p3.x - p1.x) / (p1.y - p3.y);

            centre.x = (q2.y - q1.y - m13 * q2.x + m12 * q1.x) / (m12 - m13);
            centre.y = m12 * (centre.x - q1.x) + q1.y;
        }

        radius = sqrt((centre.x - p1.x)*(centre.x - p1.x) + (centre.y - p1.y) * (centre.y - p1.y));

        c = -2 * centre.x;
        d = -2 * centre.y;
        e = centre.x*centre.x + centre.y*centre.y - radius*radius;

        if (centre.x > 0)
            printf("(x - %.3lf)^2", centre.x);
        else if (centre.x < 0)
            printf("(x + %.3lf)^2", -centre.x);
        else
            printf("x^2");

        if (centre.y > 0)
            printf(" + (y - %.3lf)^2 = %.3lf^2\n", centre.y, radius);
        else if (centre.y < 0)
            printf(" + (y + %.3lf)^2 = %.3lf^2\n", -centre.y, radius);
        else
            printf(" + y^2 = %.3lf^2\n", radius);


        printf("x^2 + y^2");
        if (c < 0)        printf(" - %.3lfx", -c);
        else if (c > 0)   printf(" + %.3lfx",  c);
        if (d < 0)        printf(" - %.3lfy", -d);
        else  if (d > 0)  printf(" + %.3lfy",  d);
        if (fabs(e) > 0.0005)
        {
            if (e < 0)   printf(" - %.3lf", -e);
            else         printf(" + %.3lf", e);
        }

        puts(" = 0\n");
    }

#ifndef ONLINE_JUDGE
    /*system("pause");*/
#endif
    return 0;
}

