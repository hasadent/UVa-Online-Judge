/****
 * 139 - Telephone Tangles
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

typedef struct {
    char code[32];
    int code_l;
    char location[64];
    double price;
    int type;
} price;

vector<price> pl;
char buf[1024];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    for (;;)
    {
        price p;

        gets(buf);

        if (strncmp(buf, "000000", 6) == 0)
            break;

        int i, j;
        for (i = 0; buf[i] != ' '; i++)
            p.code[i] = buf[i];
        p.code[i] = 0;
        p.code_l = i;

        p.type = 0;
        if (p.code_l == 2)
            p.type = 1;
        else if (p.code[0] == '0' && p.code[1] == '0')
            p.type = 2;
        else
            p.type = 1;


        for (j = 0, i += 1; buf[i] != '$'; i++, j++)
            p.location[j] = buf[i];
        p.location[j] = 0;

        p.price = static_cast<double>(atoi(buf + i + 1)) / 100;

        pl.push_back(p);
    }

    for (;;)
    {
        scanf("%s", buf);
        if (buf[0] == '#')
            break;

        printf("%-16s", buf);

        int min;
        scanf("%d", & min);

        if (buf[0] != '0')
        {
            printf("Local                   %11s%5d  0.00   0.00\n",
                buf, min);
            continue;
        }

        size_t k, t = -1, l = 0;
        for (k = 0; k < pl.size(); k++)
            if (strncmp(buf, pl[k].code, pl[k].code_l) == 0)
            {
                int x = strlen(buf + pl[k].code_l);

                if ((pl[k].type == 1 && 4 <= x && x <= 7)  ||
                    (pl[k].type == 2 && 4 <= x && x <= 10) &&
                     (l < pl[k].code_l))
                {
                    t = k;
                    l = pl[k].code_l;
                }

            }

        if (t != -1)
        {
            printf("%-24s%11s%5d%6.2lf%7.2lf\n",
                   pl[t].location,
                   buf + pl[t].code_l,
                   min,
                   pl[t].price,
                   pl[t].price * min
                   );
        }
        else
        {
            printf("Unknown                            %5d        -1.00\n", min);
        }
    }

    return 0;
}

