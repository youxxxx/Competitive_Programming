#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int t, tc;
	long long n, x;

	scanf("%d", &tc);

	for (t = 0; t < tc; t++)
	{
		scanf("%lld %lld", &n, &x);

		printf("%lld\n", x * 2);
	}

	return 0;
}