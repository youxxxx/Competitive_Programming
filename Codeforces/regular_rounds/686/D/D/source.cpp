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

int main()
{
	//freopen("input.txt", "r", stdin);

	vector<long long> prime = { 2 };

	for (long long i = 3; i < 100000; i += 2)
	{
		bool isprime = true;

		for (int j = 0; j < prime.size() && prime[j] * prime[j] <= i; j++)
		{
			if (!(i%prime[j]))
			{
				isprime = false;

				break;
			}
		}

		if (isprime)
		{
			prime.push_back(i);
		}
	}

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		long long n;

		scanf("%lld", &n);

		int lmax = 1;
		long long mval = n;

		long long temp = n;

		for (int i = 0; i < prime.size(); i++)
		{
			int cnt = 0;

			while (!(temp%prime[i]))
			{
				temp /= prime[i];

				cnt++;
			}

			if (cnt)
			{
				if (cnt > lmax)
				{
					lmax = cnt;
					mval = prime[i];
				}
			}
		}

		printf("%d\n", lmax);

		temp = n;

		for (int i = 0; i < lmax - 1; i++)
		{
			printf("%lld ", mval);

			temp /= mval;
		}

		printf("%lld\n", temp);
	}

	return 0;
}