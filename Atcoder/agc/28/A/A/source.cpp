#include<cstdio>
#include<string>

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
	char input[100001], input2[100001];
	long long n, m, i;
	string a, b;
	long long lcm;

	scanf("%lld %lld", &n, &m);
	
	scanf("%s", input);

	a = input;

	scanf("%s", input2);

	b = input2; 

	fflush(stdin);
	
	if (!(n%m))
	{
		for (i = 0; i < m; i++)
		{
			if (a[i*(n / m)] != b[i])
			{
				break;
			}
		}

		if (i != m)
		{
			printf("-1\n");

			return 0;
		}

		printf("%lld\n", n);

		return 0;
	}

	else if (!(m%n))
	{
		for (i = 0; i < n; i++)
		{
			if (b[i*(m / n)] != a[i])
			{
				break;
			}
		}

		if (i != n)
		{
			printf("-1\n");

			return 0;
		}

		printf("%lld\n", m);

		return 0;
	}

	if (a[0] != b[0])
	{
		printf("-1\n");

		return 0;
	}

	printf("%lld\n", n*m / gcd(n, m));

	fflush(stdout);

	return 0;
}