#include<cstdio>
#include<vector>

using namespace std;

long long bsearch(vector<long long> &dist, vector<long long> &speed, int n, double lim, long long lb, long long ub)
{
	double res = 0.0;
	long long next;
	int i;

	if (ub - lb <= 1)
	{
		return ub;
	}

	next = (lb + ub) / 2 + (lb + ub) % 2;

	for (i = 0; i < n; i++)
	{
		res += (double)dist[i] / (double)(speed[i] + next);
	}

	if (res > lim)
	{
		return bsearch(dist, speed, n, lim, next, ub);
	}

	return bsearch(dist, speed, n, lim, lb, next);
}

int main()
{
	int n;
	long long lim;
	int t, z;
	vector<long long> dist;
	vector<long long> speed;
	long long aland;
	long long min, max;
	long long lb, ub;
	long long input;
	int i;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d %lld", &n, &lim);

		speed.push_back(0);

		scanf("%lld", &input);

		dist.push_back(input);

		aland = input;

		for (i = 1; i < n; i++)
		{
			scanf("%lld", &input);

			dist.push_back(input - aland);

			aland = input;
		}

		min = max = 0;

		for (i = 1; i < n; i++)
		{
			scanf("%lld", &input);

			speed.push_back(input + speed[i - 1]);

			if (speed[i] > max)
			{
				max = speed[i];
			}

			if (speed[i] < min)
			{
				min = speed[i];
			}
		}

		if (lim == 0)
		{
			printf("-1\n");
		}

		else
		{
			if (min < 0)
			{
				lb = -min;
			}

			else
			{
				lb = 0;
			}

			ub = (aland + lim - 1) / lim - min;

			if (ub < 1)
			{
				ub = 1;
			}

			printf("%lld\n", bsearch(dist, speed, n, (double)lim, lb, ub));
		}

		dist.clear();
		speed.clear();
	}

	return 0;
}