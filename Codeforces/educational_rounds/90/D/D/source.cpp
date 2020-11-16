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

	int cases;

	scanf("%lld", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;
		long long arr[200001];

		scanf("%d", &n);

		for (int i = 0; i < n; i++)
		{
			scanf("%lld", &arr[i]);
		}

		long long lmax = 0;
		long long cur = 0;

		for (int i = 0; i < n - 1; i += 2)
		{
			cur += arr[i + 1] - arr[i];

			if (cur > lmax)
			{
				lmax = cur;
			}

			if (cur < 0)
			{
				cur = 0;
			}
		}

		//if (n % 2)
		{
			long long cur = 0;

			for (int i = 2; i < n; i += 2)
			{
				cur += arr[i - 1] - arr[i];

				if (cur > lmax)
				{
					lmax = cur;
				}

				if (cur < 0)
				{
					cur = 0;
				}
			}
		}

		long long sum = 0;

		for (long long i = 0; i < n; i += 2)
		{
			sum += arr[i];
		}

		printf("%lld\n", sum + lmax);
	}

	return 0;
}