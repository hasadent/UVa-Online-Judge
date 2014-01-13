/****
 * 109 - SCUD Busters
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define MAX_K 20
#define MAX_N 100

typedef struct point{
    int x;
    int y;
}point;

inline int counter_clockwise(const point &p0, const point &p1, const point &p2)
{
    return (p1.x - p0.x)*(p2.y - p0.y) - (p1.y - p0.y)*(p2.x - p0.x);
}

class kingdom
{
public:
    int   n;
    point p[MAX_N];
    int   wn;
    point w[MAX_N];
    bool  destroyed;

    kingdom();
    void   find_wall();
    double area();
    bool   inside(const point & x);
};

kingdom::kingdom()
{
    destroyed = false;
}

kingdom * current_kingdom;

bool cmp_miny(const point & a, const point& b)
{
    return (a.y < b.y) || (a.y == b.y && a.x < b.x);
}

bool cmp_angle(const point & a, const point & b)
{
   return counter_clockwise(current_kingdom->p[0], a, b) > 0;
}

void kingdom::find_wall()
{
    swap(p[0], *min_element(p, p + n, cmp_miny));

    current_kingdom = this;
    sort(p + 1, p + n, cmp_angle);
    p[n] = p[0];

    wn = 0;
    for (int i = 0; i <= n; i++)
    {
        while (wn >= 2 && counter_clockwise(w[wn-2], w[wn-1], p[i]) <= 0) wn--;
        w[wn++] = p[i];
    }
}

double kingdom::area()
{
    int area = 0;
    for(int i = 1; i < this->wn; i++)
        area += (this->w[i-1].x * this->w[i].y) - (this->w[i].x * this->w[i-1].y);

    return (double)area / 2;
}

bool kingdom::inside(const point & x)
{
    for (int i = 1; i < this->wn; i++)
        if (counter_clockwise(this->w[i-1],this->w[i], x) <= 0)
        {
            return false;
        }
    return true;
}

kingdom kingdoms[MAX_K];

int main()
{
    int i, k;

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    for (k = 0; ; k++)
    {
        kingdom &kx = kingdoms[k];
        int & n = kx.n;

        scanf("%d", &n);
        if (n == -1)
            break;

        for (i = 0; i < n; i++)
            scanf("%d %d", &kx.p[i].x, &kx.p[i].y);

        kx.find_wall();
    }

    point missle_hit;
    double area = 0.0;
    while (scanf("%d %d", &missle_hit.x, &missle_hit.y) != EOF)
    {
        for (i = 0; i < k; i++)
        {
            kingdom & kx = kingdoms[i];

            if (kx.destroyed)
                continue;

            if (kx.inside(missle_hit))
            {
                area += kx.area();
                kx.destroyed = true;
            }
        }
    }
    printf("%.2lf\n", area);

#ifndef ONLINE_JUDGE
    system("pause");
#endif
  return 0;
}
