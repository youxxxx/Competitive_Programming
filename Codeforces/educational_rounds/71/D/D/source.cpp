#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

#define MOD 998244353 

using namespace std;

bool func(const pair<long long, long long> &a, const pair<long long, long long> &b)
{
	return a.first < b.first || a.first == b.first&&a.second < b.second;
}

int main()
{
	vector<pair<long long,long long>> arr;
	vector<long long> a, b;
	long long n;
	long long perm[300001];
	long long i;
	long long input1, input2;
	long long cnt;
	long long sol, sub = 1, add = 1;

	scanf("%lld", &n);

	perm[1] = 1;

	for (i = 2; i <= n; i++)
	{
		perm[i] = perm[i - 1] * i%MOD;
	}

	for (i = 0; i < n; i++)
	{
		scanf("%lld %lld", &input1, &input2);

		a.push_back(input1);

		b.push_back(input2);

		arr.push_back(make_pair(input1, input2));
	}

	sort(arr.begin(), arr.end(), func);
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	sol = perm[n];

	cnt = 1;

	for (i = 1; i < n; i++)
	{
		if (a[i] != a[i - 1])
		{
			sub = (sub * perm[cnt]) % MOD;

			cnt = 1;
		}

		else
		{
			cnt++;
		}
	}

	sub = (sub * perm[cnt]) % MOD;

	sol = (sol + MOD - sub) % MOD;

	sub = 1;

	cnt = 1;

	for (i = 1; i < n; i++)
	{
		if (b[i] != b[i - 1])
		{
			sub = (sub * perm[cnt]) % MOD;

			cnt = 1;
		}

		else
		{
			cnt++;
		}
	}

	sub = (sub * perm[cnt]) % MOD;

	sol = (sol + MOD - sub) % MOD;

	cnt = 1;

	for (i = 1; i < n; i++)
	{
		if (arr[i].first != arr[i - 1].first || arr[i].second != arr[i - 1].second)
		{
			if (arr[i].first < arr[i - 1].first || arr[i].second < arr[i - 1].second)
			{
				add = 0;

				break;
			}

			add = (add * perm[cnt]) % MOD;

			cnt = 1;
		}

		else
		{
			cnt++;
		}
	}

	add = (add * perm[cnt]) % MOD;

	sol = (sol + add) % MOD;

	printf("%lld\n", sol);

	return 0;
}