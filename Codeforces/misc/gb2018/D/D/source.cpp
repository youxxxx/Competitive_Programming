#include<cstdio>

int main()
{
	long long n, prod = 2, prod2 = 0, num = 1;
	long long sol;
	long long i;

	scanf("%I64d", &n);

	if (n == 1)
	{
		printf("1\n");

		return 0;
	}

	if (n == 2)
	{
		printf("2\n");

		return 0;
	}

	for (i = 3; i <= n; i++)
	{
		prod = ((prod)*i) % 998244353;

		prod2 = (((prod2 + num)) % 998244353 * i) % 998244353;

		num = (((num*i) % 998244353) + (i - 1)) % 998244353;
	}

	sol = (prod + prod2) % 998244353;

	printf("%I64d\n", sol);

	return 0;
}