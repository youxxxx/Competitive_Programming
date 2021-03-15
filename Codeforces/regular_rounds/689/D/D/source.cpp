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

#define N 1000000

long long tree[N + 2];

void add(int idx, long long val)
{
	for (; idx <= N; idx += idx&(-idx))
	{
		tree[idx] += val;
	}
}

long long get(int idx)
{
	long long rvalue = 0;

	for (; idx; idx -= idx&(-idx))
	{
		rvalue += tree[idx];
	}

	return rvalue;
}

long long psum(int r, int l)
{
	return get(r) - get(l);
}

int main()
{
	freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n, m;

		scanf("%d %d", &n, &m);

		memset(tree, 0, sizeof(tree));

		set<long long> list;

		long long arr[100001];

		long long tot = 0;

		long long lmin = 1000001;
		long long lmax = 0;

		for (int i = 0; i < n; i++)
		{
			scanf("%lld", &arr[i]);

			add(arr[i], arr[i]);

			tot += arr[i];

			lmin = min(lmin, arr[i]);
			lmax = max(lmax, arr[i]);
		}

		list.insert(tot);

		queue<pair<long long, long long>> q;

		q.push({ lmin,lmax });

		while (!q.empty())
		{
			const long long lmin = q.front().first;
			const long long lmax = q.front().second;
			q.pop();
			const long long mid = (lmin + lmax) / 2;
			const long long lsum = psum(mid, lmin - 1);
			const long long rsum = psum(lmax, mid);

			list.insert(lsum);
			list.insert(rsum);

			if (lsum != 0 && rsum != 0 && lmin != lmax)
			{
				q.push({ lmin,mid });
				q.push({ mid + 1,lmax });
			}
		}

		for (int i = 0; i < m; i++)
		{
			long long input;

			scanf("%lld", &input);

			set<long long>::iterator ret = list.find(input);

			if (ret != list.end())
			{
				printf("Yes\n");
			}

			else
			{
				printf("No\n");
			}
		}
	}

	return 0;
}