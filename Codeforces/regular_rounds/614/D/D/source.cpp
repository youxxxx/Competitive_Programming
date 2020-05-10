#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>

#define LIM 30000000000000000

using namespace std;

int n, q;

int safe(int x, int y)
{
	return (x == 1 || x == 2) && y >= 1 && y <= n;
}

int main()
{
	long long x0, y0, ax, ay, bx, by;
	long long xs, ys, t;

	scanf("%lld %lld %lld %lld %lld %lld", &x0, &y0, &ax, &ay, &bx, &by);
	scanf("%lld %lld %lld", &xs, &ys, &t);

	vector<pair<long long, long long>> arr;
	vector<long long> base, dist;

	long long x, y;

	x = x0;
	y = y0;
	
	arr.push_back({ 0,0 });

	dist.push_back(0);

	base.push_back(0);

	while (x <= LIM&&y <= LIM)
	{
		arr.push_back({ x,y });
		base.push_back(abs(x - xs) + abs(y - ys));

		x = x*ax + bx;
		y = y*ay + by;
	}

	long long lmax = 0;

	long long n;

	n = arr.size() - 1;

	for (long long i = 1; i <= n; i++)
	{
		dist.push_back(dist[i - 1] + arr[i].first - arr[i - 1].first + arr[i].second - arr[i - 1].second);
	}

	for (long long i = 1; i <= n; i++)
	{
		for (long long j = i; j <= n; j++)
		{
			for (long long k = i; k <= j; k++)
			{
				long long sum;

				sum = base[k];

				sum += dist[k] - dist[i];
				sum += dist[j] - dist[i];

				if (sum <= t && j - i + 1 > lmax)
				{
					lmax = j - i + 1;
				}

				sum = base[k];

				sum += dist[j] - dist[k];
				sum += dist[j] - dist[i];

				if (sum <= t && j - i + 1 > lmax)
				{
					lmax = j - i + 1;
				}
			}
		}
	}

	printf("%lld\n", lmax);

	return 0;
}