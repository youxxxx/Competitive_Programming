#include<cstdio>

using namespace std;

int main()
{
	long long a, b;
	int k;
	int i;

	scanf("%lld %lld %d", &a, &b, &k);

	for (i = 0; i < k; i++)
	{
		if (!(i % 2))
		{
			b += a / 2;
			a /= 2;
		}

		else
		{
			a += b / 2;
			b /= 2;
		}
	}

	printf("%lld %lld\n", a, b);

	return 0;
}