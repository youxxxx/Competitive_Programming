#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

long long gcd(long long a, long long b)
{
	long long temp;

	while (b!=0)
	{
		a %= b;

		temp = a;
		a = b;
		b = temp;
	}

	return a;
}

long long lcm(long long a, long long b)
{
	return a*b / gcd(a, b);
}

int main()
{
	long long n, m;
	long long div;
	int q;
	int i, j;
	long long input[4];
	long long dn, dm;
	long long s1, s2;

	scanf("%lld %lld %d", &n, &m, &q);

	div = gcd(n, m);

	dn = n / div;
	dm = m / div;

	for (i = 0; i < q; i++)
	{
		for (j = 0; j < 4; j++)
		{
			scanf("%lld", &input[j]);
		}

		if (input[0] == 1)
		{
			s1 = (input[1] - 1) / dn;
		}

		else
		{
			s1 = (input[1] - 1) / dm;
		}

		if (input[2] == 1)
		{
			s2 = (input[3] - 1) / dn;
		}

		else
		{
			s2 = (input[3] - 1) / dm;
		}

		if (s1 == s2)
		{
			printf("YES\n");
		}

		else
		{
			printf("NO\n");
		}
	}

	return 0;
}