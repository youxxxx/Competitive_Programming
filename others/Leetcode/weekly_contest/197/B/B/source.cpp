#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<functional>

using namespace std;

#define MOD 1000000007

long long exp(long long base, long long pw)
{
	long long temp = base;
	long long rvalue = 1;

	while (pw)
	{
		if (pw % 2)
		{
			rvalue = rvalue*temp%MOD;
		}

		temp = temp*temp%MOD;

		pw /= 2;
	}

	return rvalue;
}

long long div(long long val)
{
	return exp(val, MOD - 2);
}

class Solution {
public:
	int numSub(string s) {
		long long perm[100001];

		const int n = s.size();

		perm[0] = perm[1] = 1;

		for (long long i = 2; i <= n; i++)
		{
			perm[i] = perm[i - 1] * i%MOD;
		}

		long long cur = 0;
		long long sol = 0;

		for (int i = 0; i < n; i++) {
			if (s[i] == '0')
			{
				if (cur)
				{
					sol = (sol + perm[cur + 1] * div(perm[cur - 1]) % MOD*div(2) % MOD) % MOD;

					cur = 0;
				}
			}

			else
			{
				cur++;
			}
		}

		if (cur)
		{
			sol = (sol + perm[cur + 1] * div(perm[cur - 1]) % MOD*div(2) % MOD) % MOD;

			cur = 0;
		}

		return (int)sol;
	}
};

int main()
{


	return 0;
}