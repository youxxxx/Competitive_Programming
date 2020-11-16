#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<functional>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		long long n, x, y;

		scanf("%lld %lld %lld", &n, &x, &y);

		if (n == 2)
		{
			printf("%lld %lld\n", x, y);

			continue;
		}

		if (y < n)
		{
			for (long long i = 1; i <= n; i++)
			{
				printf("%lld ", i);
			}

			printf("\n");

			continue;
		}

		/*
		if (y - x > n - 1)
		{
			long long divd = y - x;

			for (long long i = (y - x) / (n - 1); i <= y - x; i++)
			{
				if (!((y - x) % i) && (y-x) >= n - 1)
				{
					divd = i;

					break;
				}
			}

			long long left = n - ((y - x) / divd + 1);

			long long lmin = min((x - 1) / divd, left);

			left -= lmin;

			long long start = x - lmin*divd;
			long long end = y + left*divd;

			for (long long i = start; i <= end; i += divd)
			{
				printf("%lld ", i);
			}

			printf("\n");

			continue;
		}
		*/


		if (y - x > n - 1)
		{
			long long a, b;
			long long lmin = 999999999999;

			for (long long i = 1; i <= x; i++)
			{
				for (long long j = 1; j <= 50; j++)
				{
					if (i + j*(n - 1) < y || (x - i) % j || (y - i) % j)
					{
						continue;
					}

					if (i + j*(n - 1) < lmin)
					{
						lmin = i + j*(n - 1);
						a = i;
						b = j;
					}
				}
			}

			for (long long i = a; i <= a + b*(n - 1); i += b)
			{
				printf("%lld ", i);
			}

			printf("\n");

			continue;
		}

		for (long long i = y - n + 1; i <= y; i++)
		{
			printf("%lld ", i);
		}

		printf("\n");
	}

	return 0;
}