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
	freopen("input.txt", "r", stdin);

	int n, m;

	scanf("%d %d", &n, &m);

	long long arr[31];

	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &arr[i]);
	}

	for (int i = 0; i < m; i++)
	{
		int op;
		int x;
		long long k;

		scanf("%d %d %lld", &op, &x, &k);

		if (op == 1)
		{
			arr[x] = k;

			continue;
		}

		long long left = k;

		long long cur = 1;
		long long tot = 0;

		for (int j = 0; j <= x; j++)
		{
			left = max(0ll, left - arr[j]);

			tot += cur*arr[j];

			if (!left)
			{
				break;
			}

			cur *= 2;
		}

		if (!left)
		{
			printf("0\n");

			continue;
		}

		long long base = tot;
		left = (left + left % 2) / 2;
		long long sol = left;

		for (int j = x + 1; j < n; j++)
		{
			const long long subt = min(left, arr[j]);

			left -= subt;

			if (!left)
			{
				break;
			}

			tot += cur*arr[j];

			left = (left + left % 2) / 2;

			base += cur*left;

			sol += left;

			cur *= 2;
		}

		if (!left)
		{
			printf("%lld\n", sol);
		}

		else if (tot < k)
		{
			printf("-1\n");
		}

		else
		{
			printf("%lld\n", sol + tot - base);
		}
	}

	return 0;
}