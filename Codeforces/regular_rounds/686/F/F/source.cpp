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

#define N 200000

int mintree[N * 4];

int setmin(int idx, int val, int cur, int l, int r)
{
	if (l == r)
	{
		return mintree[cur] = val;
	}

	const int mid = (l + r) / 2;

	int ret;

	if (idx <= mid)
	{
		ret = setmin(idx, val, cur * 2, l, mid);
	}

	else
	{
		ret = setmin(idx, val, cur * 2 + 1, mid + 1, r);
	}

	if (ret < mintree[cur])
	{
		mintree[cur] = ret;
	}

	return mintree[cur];
}

int getmin(int lb, int ub, int cur, int l, int r)
{
	if (l == r)
	{
		return mintree[cur];
	}

	if (l > ub || r < lb)
	{
		return 1000000001;
	}

	if (l >= lb && r <= ub)
	{
		return mintree[cur];
	}

	const int mid = (l + r) / 2;

	if (ub <= mid)
	{
		return getmin(lb, ub, cur * 2, l, mid);
	}

	if (lb >= mid + 1)
	{
		return getmin(lb, ub, cur * 2 + 1, mid + 1, r);
	}

	const int left = getmin(lb, ub, cur * 2, l, mid);
	const int right = getmin(lb, ub, cur * 2 + 1, mid + 1, r);


	return left < right ? left : right;
}

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;

		int arr[N + 1];

		scanf("%d", &n);

		for (int i = 1; i < n * 4; i++)
		{
			mintree[i] = 1000000001;
		}

		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &arr[i]);

			setmin(i, arr[i], 1, 1, n);
		}

		vector<pair<int, pair<int, int>>> rmax;
		int lmax[N + 1];
		lmax[0] = 0;

		for (int i = 1; i <= n; i++)
		{
			lmax[i] = max(lmax[i - 1], arr[i]);
		}

		{
			int curmax = -1;
			int start;

			for (int i = n; i >= 1; i--)
			{
				if (arr[i] > curmax)
				{
					if (curmax != -1)
					{
						rmax.push_back({ curmax,{ i + 1,start } });
					}

					curmax = arr[i];

					start = i;
				}
			}

			rmax.push_back({ curmax,{ 1, start } });
		}

		int ptr = 0;

		bool found = false;

		for (int i = 1; i <= n - 2; i++)
		{
			while (ptr < (int)rmax.size() && rmax[ptr].first < lmax[i])
			{
				ptr++;
			}

			if (ptr == (int)rmax.size())
			{
				break;
			}

			if (rmax[ptr].first>lmax[i])
			{
				continue;
			}

			const int l = max(rmax[ptr].second.first, i + 2);
			const int r = rmax[ptr].second.second;

			if (l > r)
			{
				continue;
			}

			int lb = l - 1;
			int ub = r;

			for (int next = (lb + ub) / 2; ub - lb > 1; next = (lb + ub) / 2)
			{
				const int ret = getmin(i + 1, next, 1, 1, n);

				if (ret == lmax[i])
				{
					lb = next;

					break;
				}

				else if (ret > lmax[i])
				{
					lb = next;
				}

				else
				{
					ub = next;
				}
			}

			const int ret = getmin(i + 1, lb, 1, 1, n);

			if (ret == lmax[i])
			{
				found = true;

				printf("YES\n%d %d %d\n", i, lb - i, n - lb);

				break;
			}
		}

		if (!found)
		{
			printf("NO\n");
		}
	}

	return 0;
}