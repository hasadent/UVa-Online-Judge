/****
 * 12650 - Dangerous Dive
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 10001

int N, R;
int list[MAX_N];
char yy[MAX_N*3]; /*  */

int main()
{
  int i, j;

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

  while (scanf("%d %d\n", &N, &R) != EOF)
  {
    if (R == N)
    {
      gets(yy);
      puts("*");
      continue;
    }

    for (i = 1; i <= N; i++)
      list[i] = 0;

    for (i = 1; i <= R; i++)
    {
      scanf("%d", &j);
      list[j] = 1;
    }

    for (i = 1; i <=N; i++)
      if (list[i] == 0)
        printf("%d ", i);
    printf("\n");
  }

#ifndef ONLINE_JUDGE
    system("pause");
#endif
  return 0;
}
