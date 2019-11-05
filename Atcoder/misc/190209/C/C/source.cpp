#include<cstdio>

using namespace std;

int main()
{
	long long k, a, b;
	long long i;
	long long bis = 1, yen = 0;
	long div, q, r;

	scanf("%lld %lld %lld", &k, &a, &b);

	if (a >= b - 2)
	{
		printf("%lld\n", k + 1);
	}

	else if(k + 1 < a)
	{
		printf("%lld\n", k + 1);
	}

	else
	{
		div = (k - (a - 1));

		printf("%lld\n", a + div / 2 * (b - a) + div %z 2);
	}

	return 0;
}