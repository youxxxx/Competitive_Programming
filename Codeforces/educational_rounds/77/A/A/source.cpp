#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		long long a, b;

		scanf("%lld %lld", &a, &b);

		long long q, r;

		q = b / a;
		r = b%a;

		long long sol = 0;

		sol = r*(q + 1)*(q + 1) + (a - r)*q*q;

		printf("%lld\n", sol);
	}

	return 0;
}