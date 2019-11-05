#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<functional>


int main()
{
	int n, a, b, x, y;
	int dis1, dis2;
	int bound;
	int i;

	scanf("%d %d %d %d %d", &n, &a, &x, &b, &y);

	if (a == b)
	{
		printf("YES\n");

		return 0;
	}

	a--;
	b--;
	x--;
	y--;

	dis1 = (n + x - a) % n;
	dis2 = (n + b - y) % n;

	bound = dis1 < dis2 ? dis1 : dis2;

	for (i = 0; i < bound; i++)
	{
		a = (a + 1) % n;
		b = (b + n - 1) % n;

		if (a == b)
		{
			printf("YES\n");

			return 0;
		}
	}

	printf("NO\n");

	return 0;
}