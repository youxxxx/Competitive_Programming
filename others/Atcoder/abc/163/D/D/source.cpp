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

#define MOD 1000000007

using namespace std;

int main()
{
	long long n, k;

	scanf("%lld %lld", &n, &k);

	long long sol = 0;

	for (long long i = k; i <= n + 1; i++)
	{
		sol = (sol + (((n - i + 1) % MOD)*i%MOD + 1) % MOD) % MOD;
	}

	printf("%lld\n", sol);

	return 0;
}