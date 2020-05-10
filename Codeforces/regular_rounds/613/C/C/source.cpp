#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>

using namespace std;

long long gcd(long long a, long long b)
{
	while (b != 0)
	{
		long long temp;

		a %= b;

		temp = a;
		a = b;
		b = temp;
	}

	return a;
}

int main()
{
	long long n;

	scanf("%lld", &n);

	long long ub;

	ub = (long long) sqrt((double)n);

	for (long long i = ub; i >= 1; i--)
	{
		if (!(n%i) && gcd(i, n / i) == 1)
		{
			printf("%lld %lld\n", i, n / i);

			return 0;
		}
	}

	return 0;
}