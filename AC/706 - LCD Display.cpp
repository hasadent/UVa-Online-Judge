/****
 * 706 - LCD Display
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int seg[10][7] = {
/*
 a,b,c,d,e,f,g */
{1,1,1,1,1,1,0}, /*0*/
{0,1,1,0,0,0,0}, /*1*/
{1,1,0,1,1,0,1}, /*2*/
{1,1,1,1,0,0,1}, /*3*/
{0,1,1,0,0,1,1}, /*4*/
{1,0,1,1,0,1,1}, /*5*/
{1,0,1,1,1,1,1}, /*6*/
{1,1,1,0,0,0,0}, /*7*/
{1,1,1,1,1,1,1}, /*8*/
{1,1,1,1,0,1,1}, /*9*/
};

char output[24][108];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int s;
    char num[8];
    for (;;)
    {
        scanf("%d %s\n", &s, num);
        if (s == 0) break;

        //cout << num << endl;

        int r, d;
        for (int i = 0; num[i] != 0; i++)
        {
            int n = num[i] - '0';

            char p[7];
            p[0] = seg[n][0] == 1 ? '-' : ' ';
            p[1] = seg[n][1] == 1 ? '|' : ' ';
            p[2] = seg[n][2] == 1 ? '|' : ' ';
            p[3] = seg[n][3] == 1 ? '-' : ' ';
            p[4] = seg[n][4] == 1 ? '|' : ' ';
            p[5] = seg[n][5] == 1 ? '|' : ' ';
            p[6] = seg[n][6] == 1 ? '-' : ' ';

            d = i * (s + 3);
            r = 0;

            /* row 0 */
            output[r][d] = ' ';
            for (int j = d + 1; j <= d + s; j++)
                output[r][j] = p[0];
            output[r][d+s+1] = ' ';
            output[r][d+s+2] = ' ';

            /* row 1 to s*/
            for (r++; r <= s; r++)
            {
                for (int k = d + 1; k <= d + s; k++)
                    output[r][k] = ' ';

                output[r][d] = p[5];
                output[r][d+s+1] = p[1];
                output[r][d+s+2] = ' ';
            }

            /* row s+1 */
            output[r][d] = ' ';
            for (int j = d + 1; j <= d + s; j++)
                output[r][j] = p[6];
            output[r][d+s+1] = ' ';
            output[r][d+s+2] = ' ';

            /* row s+2 to 2s+2 */
            for (r++; r <= s*2+1; r++)
            {
                output[r][d] = p[4];
                for (int k = d + 1; k <= d + s; k++)
                    output[r][k] = ' ';
                output[r][d+s+1] = p[2];
                output[r][d+s+2] = ' ';
            }

            /* row 2s+3 */
            output[r][d] = ' ';
            for (int j = d + 1; j <= d + s; j++)
                output[r][j] = p[3];
            output[r][d+s+1] = ' ';
            output[r][d+s+2] = ' ';
        }

        for (int i = 0; i < s*2+3; i++)
        {
            output[i][d+s+2] = 0;
        }

        for (int i = 0; i < s*2+3; i++)
            puts(output[i]);
        puts("");
    }

    return 0;
}
