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

#define MOD 1000000007

long long perm[1001];

long long exp(long long base, long long pw)
{
	long long rvalue = 1;

	while (pw)
	{
		if (pw % 2)
		{
			rvalue = rvalue*base%MOD;
		}

		pw /= 2;
		base = base*base%MOD;
	}

	return rvalue;
}

long long div(long long base)
{
	return exp(base, MOD - 2);
}

long long ncr(long long n, long long r)
{
	return perm[n] * div(perm[r]) % MOD*div(perm[n - r]) % MOD;
}

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	vector<int> two, one;

	perm[0] = perm[1] = 1;

	for (int i = 2; i <= 1000; i++)
	{
		perm[i] = perm[i - 1] * i%MOD;
	}

	for (int tc = 0; tc < cases; tc++)
	{
		int n, m;

		scanf("%d %d", &n, &m);

		long long arr[1001];

		for (int i = 0; i < n; i++)
		{
			scanf("%lld", &arr[i]);
		}

		sort(&arr[0], &arr[n], greater<long long>());

		long long lb = m - 1, ub = m - 1;

		while (lb >= 0 && arr[lb] == arr[m - 1])
		{
			lb--;
		}

		while (ub < n && arr[ub] == arr[m - 1])
		{
			ub++;
		}

		const long long a = (ub - lb - 1);
		const long long b = ((m - 1) - lb);

		printf("%lld\n", ncr(a, b));
	}

	return 0;
}