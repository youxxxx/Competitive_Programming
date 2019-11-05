#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<functional>

using namespace std;

long long gcd(long long a, long long b)
{
	long long temp;

	while (b != 0)
	{
		a %= b;

		temp = a;
		a = b;
		b = temp;
	}

	return a;
}

int main()
{
	long long n, k;
	long long a, b;
	long long i;
	long long dis;
	long long cand;
	long long lmin = 99999999999, lmax = 0;

	scanf("%I64d %I64d %I64d %I64d", &n, &k, &a, &b);

	dis = (b%k - a%k + k) % k;

	for (i = 0; i < n; i++)
	{
		cand = gcd(dis + i*k, n*k);

		if (n*k / cand < lmin)
		{
			lmin = n*k / cand;
		}

		if (n*k / cand > lmax)
		{
			lmax = n*k / cand;
		}
	}

	dis = ((k - b) % k - a%k + k) % k;

	for (i = 0; i < n; i++)
	{
		cand = gcd(dis + i*k, n*k);

		if (n*k / cand < lmin)
		{
			lmin = n*k / cand;
		}

		if (n*k / cand > lmax)
		{
			lmax = n*k / cand;
		}
	}

	dis = (b%k - (k - a) % k + k) % k;

	for (i = 0; i < n; i++)
	{
		cand = gcd(dis + i*k, n*k);

		if (n*k / cand < lmin)
		{
			lmin = n*k / cand;
		}

		if (n*k / cand > lmax)
		{
			lmax = n*k / cand;
		}
	}

	dis = ((k - b) % k - (k - a) % k + k) % k;

	for (i = 0; i < n; i++)
	{
		cand = gcd(dis + i*k, n*k);

		if (n*k / cand < lmin)
		{
			lmin = n*k / cand;
		}

		if (n*k / cand > lmax)
		{
			lmax = n*k / cand;
		}
	}

	printf("%I64d %I64d\n", lmin, lmax);

	return 0;
}