#include<cstdio>

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
	long long pw;
	long long cur;
	long long mat[11][11];
	long long i, j, k;
	long long prime[11] = { 0,1,2,3,5,7,11,13,17,19,23};
	long long val[11];
	long long sol[11];
	long long muli, mulj;
	long long lcm;
	long long ng;
	long long a[11];

	for (i = 1; i < 11; i++)
	{
		mat[0][i] = 0;
		mat[1][i] = 1;
	}

	mat[0][1] = mat[1][1] = 1;

	for (i = 2; i < 11; i++)
	{
		mat[i][0] = 1;
		
		pw = cur = prime[i];

		for (j = 1; j < 11; j++)
		{
			mat[i][j] = cur;

			cur = (cur*pw) % 1000007;
		}
	}

	printf("? 0\n");
	fflush(stdin);

	scanf("%I64d", &val[0]);

	sol[0] = val[0];

	for (i = 1; i < 11; i++)
	{
		printf("? %I64d\n", prime[i]);
		fflush(stdin);

		scanf("%I64d", &val[i]);

		val[i] -= sol[0];
	}

	for (i = 10; i > 1; i--)
	{
		for (j = 1; j < i; j++)
		{
			lcm = mat[i][i] / gcd(mat[i][i], mat[j][i])*mat[j][i];
			muli = lcm / mat[i][i];
			mulj = lcm / mat[j][i];

			for (k = 1; k <= i; k++)
			{
				mat[i][k] *= muli;
				mat[j][k] *= mulj;

				mat[j][k] -= mat[i][k];
			}

			val[i] *= muli;
			val[j] *= mulj;

			val[j] -= val[i];

			for (k = 1; k <= i; k++)
			{
				mat[i][k] /= muli;
			}

			ng = val[j];

			for (k = 1; k < i; k++)
			{
				ng = gcd(ng, mat[j][k]);
			}

			for (k = 1; k < i; k++)
			{
				mat[j][k] /= ng;
			}
		}
	}

	for (i = 1; i <= 10; i++)
	{
		for (j = 1; j < i; j++)
		{
		}
	}
}