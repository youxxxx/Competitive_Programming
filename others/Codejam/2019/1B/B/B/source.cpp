#include<cstdio>
#include<cmath>

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

	return abs(a);
}

int main()
{
	int t, z;
	int w;
	long long coef[6][6] = { {2,1,1,1,1,1},{128,8,4,2,2,2},{256,16,4,4,2,2},{16,4,2,2,1,1},{32,4,2,2,2,1},{64,8,4,2,2,2} };
	int ask[6] = { 1,7,8,4,5,6 };
	long long temp[6][6];
	long long val[6];
	long long sol[6];
	long long lmax;
	long long lcm, div;
	int i, j, k;
	int res;

	scanf("%d %d", &t, &w);

	for (z = 0; z < t; z++)
	{
		for (i = 0; i < 6; i++)
		{
			printf("%d\n", ask[i]);
			fflush(stdout);

			scanf("%lld", &val[i]);

			for (j = 0; j < 6; j++)
			{
				temp[i][j] = coef[i][j];
			}
		}

		for (i = 0; i < 5; i++)
		{
			lcm = 1;

			for (j = i; j < 6; j++)
			{
				lcm = lcm / gcd(lcm, temp[j][i]) * temp[j][i];
			}

			for (j = i; j < 6; j++)
			{
				div = lcm / temp[j][i];
				for (k = i; k < 6; k++)
				{
					temp[j][k] *= div;
				}

				val[j] *= div;
			}

			for (j = i + 1; j < 6; j++)
			{
				for (k = i; k < 6; k++)
				{
					temp[j][k] -= temp[i][k];
				}

				val[j] -= val[i];
			}

			div = val[i];

			for (k = i; k < 6; k++)
			{
				div = gcd(div, temp[i][k]);
			}

			for (k = i; k < 6; k++)
			{
				temp[i][k] /= div;
			}

			val[i] /= div;

			for (j = i + 1; j < 6; j++)
			{
				div = val[j];

				for (k = i + 1; k < 6; k++)
				{
					div = gcd(div, temp[j][k]);
				}

				for (k = i + 1; k < 6; k++)
				{
					temp[j][k] /= div;
				}

				val[j] /= div;
			}
		}

		sol[5] = val[5] / temp[5][5];

		for (i = 4; i >= 0; i--)
		{
			for (j = i + 1; j < 6; j++)
			{
				val[i] -= sol[j] * temp[i][j];
			}

			sol[i] = val[i] / temp[i][i];
		}

		for (i = 0; i < 6; i++)
		{
			printf("%lld ", sol[i]);
		}

		printf("\n");
		fflush(stdout);

		scanf("%d", &res);

		if (res == -1)
		{
			return 0;
		}
	}

	return 0;
}