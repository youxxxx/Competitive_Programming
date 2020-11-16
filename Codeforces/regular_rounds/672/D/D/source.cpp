#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<functional>
#include<cstring>

using namespace std;

#define MOD 998244353

long long exp(long long base, long long pw)
{
	long long rvalue = 1;

	while (pw)
	{
		if (pw % 2)
		{
			rvalue = rvalue*base%MOD;
		}

		base = base*base%MOD;

		pw /= 2;
	}

	return rvalue;
}

long long div(long long val)
{
	return exp(val, MOD - 2);
}

int main()
{
	//freopen("input.txt", "r", stdin);

	long long perm[300001];

	perm[0] = perm[1] = 1;

	for (long long i = 2; i <= 300000; i++)
	{
		perm[i] = perm[i - 1] * i%MOD;
	}

	int n, m;

	scanf("%d %d", &n, &m);

	pair<int, int> arr[300001];

	for (int i = 0; i < n; i++)
	{
		int l, r;

		scanf("%d %d", &l, &r);

		arr[i] = { l,r };
	}

	sort(&arr[0], &arr[n]);

	priority_queue<int, vector<int>, greater<int>> pq;

	long long sol = 0;

	for (int i = 0; i < n; i++)
	{
		const int l = arr[i].first;
		const int r = arr[i].second;

		while (!pq.empty() && pq.top() < l)
		{
			pq.pop();
		}

		if (pq.size() >= m - 1)
		{
			sol = (sol + perm[pq.size()] * div(perm[m - 1]) % MOD * div(perm[pq.size() - (m - 1)]) % MOD) % MOD;
		}

		pq.push(r);
	}

	printf("%lld\n", sol);

	return 0;
}