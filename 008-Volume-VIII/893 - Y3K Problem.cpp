/****
 * 183 - Bit Maps
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace def{

const int y_days[2] = { 365, 366 };
const int m_days[2][12] =
{
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};
const int yf_days[2][12] = {
{  0,  31,  59,  90, 120, 151, 181, 212, 243, 273, 304, 334},
{  0,  31,  60,  91, 121, 152, 182, 213, 244, 274, 305, 335}};

}; /* namespace def */

int is_leap_year(int y)
{
    if ((y % 400) == 0) return 1;
    if ((y % 100) == 0) return 0;
    if ((y % 4) == 0) return 1;
    return 0;
}


int pd;
int dd, mm, yy;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    for (;;)
    {
        scanf("%d %d %d %d", &pd, &dd, &mm, &yy);
        if (pd == 0 && dd == 0 && mm == 0 && yy == 0)
            break;

        /* convert current day to first day of year */
        pd += dd - 1 + def::yf_days[is_leap_year(yy)][mm-1];
        dd = 1;
        mm = 1;

        for (;;)
        {
            int days = def::y_days[is_leap_year(yy)];
            if (pd < days) break;

            pd -= days;
            yy += 1;
        }

        const int * m_days = def::m_days[is_leap_year(yy)];
        for (int i = 0;;i++)
        {
            int days = m_days[i];
            if (pd < days) break;

            pd -= days;
            mm += 1;
        }

        dd += pd;
        pd = 0;

        printf("%d %d %d\n", dd, mm, yy);
    }

#ifndef ONLINE_JUDGE
    //system("pause");
#endif
    return 0;
}
