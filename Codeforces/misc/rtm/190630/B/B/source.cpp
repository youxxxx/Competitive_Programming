#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

pair<long long,pair<long long, long long>> gcd(long long a, long long b)
{
	long long temp;
	long long p, q;
	pair<long long, pair<long long, long long>> rvalue, ret;

	if (a == 0)
	{
		rvalue.first = b;

		rvalue.second.first = 0;
		rvalue.second.second = 1;

		return rvalue;
	}

	ret = gcd(b%a, a);

	rvalue.first = ret.first;
	rvalue.second.first = ret.second.second - (b / a)*ret.second.first;
	rvalue.second.second = ret.second.first;

	return rvalue;
}

int main()
{
	long long n, m;
	pair<long long, pair<long long, long long>> ret;
	long long g;
	long long lcm;
	long long x, y;
	long long p, q;
	long long xs[4] = { 2,2,0,0 };
	long long ys[4] = { 2,0,2,0 };
	long long xi[4] = { -1,-1,1,1 };
	long long yi[4] = { -1,1,-1,1 };
	long long a, b;
	long long sol, cand;
	int k;
	int i, j;

	scanf("%lld %lld %d", &n, &m, &k);

	ret = gcd(n*2, m*2);
	g = ret.first;
	p = ret.second.first;
	q = ret.second.second;

	lcm = n * 2 / g * m * 2;
	 
	for (i = 0; i < k; i++)
	{
		scanf("%lld %lld", &x, &y);

		sol = -1;

		for (j = 0; j < 4; j++)
		{
			a = n * xs[j] + x * xi[j];
			b = m * ys[j] + y * yi[j];

			if (a%g != b%g)
			{
				continue;
			}

			cand = ((a*q*m*2) + (b*p*n*2)) / g;

			cand = (cand + 8 * n*m) % lcm;

			if ((sol == -1 || cand < sol))
			{
				sol = cand;
			}
		}

		printf("%lld\n", sol);
	}

	return 0;
}