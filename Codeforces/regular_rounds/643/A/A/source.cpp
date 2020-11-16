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

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		long long n, k;

		scanf("%lld %lld", &n, &k);

		long long cur = n;

		for (long long i = 0; i < k - 1; i++)
		{
			long long temp = cur;

			long long lmin = 9, lmax = 0;

			while (temp)
			{
				long long digit = temp % 10;

				if (digit < lmin)
				{
					lmin = digit;
				}

				if (digit > lmax)
				{
					lmax = digit;
				}

				temp /= 10;
			}

			if (lmin == 0)
			{
				break;
			}

			cur = cur + lmin*lmax;
		}

		printf("%lld\n", cur);
	}

	return 0;
}