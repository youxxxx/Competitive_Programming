#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int main()
{
	int tc, cases;
	int n;
	int ub;
	int i, j;
	int bit;
	long long p[40], w[40], v[40];
	long long cand, acc, sol, lmax;
	map<long long, long long> list[2];
	map<long long, long long>::iterator it,ret;

	scanf("%d", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		scanf("%d", &n);

		for (i = 0; i < n; i++)
		{
			scanf("%lld %lld %lld", &w[i], &p[i], &v[i]);
		}

		sol = 0;

		/*
		ub = (int)pow(2.0, n);

		for (i = 1; i < ub; i++)
		{
			cand = acc = 0;

			for (j = 0; j < n; j++)
			{
				bit = (i >> j) % 2;

				if (bit && acc <= w[j])
				{
					acc += p[j];

					cand += v[j];
				}
			}

			if (cand > sol)
			{
				sol = cand;
			}
		}
		*/

		list[0].clear();
		list[1].clear();

		list[1][0] = 0;

		for (i = 0; i < n; i++)
		{
			lmax = 0;

			list[i % 2] = list[!(i % 2)];

			for (it = list[!(i%2)].begin(); it != list[!(i%2)].end(); it++)
			{
				if (it->first > w[i])
				{
					break;
				}

				if (it->second + v[i] <= lmax)
				{
					continue;
				}

				lmax = it->second + v[i];

				ret = list[i%2].find(it->first + p[i]);

				if (ret == list[i%2].end())
				{
					list[i%2][it->first + p[i]] = it->second + v[i];
				}

				else if(it->second + v[i] > ret->second)
				{
					ret->second = it->second + v[i];
				}

				if (it->second + v[i] > sol)
				{
					sol = it->second + v[i];
				}
			}
		}

		printf("%lld\n", sol);
	}

	return 0;
}