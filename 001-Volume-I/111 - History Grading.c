/****
 * 111 - History Grading
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 21
int n;
int order[MAX_N];
int event_to_alias[MAX_N];

int input[MAX_N];
int len[MAX_N];
#define MAX(a, b)  ((a) > (b) ? (a) : (b))

int main()
{
    int i, j;
    int grade;
    int t;

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &n);

    /*  index -> event_id, value -> order  */
    /*    =>  array[value] = event_id;     */
    for (i = 0; i < n; i++)
    {
        scanf("%d", &t);
        order[t-1] = i;
    }

    /* using increaing numbers to repersent the event_id */
    for (i = 0; i < n; i++)
        event_to_alias[order[i]] = i;

    while (scanf("%d", &t) != EOF)
    {
        input[t-1] = 0;
        for (i = 1; i < n; i++)
        {
            scanf("%d", &t);
            input[t-1] = i;
        }

        for (i = 0 ; i < n; i++)
            input[i] = event_to_alias[input[i]];

        /* LIS init */
        for (i = 0; i < n; i++)
            len[i] = 1;

        /* LIS */
        for (i = 0 ; i < n; i++)
            for (j = i+1; j < n; j++)
                if (input[i] < input[j])
                {
                    len[j] = MAX(len[j], len[i]+1);
                }

        /* find max len */
        grade = len[0];
        for (i = 1; i < n; i++)
            if (len[i] > grade)
                grade = len[i];

        printf("%d\n", grade);
    }

#ifndef ONLINE_JUDGE
    system("pause");
#endif
  return 0;

}
