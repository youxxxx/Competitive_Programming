#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;

int main()
{
	int n, m, k;
	vector<long long> arr;
	long long input;
	priority_queue<long long> **dp;
	int i, j, h;

	scanf("%d %d %d", &n, &m, &k);

	for (i = 0; i < n; i++)
	{
		scanf("%I64d", &input);

		arr.push_back(input);
	}

	dp = new priority_queue<long long>*[n+1];

	for (i = 0; i < n + 1; i++)
	{
		dp[i] = new priority_queue<long long>[n - m * k + 1];
	}

	dp[0][0].push(arr[0]);

	for (i = 1; i < n; i++)
	{
		for (j = 0; j < i / m; i++)
		{
			for(h=0;)
		}
	}

	return 0;
}