#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int tc, cases;
	int n;
	int i;
	long long dmax, smax;
	long long d, h;
	long long x;

	//freopen("input.txt", "r", stdin);

	scanf("%d", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		scanf("%d %lld", &n, &x);

		smax = -1;
		dmax = 0;

		for (i = 0; i < n; i++)
		{
			scanf("%lld %lld", &d, &h);

			if (d - h > smax)
			{
				smax = d - h;
			}

			if (d > dmax)
			{
				dmax = d;
			}
		}

		if (dmax >= x)
		{
			printf("1\n");

			continue;
		}

		if (smax <= 0)
		{
			printf("-1\n");

			continue;
		}

		printf("%lld\n", (x - dmax + smax - 1) / smax + 1);
	}

	return 0;
}