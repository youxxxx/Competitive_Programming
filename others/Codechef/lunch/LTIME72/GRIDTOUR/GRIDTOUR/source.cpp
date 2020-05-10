#include<cstdio>
#include<vector>

using namespace std;

long long gcd(long long a, long long b)
{
	long long temp;

	while (b != 0)
	{
		temp = a;

		a %= b;

		temp = a;
		a = b;
		b = temp;
	}

	return a;
}

int main()
{
	int t, z;
	long long n, m, k;
	long long div;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%lld %lld %lld", &n, &m, &k);

		div = gcd(n, k);

		if (div != 1)
		{
			printf("-1\n");

			continue;
		}

		div = gcd(m, k);

		if (div != 1)
		{
			printf("-1\n");

			continue;
		}

		else
		{
			printf("%lld\n", n*m);
		}
	}

	return 0;
}