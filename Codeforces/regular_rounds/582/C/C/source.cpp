#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

int main()
{
	int tc, cases;
	long long n, m;
	long long q, r, sol;
	long long num[11], acc[11], tot;
	long long i;

	scanf("%d", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		scanf("%lld %lld", &n, &m);

		q = n / (m * 10);
		r = n % (m * 10) / m;

		num[0] = 0;
		acc[0] = 0;

		for (i = 1; i <= 10; i++)
		{
			num[i] = (num[i - 1] + m) % 10;

			acc[i] = acc[i - 1] + num[i];
		}

		sol = q* acc[10] + acc[r];

		printf("%lld\n", sol);
	}

	return 0;
}