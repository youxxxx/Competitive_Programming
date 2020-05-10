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

long long lcm(long long a, long long b)
{
	return a*b / gcd(a, b);
}
int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		long long a, b;
		int q;

		scanf("%lld %lld %d", &a, &b, &q);

		long long ub;

		ub = lcm(a, b);

		vector<long long> acc;

		acc.push_back(0);

		for (long long i = 1; i < ub; i++)
		{
			long long ab, ba;

			ab = i%a%b;
			ba = i%b%a;

			if (ab != ba)
			{
				acc.push_back(acc.back() + 1);
			}

			else
			{
				acc.push_back(acc.back());
			}
		}

		for (int i = 0; i < q; i++)
		{
			long long l, r;

			scanf("%lld %lld", &l, &r);

			long long sol;

			sol = acc.back()*(r / ub - (l - 1) / ub);

			sol += acc[r%ub];
			sol -= acc[(l - 1) % ub];

			printf("%lld ", sol);
		}

		printf("\n");
	}

	return 0;
}