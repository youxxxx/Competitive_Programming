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

	scanf("%lld", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		long long n, m;

		scanf("%lld %lld", &n, &m);

		m++;

		long long sol = -1;

		const long long left = (n - (m - 1)*m / 2);

		if (left >= 0 && !(left%m))
		{
			long long base = left / m;

			if (base >= 0)
			{
				for (long long i = 0; i <= 10 - m; i++)
				{
					const long long ls = i;

					if (ls > base)
					{
						continue;
					}

					long long left = base - ls;

					long long cand = left % 9;

					left -= cand;

					for (long long j = 0; j < left / 9; j++)
					{
						cand = cand * 10 + 9;
					}

					cand = cand * 10 + ls;

					if (sol == -1 || cand < sol)
					{
						sol = cand;
					}
				}
			}
		}

		for (long long i = 1; i < m; i++)
		{
			for (long long j = 1; j <= 20; j++)
			{
				const long long diff = i*(j * 9);
				const long long tot = n + diff;

				bool valid = false;

				if (m % 2)
				{
					if (tot > 0)
					{
						const long long q = tot / m;

						if (q*m == tot)
						{
							valid = true;
						}
					}
				}

				else
				{
					if (tot > 0)
					{
						const long long q = tot / (m / 2);

						if (q % 2 && q*(m / 2) == tot)
						{
							valid = true;
						}
					}
				}

				if (!valid)
				{
					continue;
				}

				long long left = tot - (m - 1)*m / 2;

				if (left < 0)
				{
					continue;
				}

				long long base = left / m;

				if (base*m != left)
				{
					continue;
				}

				const long long ls = (10 - (m - i)) % 10;
				const long long sum = ls + (j - 1) * 9;

				if (sum > base)
				{
					continue;
				}

				long long left2 = base - sum;
				long long cnt = 0;

				long long cand;

				if (left2 < 9)
				{
					cand = left2;
				}

				else
				{
					left2 -= 8;

					while (left2 > 9)
					{
						left2 -= 9;

						cnt++;
					}

					cand = left2;

					for (long long k = 0; k < cnt; k++)
					{
						cand = cand * 10 + 9;
					}

					cand = cand * 10 + 8;
				}

				for (long long k = 0; k < j - 1; k++)
				{
					cand = cand * 10 + 9;
				}

				cand = cand * 10 + ls;

				if (sol == -1 || cand < sol)
				{
					sol = cand;
				}
			}
		}

		printf("%lld\n", sol);
	}

	return 0;
}