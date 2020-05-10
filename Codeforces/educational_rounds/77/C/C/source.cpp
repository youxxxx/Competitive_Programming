#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

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
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		long long a, b, k;

		scanf("%lld %lld %lld", &a, &b, &k);

		if (a > b)
		{
			long long temp;

			temp = a;
			a = b;
			b = temp;
		}

		long long base;
		base = gcd(a, b);

		if ((b - 1) / a >= k || 1 + (b - 1 - base) / a >= k)
		{
			printf("REBEL\n");
		}

		else
		{
			printf("OBEY\n");
		}
	}

	return 0;
}