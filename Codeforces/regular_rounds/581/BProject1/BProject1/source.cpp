#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	long long n, i, j;
	long long l, r;
	long long lmin = 0, lmax = 0;
	long long cur;

	scanf("%lld %lld %lld", &n, &l, &r);

	cur = 1;

	for (i = 0; i < n; i++)
	{
		lmin += cur;

		if (i >= n - l)
		{
			cur *= 2;
		}
	}

	cur = 1;

	for (i = 0; i < n && i < r; i++)
	{
		lmax += cur;

		cur *= 2;
	}

	cur /= 2;

	for (j = i; j < n; j++)
	{
		lmax += cur;
	}

	printf("%lld %lld\n", lmin, lmax);

	return 0;
}