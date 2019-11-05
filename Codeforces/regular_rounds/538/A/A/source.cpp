#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>

int main()
{
	int x, y, z;
	int lmin;
	int a, b, c;

	scanf("%d %d %d", &x, &y, &z);
	scanf("%d %d %d", &a, &b, &c);

	if (a < x)
	{
		printf("NO");

		return 0;
	}

	a -= x;

	b += a;

	if (b < y)
	{
		printf("NO");

		return 0;
	}

	b -= y;

	c += b;

	if (c < z)
	{
		printf("NO");

		return 0;
	}

	printf("YES");

	return 0;
}