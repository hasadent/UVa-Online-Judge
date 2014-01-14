/****
 * 128 - Software CRC
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_S 1032

int main()
{
    int i;
    char * buf, _buf[MAX_S];
    unsigned sum, crc, len;

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    _buf[0] = 0;

    for (;;)
    {
        buf = _buf + 1;
        gets(buf);
        if (buf[0] == '#' && buf[1] == 0)
            break;

        len = strlen(buf);
        buf -= len & 1;

        sum = 0;
        for (i = 0; i < len; i+=2)
            sum = ((sum << 16) + (buf[i] << 8) + buf[i+1]) % 34943;

        sum = (sum << 16) % 34943;
        crc = (34943 - sum) % 34943;
        printf("%02X %02X\n", crc >> 8, crc & 255);
    }

#ifndef ONLINE_JUDGE
    system("pause");
#endif
  return 0;

}
