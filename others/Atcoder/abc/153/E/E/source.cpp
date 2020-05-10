#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>
#include<cstring>

using namespace std;

int main()
{
	long long h;
	long long n;
	vector<pair<long long, long long>> arr;

	scanf("%lld %lld", &h, &n);

	for (long long i = 0; i < n; i++)
	{
		long long input1, input2;

		scanf("%lld %lld", &input1, &input2);

		arr.push_back({ input1,input2 });
	}

	long long dp[10001];

	memset(dp, -1, sizeof(dp));

	dp[0] = 0;

	for (long long i = 0; i < h; i++)
	{
		if (dp[i] == -1)
		{
			continue;
		}

		for (long long j = 0; j < n; j++)
		{
			long long nstate, cost;

			nstate = i + arr[j].first < h ? i + arr[j].first : h;

			cost = dp[i] + arr[j].second;

			if (dp[nstate] == -1 || cost < dp[nstate])
			{
				dp[nstate] = cost;
			}
		}
	}

	printf("%lld\n", dp[h]);

	return 0;
}