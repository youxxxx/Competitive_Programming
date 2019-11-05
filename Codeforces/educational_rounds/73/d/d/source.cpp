#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	long long tc, cases;
	long long n;
	long long i, j, k;
	vector<long long> a, b;
	long long dp[2][3], h[2][3];
	long long input1, input2;
	long long cand;
	long long sol;

	scanf("%lld", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		a.clear();
		b.clear();
		
		scanf("%lld", &n);

		for (i = 0; i < n; i++)
		{
			scanf("%lld %lld", &input1, &input2);

			a.push_back(input1);
			b.push_back(input2);
		}

		if (n == 1)
		{
			printf("0\n");

			continue;
		}

		dp[0][0] = 0;
		dp[0][1] = b[0];
		dp[0][2] = b[0] * 2;

		h[0][0] = a[0];
		h[0][1] = a[0] + 1;
		h[0][2] = a[0] + 2;

		for (i = 1; i < n; i++)
		{
			for (j = 0; j < 3; j++)
			{
				cand = -1;

				for (k = 0; k < 3; k++)
				{
					if (h[!(i % 2)][k] != a[i] + j && (cand == -1 || dp[!(i % 2)][k] + b[i] * j < cand))
					{
						cand = dp[!(i % 2)][k] + b[i] * j;
					}
				}

				dp[i % 2][j] = cand;
				h[i % 2][j] = a[i] + j;
			}
		}

		sol = dp[!(n % 2)][0];

		for (i = 1; i < 3; i++)
		{
			if (dp[!(n % 2)][1] < sol)
			{
				sol = dp[!(n % 2)][i];
			}
		}

		printf("%lld\n", sol);
	}

	return 0;
}