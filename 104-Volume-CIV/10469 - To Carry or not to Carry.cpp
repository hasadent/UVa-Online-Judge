/****
 * 10469 - To Carry or not to Carry
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int a, b;
    while (scanf("%d %d", &a, &b) != EOF)
    {
        printf("%d\n", a ^ b);
    }
    return 0;
}
