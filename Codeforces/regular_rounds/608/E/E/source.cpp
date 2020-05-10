#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>

using namespace std;

long long rec(long long cur, long long lim, long long base)
{
	if (cur + base - 1 <= lim)
	{
		return base + rec(cur * 2, lim, base * 2);
	}

	return lim - cur > 0 ? lim - cur : 0;
}

long long bin_search(long long lb, long long ub, long long lim, long long target)
{
	long long next;
	long long ret, ret2;

	if (ub - lb < 2)
	{
		ret = rec(lb * 2, lim, 1);

		if (ret < target)
		{
			return lb * 2 - 1;
		}

		return lb * 2;
	}

	next = (lb + ub) / 2;
	
	if (next * 2 + 1 < ub)
	{
		ret2 = rec(next * 2 + 1, lim, 2);

		if (ret2 >= target)
		{
			return next * 2 + 1;
		}
	}

	ret = rec(next * 2, lim, 1);

	if (ret >= target)
	{
		return bin_search(next, ub, lim, target);
	}

	return bin_search(lb, next, lim, target);
}

int main()
{
	long long n, m;

	scanf("%lld %lld", &n, &m);

	printf("%lld\n", bin_search(1, n / 2 + 1, n, m));

	return 0;
}