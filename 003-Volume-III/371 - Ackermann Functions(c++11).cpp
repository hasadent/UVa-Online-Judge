/****
 * 371 - Ackermann Functions
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

unsigned int f[10000]= {
0, 3, 1, 7, 2, 5, 8, 16, 3, 19, 6,
14, 9, 9, 17, 17, 4, 12, 20, 20, 7,
7, 15, 15, 10, 23, 10, 111, 18, 18, 18,
106, 5, 26, 13, 13, 21, 21, 21, 34, 8,
109, 8, 29, 16, 16, 16, 104, 11, 24, 24,
24, 11, 11, 112, 112, 19, 32, 19, 32, 19,
19, 107, 107, 6, 27, 27, 27, 14, 14, 14,
102, 22, 115, 22, 14, 22, 22, 35, 35, 9,
22, 110, 110, 9, 9, 30, 30, 17, 30, 17,
92, 17, 17, 105, 105, 12, 118, 25, 25, 25,
25, 25, 87, 12, 38, 12, 100, 113, 113, 113,
69, 20, 12, 33, 33, 20, 20, 33, 33, 20,
95, 20, 46, 108, 108, 108, 46, 7, 121, 28,
28, 28, 28, 28, 41, 15, 90, 15, 41, 15,
15, 103, 103, 23, 116, 116, 116, 23, 23, 15,
15, 23, 36, 23, 85, 36, 36, 36, 54, 10,
98, 23, 23, 111, 111, 111, 67, 10, 49, 10,
124, 31, 31, 31, 80, 18, 31, 31, 31, 18,
18, 93, 93, 18, 44, 18, 44, 106, 106, 106,
44, 13, 119, 119, 119, 26, 26, 26, 119, 26,
18, 26, 39, 26, 26, 88, 88, 13, 39, 39,
39, 13, 13, 101, 101, 114, 26, 114, 52, 114,
114, 70, 70, 21, 52, 13, 13, 34, 34, 34,
127, 21, 83, 21, 127, 34, 34, 34, 52, 21,
21, 96, 96, 21, 21, 47, 47, 109, 47, 109,
65, 109, 109, 47, 47, 8, 122, 122, 122, 29,
29, 29, 78, 29, 122, 29, 21, 29, 29, 42,
42, 16, 29, 91, 91, 16, 16, 42, 42, 16,
42, 16, 60, 104, 104, 104, 42, 24, 29, 117,
117, 117, 117, 117, 55, 24, 73, 24, 117, 16,
16, 16, 42, 24, 37, 37, 37, 24, 24, 86,
86, 37, 130, 37, 37, 37, 37, 55, 55, 11,
24, 99, 99, 24, 24, 24, 143, 112, 50, 112,
24, 112, 112, 68, 68, 11, 112, 50, 50, 11,
11, 125, 125, 32, 125, 32, 125, 32, 32, 81,
81, 19, 125, 32, 32, 32, 32, 32, 50, 19,
45, 19, 45, 94, 94, 94, 45, 19, 19, 45,
45, 19, 19, 45, 45, 107, 63, 107, 58, 107,
107, 45, 45, 14, 32, 120, 120, 120, 120, 120,
120, 27, 58, 27, 76, 27, 27, 120, 120, 27,
19, 19, 19, 27, 27, 40, 40, 27, 40, 27,
133, 89, 89, 89, 133, 14, 133, 40, 40, 40,
40, 40, 32, 14, 58, 14, 53, 102, 102, 102,
40, 115, 27, 27, 27, 115, 115, 53, 53, 115,
27, 115, 53, 71, 71, 71, 97, 22, 115, 53,
53, 14, 14, 14, 40, 35, 128, 35, 128, 35,
35, 128, 128, 22, 35, 84, 84, 22, 22, 128,
128, 35, 35, 35, 27, 35, 35, 53, 53, 22,
48, 22, 22, 97, 97, 97, 141, 22, 48, 22,
141, 48, 48, 48, 97, 110, 22, 48, 48, 110,
110, 66, 66, 110, 61, 110, 35, 48, 48, 48,
61, 9, 35, 123, 123, 123, 123, 123, 61, 30,
123, 30, 123, 30, 30, 79, 79, 30, 30, 123,
123, 30, 30, 22, 22, 30, 22, 30, 48, 43,
43, 43, 136, 17, 43, 30, 30, 92, 92, 92,
43, 17, 136, 17, 30, 43, 43, 43, 87, 17,
43, 43, 43, 17, 17, 61, 61, 105, 56, 105,
30, 105, 105, 43, 43, 25, 30, 30, 30, 118,
118, 118, 30, 118, 56, 118, 118, 118, 118, 56,
56, 25, 74, 74, 74, 25, 25, 118, 118, 17,
56, 17, 69, 17, 17, 43, 43, 25, 131, 38,
38, 38, 38, 38, 69, 25, 131, 25, 131, 87,
87, 87, 131, 38, 25, 131, 131, 38, 38, 38,
38, 38, 30, 38, 30, 56, 56, 56, 131, 12,
51, 25, 25, 100, 100, 100, 38, 25, 144, 25,
100, 25, 25, 144, 144, 113, 51, 51, 51, 113,
113, 25, 25, 113, 51, 113, 144, 69, 69, 69,
95, 12, 64, 113, 113, 51, 51, 51, 64, 12,
64, 12, 38, 126, 126, 126, 38, 33, 126, 126,
126, 33, 33, 126, 126, 33, 126, 33, 64, 82,
82, 82, 170, 20, 33, 126, 126, 33, 33, 33,
64, 33, 25, 33, 25, 33, 33, 51, 51, 20,
46, 46, 46, 20, 20, 46, 46, 95, 33, 95,
139, 95, 95, 46, 46, 20, 139, 20, 20, 46,
46, 46, 95, 20, 90, 20, 46, 46, 46, 46,
139, 108, 20, 64, 64, 108, 108, 59, 59, 108,
33, 108, 152, 46, 46, 46, 59, 15, 33, 33,
33, 121, 121, 121, 152, 121, 33, 121, 59, 121,
121, 121, 121, 28, 121, 59, 59, 28, 28, 77,
77, 28, 77, 28, 103, 121, 121, 121, 72, 28,
59, 20, 20, 20, 20, 20, 72, 28, 46, 28,
134, 41, 41, 41, 134, 28, 41, 41, 41, 28,
28, 134, 134, 90, 134, 90, 41, 90, 90, 134,
134, 15, 28, 134, 134, 41, 41, 41, 85, 41,
41, 41, 41, 41, 41, 33, 33, 15, 59, 59,
59, 15, 15, 54, 54, 103, 28, 103, 147, 103,
103, 41, 41, 116, 147, 28, 28, 28, 28, 28,
178, 116, 147, 116, 28, 54, 54, 54, 147, 116,
116, 28, 28, 116, 116, 54, 54, 72, 147, 72,
46, 72, 72, 98, 98, 23, 67, 116, 116, 54,
54, 54, 116, 15, 67, 15, 54, 15, 15, 41,
41, 36, 129, 129, 129, 36, 36, 129, 129, 36,
129, 36, 67, 129, 129, 129, 116, 23, 129, 36,
36, 85, 85, 85, 129, 23, 173, 23, 85, 129,
129, 129, 36, 36, 36, 36, 36, 36, 36, 28,
28, 36, 28, 36, 28, 54, 54, 54, 129, 23,
49, 49, 49, 23, 23, 23, 142, 98, 49, 98,
36, 98, 98, 142, 142, 23, 98, 49, 49, 23,
23, 142, 142, 49, 23, 49, 36, 49, 49, 98,
98, 111, 93, 23, 23, 49, 49, 49, 49,
};
size_t fsize = 1000;

inline unsigned int func(int n)
{
    if (n < fsize)
        return f[n];

    unsigned int c = 0;
    for (unsigned int k = n; k != 1; c++)
    {
        if ((k & 1) == 0)
            k /= 2;
        else
            k = k * 3 + 1;

        if (k < fsize)
            return c + f[k] + 1;
    }
    return c;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    for (; fsize < 10000; fsize++)
        f[fsize] = func(fsize);

    unsigned int L, H, V, S;
    for (;;)
    {
        scanf("%d %d", &L, &H);
        if (L == 0) break;
        if (L > H) swap(L, H);

        S = V = 0;
        for (unsigned int i = L; i <= H; i++)
        {
            unsigned int c = func(i);
            if (c > S)
            {
                S = c;
                V = i;
            }
        }

        printf("Between %d and %d, %d generates the longest sequence of %d values.\n",
               L, H, V, S);
    }

    return 0;
}
