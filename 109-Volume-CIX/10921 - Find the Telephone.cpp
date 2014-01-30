/****
 * 10921 - Find the Telephone
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char ch[128];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ch['0'] = '0';
    ch['1'] = '1';
    ch['2'] = ch['A'] = ch['B'] = ch['C'] = '2';
    ch['3'] = ch['D'] = ch['E'] = ch['F'] = '3';
    ch['4'] = ch['G'] = ch['H'] = ch['I'] = '4';
    ch['5'] = ch['J'] = ch['K'] = ch['L'] = '5';
    ch['6'] = ch['M'] = ch['N'] = ch['O'] = '6';
    ch['7'] = ch['P'] = ch['Q'] = ch['R'] = ch['S'] = '7';
    ch['8'] = ch['T'] = ch['U'] = ch['V'] = '8';
    ch['9'] = ch['W'] = ch['X'] = ch['Y'] = ch['Z'] = '9';
    ch['-'] = '-';
    char buf[100];


    while (gets(buf) != NULL)
    {
        for (char *p = buf; *p != 0; p++)
            *p = ch[*p];
        puts(buf);
    }

    return 0;
}
