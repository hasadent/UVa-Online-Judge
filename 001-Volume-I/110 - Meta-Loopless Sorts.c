/****
 * 110 - Meta-Loopless Sorts
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 8
int n, m;

#define INSERT_AT(dst, src, loc, value, _i) \
{                                           \
    for (_i = 0; _i < loc; _i++ )           \
        dst[_i] = src[_i];                  \
    dst[_i] = value;                        \
    for (; _i < value; _i++)                \
        dst[_i+1] = src[_i];                \
}

char input_str[MAX_N*3] = "a,b,c,d,e,f,g,h";

const char *fmt0 = "                if %c < %c then\n";
const char *fmt1 = "                else if %c < %c then\n";
const char *fmt2 = "                else";
const char *fmt3 = "                writeln(";

void generate(int *in, int num)
{
    int i, j;
    int local[MAX_N];
    int offset = (8 - num) * 2;

    if (num == n)
    {
        printf(fmt3+offset);
        for (i = 0; i < num-1; i++)
            printf("%c,", 'a'+in[i]);
        printf("%c)\n", 'a'+in[i]);
        return;
    }

    INSERT_AT(local, in, num, num, j);
    printf(fmt0+offset, 'a' + in[num-1], 'a' + num);
    generate(local, num+1);

    for (i = num-1; i > 0; i--)
    {
        INSERT_AT(local, in, i, num, j);
        printf(fmt1+offset, 'a' + in[i-1], 'a'+num);
        generate(local, num+1);
    }

    INSERT_AT(local, in, 0, num, j);
    puts(fmt2+offset);
    generate(local, num+1);
}


int main()
{
    int i;
    int local[MAX_N];

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &m);
    while (m-- > 0)
    {
        scanf("%d", &n);

        input_str[n*2-1] = 0;

        printf("program sort(input,output);\n"
               "var\n"
               "%s : integer;\n"
               "begin\n"
               "  readln(%s);\n",
               input_str, input_str);

        local[0] = 0;
        generate(local, 1);

        puts("end.");

        input_str[n*2-1] = ',';
        if (m != 0)
            puts("");
    }

#ifndef ONLINE_JUDGE
    system("pause");
#endif
  return 0;

}
