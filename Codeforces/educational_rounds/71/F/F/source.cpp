#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

#define MOD 400

using namespace std;

int main()
{
	long long arr[500001] = { 0, };
	long long sol[MOD][MOD] = { 0, };
	long long n;
	long long tc, cases;
	long long i, j;
	long long op;
	long long x, y;
	long long sum;

	scanf("%lld", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		scanf("%lld %lld %lld", &op, &x, &y);

		if (op == 1)
		{
			arr[x] += y;

			for (i = 1; i < MOD; i++)
			{
				sol[i][x % i] += y;
			}
		}

		else
		{
			if (x < MOD)
			{
				printf("%lld\n", sol[x][y]);
			}

			else
			{
				sum = 0;

				for (i = y; i <= 500000; i += x)
				{
					sum += arr[i];
				}

				printf("%lld\n", sum);
			}
		}
	}

	return 0;
}