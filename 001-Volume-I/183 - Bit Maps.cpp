/****
 * 183 - Bit Maps
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>

char map[200][200];
int row, col;

void printMap(int r, int c, int rl, int cl)
{
    for (int i = r; i < r+rl; i++)
    {
        for(int j = c; j < c+cl; j++)
        {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

namespace input {

char buf[60] = "\0";
int  p = 0;

inline void drop()
{
    buf[0] = 0;
    p = 0;
}

inline char * getline()
{
    gets(buf);
    return buf;
}

inline char getchar()
{
    if (buf[p] == 0)
    {
        gets(buf);
        p = 0;
    }
    return buf[p++];
}

}; /* namespace input */

namespace output {

int c;
int p;
char r[1000][51];

inline void reset()
{
    c = p = 0;
}

inline void store(char x)
{
    if (p == 50 && x != 0)
    {
        r[c][p] = '\0';
        c += 1;
        p = 0;
    }

    r[c][p++] = x;
}

inline void print()
{
    for (int i = 0; i <= c; i++)
        puts(r[i]);
}

}; /* namespace result */


void B2D_encode(int row_0, int col_0, int rowlen, int collen)
{
    char c   = map[row_0][col_0];
    bool isD = false;
    for (int i = row_0; i < row_0 + rowlen; i++)
        for (int j = col_0; j < col_0 + collen; j++)
            if (c != map[i][j])
            {
                isD = true;
                goto done;
            }
done:
    if (!isD)
    {
        output::store(c);
        return;
    }

    output::store('D');

    if (rowlen == 1)
    {
        int collen_1 = collen / 2;
        int collen_0 = collen - collen_1;
        int col_1 = col_0 + collen_0;

        B2D_encode(row_0, col_0, rowlen, collen_0);
        B2D_encode(row_0, col_1, rowlen, collen_1);
    }
    else if (collen == 1)
    {
        int rowlen_1 = rowlen / 2;
        int rowlen_0 = rowlen - rowlen_1;
        int row_1 = row_0 + rowlen_0;

        B2D_encode(row_0, col_0, rowlen_0, collen);
        B2D_encode(row_1, col_0, rowlen_1, collen);

    }
    else
    {
        int rowlen_1 = rowlen / 2;
        int collen_1 = collen / 2;
        int rowlen_0 = rowlen - rowlen_1;
        int collen_0 = collen - collen_1;
        int row_1 = row_0 + rowlen_0;
        int col_1 = col_0 + collen_0;

        B2D_encode(row_0, col_0, rowlen_0, collen_0);
        B2D_encode(row_0, col_1, rowlen_0, collen_1);
        B2D_encode(row_1, col_0, rowlen_1, collen_0);
        B2D_encode(row_1, col_1, rowlen_1, collen_1);
    }
}

void D2B_encode(int row_0, int col_0, int rowlen, int collen)
{
    char d = input::getchar();

    if (d != 'D')
    {
        for (int i = row_0; i < row_0 + rowlen; i++)
            for (int j = col_0; j < col_0 + collen; j++)
                map[i][j] = d;
        return;
    }

    if (rowlen == 1)
    {
        int collen_1 = collen / 2;
        int collen_0 = collen - collen_1;
        int col_1 = col_0 + collen_0;

        D2B_encode(row_0, col_0, rowlen, collen_0);
        D2B_encode(row_0, col_1, rowlen, collen_1);
    }
    else if (collen == 1)
    {
        int rowlen_1 = rowlen / 2;
        int rowlen_0 = rowlen - rowlen_1;
        int row_1 = row_0 + rowlen_0;

        D2B_encode(row_0, col_0, rowlen_0, collen);
        D2B_encode(row_1, col_0, rowlen_1, collen);

    }
    else
    {
        int rowlen_1 = rowlen / 2;
        int collen_1 = collen / 2;
        int rowlen_0 = rowlen - rowlen_1;
        int collen_0 = collen - collen_1;
        int row_1 = row_0 + rowlen_0;
        int col_1 = col_0 + collen_0;

        D2B_encode(row_0, col_0, rowlen_0, collen_0);
        D2B_encode(row_0, col_1, rowlen_0, collen_1);
        D2B_encode(row_1, col_0, rowlen_1, collen_0);
        D2B_encode(row_1, col_1, rowlen_1, collen_1);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    for (;;)
    {
        char * buf = input::getline();
        char t = buf[0];
        if (t == '#')
            break;

        sscanf(buf+1, "%d %d", &row, &col);
        printf("%c%4d%4d\n", t == 'B' ? 'D' : 'B', row, col);
        input::drop();

        if (t == 'B')
        {
            for (int i = 0; i < row; i++)
                for (int j = 0; j < col; j++)
                    map[i][j] = input::getchar();
            output::reset();
            B2D_encode(0, 0, row, col);
            output::store(0);
            output::print();
        }
        else if (t == 'D')
        {
            D2B_encode(0, 0, row, col);
            output::reset();
            for (int i = 0; i < row; i++)
                for (int j = 0; j < col; j++)
                    output::store(map[i][j]);
            output::store(0);
            output::print();
        }
    }



#ifndef ONLINE_JUDGE
    //system("pause");
#endif
    return 0;
}
