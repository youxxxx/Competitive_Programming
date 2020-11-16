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

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;
		long long k;

		scanf("%d %lld", &n, &k);

		long long arr[200001];

		for (int i = 0; i < n; i++)
		{
			scanf("%lld", &arr[i]);
		}

		sort(&arr[0], &arr[n]);

		long long dummy;

		for (int i = 0; i < n; i++)
		{
			scanf("%lld", &dummy);
		}

		int ptr = 0;
		long long right[200001];

		for (int i = 0; i < n; i++)
		{
			while (ptr != n&&arr[ptr] <= arr[i] + k)
			{
				ptr++;
			}

			right[i] = ptr;
		}

		ptr = n - 1;

		long long sol = 0;
		long long rmax = 0;

		for (int i = n - 1; i >= 0; i--)
		{
			while (ptr > 0 && ptr >= right[i])
			{
				if (right[ptr] - ptr > rmax)
				{
					rmax = right[ptr] - ptr;
				}

				ptr--;
			}

			const long long add = max(rmax, right[ptr] - right[i]);

			if (add + (right[i] - i) > sol)
			{
				sol = add + (right[i] - i);
			}
		}

		printf("%lld\n", sol);
	}

	return 0;
}