/****
 * 162 - Beggar My Neighbour
 */
#include <iostream>
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
const int card_of_rank[13] = {4,0,0,0,0,0,0,0,0,0,1,2,3};

deque<int> decks[3];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;

    for (bool done = false; ;)
    {
        char input[4];
        for (int i = 51; i >= 0; i--)
        {
            scanf("%s", input);

            if (input[0] == '#')
            { done = true; break; }

            char x = input[1];
            char y = input[0];
            decks[i&1].push_back(ascii[x] + ascii[y]);
        }

        if (done)
            break;

#define SWITCH_PLAYER()    { turn ^= 1; /*printf("%s's turn\n", turn == 1 ? "Dealer" : "Non-dealer");*/ }
        int turn = 1, has_loser = 0;;
        for(;;)
        {
            if (decks[turn].empty())
                break;

            int now = decks[turn].back();
            decks[turn].pop_back();
            decks[2].push_back(now);
            //printf("%c%c\n", suit[now/13], rank[now%13]);

            SWITCH_PLAYER();

            int draw_card = card_of_rank[now % 13];
            if (draw_card == 0)
                continue;

            while (draw_card > 0)
            {
                while (draw_card-- > 0)
                {
                    if (decks[turn].empty())
                    {
                        has_loser = 1;
                        break;
                    }
                    now = decks[turn].back();
                    //printf("> draw_%d %c%c\n", draw_card+1, suit[now/13], rank[now%13]);
                    decks[turn].pop_back();
                    decks[2].push_back(now);

                    /* draw a face card */
                    if (card_of_rank[now % 13] != 0)
                    {
                        SWITCH_PLAYER();
                        draw_card = card_of_rank[now % 13];
                        break;
                    }
                }

                if (has_loser)
                    break;
            }

            if (has_loser)
                break;

            SWITCH_PLAYER();
            //printf("> get all cards\n");
            while (!decks[2].empty())
            {
                decks[turn].push_front(decks[2].front());
                decks[2].pop_front();
            }
        }

        printf("%d%3d\n", (turn^1)+1, decks[turn^1].size());

        decks[0].clear();
        decks[1].clear();
        decks[2].clear();
    }

    return 0;
}

