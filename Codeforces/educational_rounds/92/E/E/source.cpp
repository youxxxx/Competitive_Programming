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

long long gcd(long long a, long long b)
{
	while (b != 0)
	{
		long long temp;

		a %= b;

		temp = a;
		a = b;
		b = temp;
	}

	return a;
}

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		long long m, d, w;

		scanf("%lld %lld %lld", &m, &d, &w);

		if (d == 1)
		{
			printf("0\n");

			continue;
		}

		const long long g = gcd((d - 1), w);
		long long mlt = w / g;
		long long bound = (m < d ? m : d);

		long long lmax = (bound - 1) / mlt;

		long long sol = (lmax) * ((bound - lmax * mlt) + (bound - mlt)) / 2;

		printf("%lld\n", sol);
	}

	return 0;
}