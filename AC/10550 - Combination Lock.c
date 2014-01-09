/****
 * 10550 - Combination Lock
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int s, v0, v1, v2;
	int t;
	while (scanf("%d %d %d %d", &s, &v0, &v1, &v2) != EOF && (s+v0+v1+v2) != 0)
	{
		t = 120;
		t += (40 + s - v0) % 40;
		t += (40 + v1 - v0) % 40;
		t += (40 + v1 - v2) % 40;
		t *= 9;
		printf("%d\n", t);
	}
	return 0;
}

