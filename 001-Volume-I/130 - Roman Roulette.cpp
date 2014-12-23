#include <cstdio>
#include <cstdlib>

int p[100];
int n, k;
#define EMPTY       -1

int next_position(int current, int step)
{
    for (;;)
    {
        current = (current + 1) % n;
        if (p[current] != EMPTY)
            step --;

        if (step == 0) break;
    }
    return current;
}

int main()
{
    for(;;)
    {
        scanf("%d %d", &n, &k);
        if (n == 0 && k == 0) break;

        if (n != 1)
        {
            for (int i = 0; i < n; i++)
                p[i] = i+1;

            int left = n, current = n - 1, dead;

            while (left != 1)
            {
                int pos_d = next_position(current, k);

                p[pos_d] = EMPTY; // MARK AS DEAD

                int pos_b = next_position(pos_d, k);

                p[pos_d] = p[pos_b];
                p[pos_b] = EMPTY;

                current = pos_d;
                left --;
            }

            int survivor;
            for (int j = 0; j < n; j++)
                if (p[j] != EMPTY)
                {
                    survivor = p[j];
                    break;
                }

            int shift = (n - survivor + 2) % n;
            shift = shift == 0 ? n : shift;
            printf("%d\n", shift);
        }
        else puts("1");
    }

#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}
