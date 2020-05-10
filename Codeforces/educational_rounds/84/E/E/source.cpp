#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cstring>

#define MOD 998244353

using namespace std;

int main()
{
	long long n;

	scanf("%lld", &n);

	vector<long long> sol;

	sol.push_back(10);

	long long main = 200;
	long long inc = 100;
	long long subt = 10;
	long long sinc = 10;
	long long other = 10;

	for (long long i = 0; i < n - 1; i++)
	{
		sol.push_back((main - subt + MOD - other + MOD) % MOD);

		other = (other + sol.back()) % MOD;
		main = (main + inc) % MOD;
		main = main * 10 % MOD;
		inc = inc * 10 % MOD;
		subt = (subt + sinc) % MOD;
		subt = subt * 10 % MOD;
		sinc = sinc * 10 % MOD;
	}

	for (long long i = n - 1; i >= 0; i--)
	{
		printf("%lld ", sol[i]);
	}


	/*
	long long ub;

	long long cnt[10] = { 0, };

	string str;

	ub = (long long)pow(10.0, n);

	for (long long i = 0; i < ub; i++)
	{
		long long temp;

		temp = i;

		vector<long long> num;

		for (long long j = 0; j < n; j++)
		{
			num.push_back(temp % 10);

			temp /= 10;
		}

		long long cur = 0;
		long long acc = 0;

		for (long long j = n - 1; j >= 0; j--)
		{
			if (cur != num[j])
			{
				cur = num[j];

				cnt[acc]++;

				acc = 1;
			}

			else
			{
				acc++;
			}
		}

		cnt[acc]++;
	}

	char cur = '0';
	long long acc = 0;

	for (long long i = 0; i < str.size(); i++)
	{
		if (cur != str[i])
		{
			cur = str[i];

			cnt[acc]++;

			acc = 1;
		}

		else
		{
			acc++;
		}
	}

	for (long long i = 1; i <= n; i++)
	{
		prlong longf("%lld\n", cnt[i]);
	}

	*/

	return 0;
}