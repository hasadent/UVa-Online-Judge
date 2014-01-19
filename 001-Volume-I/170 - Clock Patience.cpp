/****
 * 170 - Clock Patience
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <deque>
using namespace std;

const int ascii [128] {
/* 0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F          */
  -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, /* 0x0? */
  -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, /* 0x1? */
  -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, /* 0x2? */
  -1,-1, 1, 2, 3, 4, 5, 6, 7, 8, 9,-1,-1,-1,-1,-1, /* 0x3? */
  -1, 0,-1,26,13,-1,-1,-1, 0,-1,10,12,-1,-1,-1,-1, /* 0x4? */
  -1,11,-1,39, 9,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, /* 0x5? */
};
const char rank [] = "A23456789TJQK";
const char suit [] = "HDCS";

int deck_take[12];
deque<int> decks[13];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    for (bool done = false;;)
    {
        char input[4];
        for (int i = 51; i >= 0; i--)
        {
            scanf("%s", input);

            if (input[0] == '#')
            { done = true; break; }

            char x = input[0];
            char y = input[1];
            decks[i%13].push_front(ascii[x] + ascii[y]);
        }

        if (done) break;

        memset(deck_take, 0, sizeof(deck_take));

        int c = decks[12].back();
        decks[12].pop_back();
        deck_take[12] = 1;

        int i;
        for (i = 1;; i++)
        {
            int r = c % 13;
            if (deck_take[r]== 4)
                break;
            deck_take[r] += 1;

            c = decks[r].back();
            decks[r].pop_back();
        }
        printf("%02d,%c%c\n", i, rank[c%13], suit[c/13]);

        for (int i = 0; i < 13; i++)
            decks[i].clear();
    }

    return 0;
}

