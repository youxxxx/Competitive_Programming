#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	long long cases;

	scanf("%lld", &cases);

	for (long long tc = 0; tc < cases; tc++)
	{
		long long n, m;

		long long pos[100001];

		long long lmax = 0;

		scanf("%lld %lld", &n, &m);

		for (long long i = 1; i <= n; i++)
		{
			long long input;

			scanf("%lld", &input);

			pos[input] = i;
		}

		long long sum = 0;

		for (long long i = 0; i < m; i++)
		{
			long long input;

			scanf("%lld", &input);

			if (pos[input] > lmax)
			{
				lmax = pos[input];

				sum += 2 * (lmax - i - 1) + 1;
			}

			else
			{
				sum++;
			}
		}

		printf("%lld\n", sum);
	}

	return 0;
}