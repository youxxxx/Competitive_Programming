#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

long long n, k;

long long bin_search(long long lb, long long ub, long long target)
{
	long long next;
	long long val;

	if (ub - lb < 2)
	{
		return lb;
	}

	next = (lb + ub) / 2;

	val = next*(next + 1) / 2 - (n - next);

	if (val == k)
	{
		return next;
	}

	if (val < k)
	{
		return bin_search(next, ub, target);
	}
	
	return bin_search(lb, next, target);
}

int main()
{
	scanf("%lld %lld", &n, &k);

	printf("%lld\n", n - bin_search(1, n + 1, k));

	return 0;
}