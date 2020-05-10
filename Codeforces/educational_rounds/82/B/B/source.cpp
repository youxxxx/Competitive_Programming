#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		long long n, g, b;

		scanf("%lld %lld %lld", &n, &g, &b);

		if (g >= b)
		{
			printf("%lld\n", n);
		}

		else
		{
			long long q, r;

			q = n / (g + b);
			r = n % (g + b);

			long long cur;

			cur = q*g + (r < g ? r : g);

			if (cur * 2 >= n)
			{
				printf("%lld\n", n);
			}

			else
			{
				long long left;

				left = (n + 1) / 2 - cur;

				long long sol;

				sol = n;

				if (r < g)
				{
					long long rem;

					rem = g - r;

					if (rem >= left)
					{
						sol += left;

						printf("%lld\n", sol);

						continue;
					}

					sol += rem + b;

					left -= rem;
				}

				else
				{
					sol += (g + b) - r;
				}

				q = left / g;
				r = left%g;

				sol += q*(g + b) + r;

				if (r == 0)
				{
					sol -= b;
				}

				printf("%lld\n", sol);
			}
		}
	}

	return 0;
}