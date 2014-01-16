/****
 * 145 - Gondwanaland Telecom
 */
#include <stdio.h>
#include <stdlib.h>


double charges [5][3] =
 {
      {0.10, 0.06, 0.02},
      {0.25, 0.15, 0.05},
      {0.53, 0.33, 0.13},
      {0.87, 0.47, 0.17},
      {1.44, 0.80, 0.30},
 };

#define AM0800    8*60
#define PM0600   18*60
#define PM1000   22*60
#define NEXT_DAY_AM0800 32*60
#define NEXT_DAY_PM0600 42*60
#define NEXT_DAY_PM1000 46*60
#define NEXT_DAY_AM1200 48*60
int time[7] = { 
  AM0800, PM0600, PM1000, 
  NEXT_DAY_AM0800, NEXT_DAY_PM0600, NEXT_DAY_PM1000, NEXT_DAY_AM1200 
};
int min[3];

int main()
{
    char step;
    char tel_num[10];
    int hhs, mms, hhe, mme;
    int time_start, time_end;
    int i;
    double *charge, cost;

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while ( scanf("%c", &step) != EOF && step != '#')
    {
        scanf("%s %d %d %d %d\n", tel_num, &hhs, &mms, &hhe, &mme);

        time_start = mms + hhs * 60;
        time_end   = mme + hhe * 60;
        if (time_end <= time_start)
            time_end += 24*60;

        min[0] = min[1] = min[2] = 0;

        for (i = 0; i < 7 ; i++)
        {
            if (time_end <= time[i])
            {
                min[i%3] += time_end - time_start;
                time_start = time_end;
                break;
            }

            if (time_start <= time[i])
            {
                min[i%3] += time[i] - time_start;
                time_start = time[i];
            }
        }

        charge = charges[step-'A'];
        cost = min[0] * charge[2] + min[1] * charge[0] + min[2] * charge[1];
        printf("%10s%6d%6d%6d%3c%8.2f\n", tel_num, min[1], min[2], min[0], step, cost);
    }

#ifndef ONLINE_JUDGE
    //system("pause");
#endif
    return 0;
}


