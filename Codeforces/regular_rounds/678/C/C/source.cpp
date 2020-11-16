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
	int n, x, pos;

	scanf("%d %d %d", &n, &x, &pos);

	int left = 0, right = n;

	int lesser = 0, greater = 0;

	for (int mid = (left + right) / 2; left != right && mid != pos; mid = (left + right) / 2)
	{
		if (mid > pos)
		{
			right = mid;

			greater++;
		}

		else
		{
			left = mid + 1;

			lesser++;
		}
	}

	if (lesser > x - 1 || greater > n - x)
	{
		printf("0\n");

		return 0;
	}

	long long perm[200001];

	perm[0] = perm[1] = 1;

	for (long long i = 2; i <= 200000; i++)
	{
		perm[i] = perm[i - 1] * i % MOD;
	}

	long long sol = (perm[x-1]*div(perm[x - 1 - lesser]) % MOD * perm[n-x] % MOD * div(perm[n - x - greater]) % MOD*perm[(n - 1) - (lesser + greater)] % MOD) % MOD;

	printf("%lld\n", sol);

	return 0;
}