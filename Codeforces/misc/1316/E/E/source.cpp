#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>

using namespace std;

bool func(vector<long long> &a, vector<long long> &b)
{
	return a[0] > b[0];
}

int main()
{
	int n, p, k;

	//freopen("input.txt", "r", stdin);

	scanf("%d %d %d", &n, &p, &k);

	vector<long long> s[100001];

	for (int i = 0; i < n; i++)
	{
		long long input;

		scanf("%lld", &input);

		s[i].push_back(input);
	}

	for (int i = 0; i < n; i++)
	{
		long long input;

		for (int j = 1; j <= p; j++)
		{
			scanf("%lld", &input);

			s[i].push_back(input);
		}
	}

	sort(&s[0], &s[n], func);

	long long dp[2][128];

	memset(dp, -1, sizeof(dp));

	dp[1][0] = 0;

	for (int i = 0; i < n; i++)
	{
		memset(dp[i % 2], -1, sizeof(dp[i % 2]));

		for (int l = 0; l < (1 << p); l++)
		{
			long long cand1 = -1, cand2 = -1;

			if (dp[!(i % 2)][l] != -1)
			{
				int temp;
				int cnt;

				cnt = i;

				temp = l;

				while (temp)
				{
					cnt -= temp % 2;

					temp >>= 1;
				}

				if (cnt < k)
				{
					cand1 = dp[!(i % 2)][l] + s[i][0];
				}

				else
				{
					cand1 = dp[!(i % 2)][l];
				}
			}

			for (int j = 0; j < p; j++)
			{
				if ((l >> j) % 2)
				{
					int prev;

					prev = l&(~(1 << j));

					if (dp[!(i % 2)][prev] != -1 && dp[!(i % 2)][prev] + s[i][j + 1] > cand2)
					{
						cand2 = dp[!(i % 2)][prev] + s[i][j + 1];
					}
				}
			}

			long long cand;

			cand = cand1 > cand2 ? cand1 : cand2;

			if (cand > dp[i % 2][l])
			{
				dp[i % 2][l] = cand;
			}
		}
	}

	long long lmax = 0;

	for (int i = 0; i < (1 << p); i++)
	{
		if (dp[!(n % 2)][i] > lmax)
		{
			lmax = dp[!(n % 2)][i];
		}
	}

	printf("%lld\n", lmax);

	return 0;
}