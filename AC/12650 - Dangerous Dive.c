/****
 * 12650 - Dangerous Dive
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 10001

int N, R;
int list[MAX_N];

int main()
{
  int i, j;

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

  while (scanf("%d %d", &N, &R) != EOF)
  {
    for (i = 1; i <= N; i++)
      list[i] = 0;

    for (i = 1; i <= R; i++)
    {
      scanf("%d", &j);
      list[j] = 1;
    }

    if (R == N)
      puts("*");
    else
    {
      for (i = 1; i <=N; i++)
        if (list[i] == 0)
          printf("%d ", i);
      printf("\n");
    }
  }

#ifndef ONLINE_JUDGE
    system("pause");
#endif
  return 0;
}
