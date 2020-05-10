#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

#define MOD 1000000007

using namespace std;

int main()
{
	long long n;
	long long perm = 1;

	freopen("input.txt", "r", stdin);

	scanf("%lld", &n);

	for (long long i = 3; i < n; i++)
	{
		perm = perm*i%MOD;
	}

	long long sol = 0;

	long long input;

	scanf("%lld", &input);

	long long prev;

	prev = input;

	long long acc = 0;

	for (long long i = 0; i < n - 1; i++)
	{
		long long input;

		scanf("%lld", &input);

		acc = (acc + (input - prev)*i%MOD) % MOD;

		sol = (sol + (input - prev)*perm%MOD * 2 % MOD) % MOD;

		sol = (sol + acc*perm%MOD) % MOD;

		prev = input;
	}

	printf("%lld\n", sol);

	return 0;
}