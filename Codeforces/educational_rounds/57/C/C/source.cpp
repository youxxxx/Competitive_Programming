#include<cstdio>

using namespace std;

int gcd(int a, int b)
{
	int temp;

	while (b)
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
	int t, z;
	int n;
	int div, sol;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d", &n);

		div = gcd(n, 180);
		sol = 180 / div;

		if (n + div >= 180)
		{
			sol *= 2;
		}

		printf("%d\n", sol);
	}

	return 0;
}