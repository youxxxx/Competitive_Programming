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
	long long ans;
	long long add = 128;
	long long i;
	long long sol;

	printf("?");

	for (i = 0; i < 100; i++)
	{
		printf(" %lld", i);
	}

	printf("\n");

	fflush(stdout);

	scanf("%lld", &ans);

	sol = ans / 128 * 128;

	printf("?");

	for (i = 1; i <= 100; i++)
	{
		printf(" %lld", i * 128);
	}

	printf("\n");

	fflush(stdout);

	scanf("%lld", &ans);

	sol += ans % 128;

	printf("! %lld\n", sol);

	return 0;
}