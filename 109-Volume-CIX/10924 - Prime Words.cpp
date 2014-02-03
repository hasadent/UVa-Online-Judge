/****
 * 10924 - Prime Words
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int ch[128];
int prime[1041];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    for (int a = 'a'; a <= 'z'; a++)
        ch[a] = a - 'a' + 1;

    for (int a = 'A'; a <= 'Z'; a++)
        ch[a] = a - 'A' + 27;

    memset(prime, 0, sizeof(prime));
    prime[0] = 1;
    prime[1] =  prime[2] = 0;
    for (int i = 2; i <= 1040; i++)
        if (prime[i] == 0)
            for (int j = 2 * i; j <= 1040; j+=i)
                prime[j] = 1;

    char buf[24];

    while (gets(buf) != NULL)
    {
        int sum = 0;
        for (char *p = buf; *p != 0; p++)
            sum += ch[*p];


        if (prime[sum] == 0)
            puts("It is a prime word.");
        else
            puts("It is not a prime word.");

    }
    return 0;
}
