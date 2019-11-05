#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	long long n, x;
	long long i, j;
	long long prod = 1, temp;
	long long ub;
	long long mask[18];
	long long output;
	long long exc = -1, base = 0, dec = 0;

	scanf("%lld %lld", &n, &x);

	ub = (long long)pow(2.0, n);

	temp = 1;

	for (i = 0; i < n; i++)
	{
		if (x < ub && temp & x && exc == -1)
		{
			exc = i;

			dec = 1;

			temp *= 2;

			continue;
		}

		mask[i - dec] = temp;

		temp *= 2;
	}

	printf("%lld\n", ub / (dec + 1) - 1);

	for (i = 1; i < ub / (dec + 1); i++)
	{
		output = 0;
		temp = 1;

		for (j = 0; j < n - dec; j++)
		{
			output |= !(i % temp) * mask[j];

			temp *= 2;
		}

		printf("%lld ", output);
	}

	return 0;
}