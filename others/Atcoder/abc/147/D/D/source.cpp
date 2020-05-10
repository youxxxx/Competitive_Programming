#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>

#define MOD 1000000007

using namespace std;

int main()
{
	long long n;

	scanf("%lld", &n);

	long long bits[60] = { 0, };

	for (long long i = 0; i < n; i++)
	{
		long long input;

		scanf("%lld", &input);

		int idx = 0;

		while (input)
		{
			bits[idx++] += input % 2;

			input /= 2;
		}
	}

	long long sol = 0;
	long long cur = 1;

	for (int i = 0; i < 60; i++)
	{
		sol = (sol + (bits[i] * (n - bits[i]) % MOD) * cur % MOD) % MOD;

		cur = cur * 2 % MOD;
	}

	printf("%lld\n", sol);

	return 0;
}