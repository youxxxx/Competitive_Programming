#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<functional>
#include<cstring>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		long long n;

		scanf("%lld", &n);

		long long arr[200001];

		for (long long i = 0; i < n; i++)
		{
			scanf("%lld", &arr[i]);
		}

		long long diff[200001];

		diff[0] = arr[0];

		bool neg = (diff[0] < 0);

		for (long long i = 1; i < n; i++)
		{
			diff[i] = arr[i] - diff[i - 1];

			neg = neg || (diff[i] < 0);
		}

		if (!diff[n - 1] && !neg)
		{
			printf("YES\n");

			continue;
		}

		long long rmin[2][200001];

		rmin[0][n] = rmin[1][n] = rmin[n % 2][n - 1] = 1000000000;

		rmin[!(n % 2)][n - 1] = diff[n - 1];

		for (long long i = n - 2; i >= 0; i--)
		{
			rmin[i % 2][i] = min(rmin[i % 2][i + 2], diff[i]);

			rmin[!(i % 2)][i] = rmin[!(i % 2)][i + 1];
		}

		bool found = false;

		for (long long i = 1; i < n; i++)
		{
			const long long curdiff = arr[i] - arr[i - 1];

			if (i % 2 == !(n % 2) && curdiff * 2 == diff[n - 1] || i % 2 != !(n % 2) && curdiff * 2 == -diff[n - 1])
			{
				if (diff[i - 1] + curdiff >= 0 && rmin[i % 2][i] - curdiff * 2 >= 0 && rmin[!(i % 2)][i] + curdiff * 2 >= 0)
				{
					found = true;

					false;
				}
			}

			if (diff[i - 1] < 0)
			{
				break;
			}
		}

		if (found)
		{
			printf("YES\n");
		}

		else
		{
			printf("NO\n");
		}
	}

	return 0;
}