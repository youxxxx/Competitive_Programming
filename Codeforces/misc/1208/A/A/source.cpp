#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int tc, cases;
	long long n, a, b;
	long long val[2][32];
	long long add[32], temp, sol, bit[3] = { 0,1,1 };
	int i, j;

	scanf("%d", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		scanf("%lld %lld %lld", &a, &b, &n);

		if (n == 0)
		{
			printf("%lld\n", a);

			continue;
		}
		
		if (n == 1)
		{
			printf("%lld\n", b);

			continue;
		}

		temp = a;

		for (i = 0; i < 32; i++)
		{
			val[0][i] = temp % 2;

			temp /= 2;
		}

		temp = b;

		for (i = 0; i < 32; i++)
		{
			val[1][i] = temp % 2;

			temp /= 2;
		}

		for (i = 0; i < 32; i++)
		{
			if (val[0][i] == 0 && val[1][i] == 0)
			{
				add[i] = -1;
			}

			else if (val[0][i] == 0 && val[1][i] == 1)
			{
				add[i] = 0;
			}

			else if (val[0][i] == 1 && val[1][i] == 1)
			{
				add[i] = 1;
			}

			else
			{
				add[i] = 2;
			}
		}

		temp = 1;

		sol = 0;

		for (i = 0; i < 32; i++)
		{
			if (add[i] != -1)
			{
				sol += temp*bit[(n + add[i]) % 3];
			}

			temp *= 2;
		}

		printf("%lld\n", sol);
	}

	return 0;
}