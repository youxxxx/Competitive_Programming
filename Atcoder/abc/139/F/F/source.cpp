#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

bool func(const pair<long long, long long> &a, const pair<long long, long long> &b)
{
	return atan2(a.second, a.first) < atan2(b.second, b.first);
}

int main()
{
	int n;
	pair<long long, long long> coord[100];
	double len, lmax = 0.0, cand;
	int i, j, k, pj, pk;
	long long x, y;
	long long nx, ny;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%lld %lld", &x, &y);

		coord[i] = make_pair(x, y);
	}

	if (n == 1)
	{
		printf("%.12lf\n", sqrt(coord[0].first*coord[0].first + coord[0].second * coord[0].second));

		return 0;
	}

	sort(&coord[0], &coord[n], func);

	for (i = 0; i < n; i++)
	{
		len = coord[i].first*coord[i].first + coord[i].second * coord[i].second;
		x = coord[i].first;
		y = coord[i].second;

		if (len > lmax)
		{
			lmax = len;
		}

		j = (i - 1 + n) % n;
		k = (i + 1) % n;

		pj = j;
		pk = k;

		while (1)
		{
			if (j == i)
			{
				break;
			}

			nx = coord[j].first;
			ny = coord[j].second;

			cand = (x + nx)*(x + nx) + (y + ny)*(y + ny);

			if (cand >= lmax)
			{
				lmax = cand;
			}

			if (cand >= len)
			{
				len = cand;

				x = x + nx;
				y = y + ny;

				if (j == k)
				{
					break;
				}

				j = (j - 1 + n) % n;

			}

			nx = coord[k].first;
			ny = coord[k].second;

			cand = (x + nx)*(x + nx) + (y + ny)*(y + ny);

			if (cand >= lmax)
			{
				lmax = cand;
			}

			if (cand >= len)
			{
				len = cand;

				x = x + nx;
				y = y + ny;

				if (j == k)
				{
					break;
				}

				k = (k + 1) % n;
			}

			if (j == pj&&k == pk)
			{
				break;
			}

			pj = j;
			pk = k;
		}
	}

	printf("%.12lf\n", sqrt(lmax));

	return 0;
}