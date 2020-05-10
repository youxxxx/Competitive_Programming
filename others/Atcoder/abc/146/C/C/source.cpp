#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

long long a, b, x;

long long bin_search(long long lb, long long ub)
{
	long long next;

	if (ub - lb < 2)
	{
		return lb;
	}

	next = (lb + ub) / 2;

	long long cost;

	cost = a*next + ((long long)log10((double)next) + 1)*b;

	if (cost <= x)
	{
		return bin_search(next, ub);
	}

	return bin_search(lb, next);
}

int main()
{
	scanf("%lld %lld %lld", &a, &b, &x);

	printf("%lld\n", bin_search(0, 1000000001));

	return 0;
}