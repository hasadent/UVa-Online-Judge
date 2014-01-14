/****
 * 114 - Simulation Wizardry
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_G 52
#define MAX_B 49*49

int grid[MAX_G][MAX_G];
int n, m;

typedef struct bumper
{
    int v;
    int c;
} bumper;

bumper bumpers[MAX_B];
int b;

#define RIGHT 0
#define LEFT  2
#define UP    1
#define DOWN  3

const int next_direction[4] = {   DOWN,  RIGHT,     UP,   LEFT };
/*                            | RIGHT |    UP |  LEFT |  DOWN  */
const int x_move[4]         = {      1,      0,     -1,      0 };
const int y_move[4]         = {      0,      1,      0,     -1 };

int main()
{
    int wall_cost;
    int direction;
    int lifetime;

    int total_value;
    int value;
    int x, y, new_x, new_y;
    int i;

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    memset(grid, 0, sizeof(grid));

    scanf("%d %d", &m, &n);
    scanf("%d", &wall_cost);
    scanf("%d", &b);

    for (i = 1; i <= b; i+=1)
    {
        scanf("%d %d %d %d", &x, &y, &bumpers[i].v, &bumpers[i].c);
        grid[x][y] = i;
    }

    total_value = 0;
    while (scanf("%d %d %d %d", &x, &y, &direction, &lifetime) != EOF)
    {
        value = 0;
        while (--lifetime > 0)
        {
            new_x = x + x_move[direction];
            new_y = y + y_move[direction];

            /* hit a wall */
            if (new_x == m ||  new_y == n || new_x == 1 || new_y == 1)
            {
                lifetime -= wall_cost;
                direction = next_direction[direction];
                continue;
            }

            /* hit a bumper */
            if ((i = grid[new_x][new_y]) != 0)
            {
                lifetime -= bumpers[i].c;
                value    += bumpers[i].v;
                direction = next_direction[direction];
                continue;
            }

            x = new_x;
            y = new_y;
        } /* while (lifetime >= 0) */

        printf("%d\n", value);
        total_value += value;
    } /* while scanf */
    printf("%d\n", total_value);

#ifndef ONLINE_JUDGE
    system("pause");
#endif
  return 0;
}
