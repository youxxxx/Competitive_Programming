#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int t, z;
	long long n;
	long long i, j;
	long long input, temp, sol;
	long long bitcnt[40];

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%lld", &n);

		for (i = 0; i < 40; i++)
		{
			bitcnt[i] = 0;
		}

		for (i = 0; i < n; i++)
		{
			scanf("%lld", &input);

			for (j = 0; j < 40; j++)
			{
				bitcnt[j] += input % 2;

				input /= 2;
			}
		}

		temp = 1;
		sol = 0;

		for (i = 0; i < 40; i++)
		{
			sol += (bitcnt[i] < n - bitcnt[i] ? bitcnt[i] : n - bitcnt[i])*temp;

			temp *= 2;
		}

		printf("%lld\n", sol);
	}

	return 0;
}