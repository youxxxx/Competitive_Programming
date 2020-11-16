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
		int n, m;

		scanf("%d %d", &n, &m);

		long long arr[300001];
		long long diff[300001];
		long long sol = 0;

		long long prev = 0;

		for (int i = 0; i < n; i++)
		{
			scanf("%lld", &arr[i]);

			diff[i] = arr[i] - prev;

			if (diff[i] > 0)
			{
				sol += diff[i];
			}

			prev = arr[i];
		}

		printf("%lld\n", sol);

		for (int i = 0; i < m; i++)
		{
			int l, r;

			scanf("%d %d", &l, &r);

			l--;
			r--;

			if (l == r)
			{
				printf("%lld\n", sol);

				continue;
			}

			long long cur = max(diff[l], 0ll) + max(diff[r], 0ll);

			if (l + 1 != r)
			{
				cur += max(diff[l + 1], 0ll);
			}

			if (r < n - 1)
			{
				cur += max(diff[r + 1], 0ll);
			}

			long long temp = arr[l];
			arr[l] = arr[r];
			arr[r] = temp;

			long long next = 0;

			if (l == 0)
			{
				diff[0] = arr[0];
			}

			else
			{
				diff[l] = arr[l] - arr[l - 1];
			}

			next += max(diff[l], 0ll);

			if (l + 1 != r)
			{
				diff[l + 1] = arr[l + 1] - arr[l];

				next += max(diff[l + 1], 0ll);
			}

			diff[r] = arr[r] - arr[r - 1];

			next += max(diff[r], 0ll);

			if (r < n - 1)
			{
				diff[r + 1] = arr[r + 1] - arr[r];

				next += max(diff[r + 1], 0ll);
			}

			sol += next - cur;

			printf("%lld\n", sol);
		}
	}

	return 0;
}