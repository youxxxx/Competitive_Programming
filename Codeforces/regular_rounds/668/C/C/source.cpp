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

#define N 300000

int tree[N + 2] = { 0, };

void add(int idx, int val)
{
	for (; idx <= N; idx += (idx&(-idx)))
	{
		tree[idx] += val;
	}
}

int get(int idx)
{
	int rvalue = 0;

	for (; idx; idx -= (idx&(-idx)))
	{
		rvalue += tree[idx];
	}

	return rvalue;
}

int psum(int r, int l)
{
	return get(r) - get(l);
}

int tree2[N + 2] = { 0, };

void add2(int idx, int val)
{
	for (; idx <= N; idx += (idx&(-idx)))
	{
		tree2[idx] += val;
	}
}

int get2(int idx)
{
	int rvalue = 0;

	for (; idx; idx -= (idx&(-idx)))
	{
		rvalue += tree2[idx];
	}

	return rvalue;
}

int psum2(int r, int l)
{
	return get2(r) - get2(l);
}

int main()
{
	//freopen("input.txt", "r", stdin);

	int n, m;

	scanf("%d %d", &n, &m);

	int arr[N + 1];
	int acc[N + 1];
	int count[N + 1];

	acc[0] = 0;

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);

		if (arr[i] > i)
		{
			count[i] = -1;

			acc[i] = acc[i - 1];

			continue;
		}

		if (arr[i] == i)
		{
			count[i] = 0;

			acc[i] = acc[i - 1] + 1;

			add(i, 1);

			continue;
		}

		if (arr[i] + acc[i - 1] >= i)
		{
			count[i] = arr[i] + acc[i - 1] - i + 1;

			acc[i] = acc[i - 1] + 1;

			add(i, 1);

			continue;
		}

		count[i] = -1;

		acc[i] = acc[i - 1];
	}

	vector<int> loc[300001];

	for (int i = 1; i <= n; i++)
	{
		if (count[i] == -1)
		{
			continue;
		}

		if (count[i] == 0)
		{
			add2(i, 1);

			loc[i].push_back(i);

			continue;
		}

		int lb = 0;
		int ub = i - 1;

		for (int next = (lb + ub) / 2; ub - lb > 1; next = (lb + ub) / 2)
		{
			const int ret = get2(next);

			if (ret >= count[i])
			{
				ub = next;
			}

			else
			{
				lb = next;
			}
		}

		add2(ub, 1);

		loc[ub].push_back(i);
	}

	vector<pair<pair<int, int>, int>> query;

	for (int i = 0; i < m; i++)
	{
		int l, r;

		scanf("%d %d", &l, &r);

		query.push_back({ {l,r},i });
	}

	sort(query.begin(), query.end());

	vector<pair<int, int>> sol;

	int cur = 0;

	for (int i = 0; i < m; i++)
	{
		const int l = query[i].first.first;
		const int r = query[i].first.second;
		const int idx = query[i].second;

		while (cur < l)
		{
			cur++;

			for (int j = 0; j < loc[cur].size(); j++)
			{
				add(loc[cur][j], -1);
			}
		}

		sol.push_back({ idx,get(n - r) });
	}

	sort(sol.begin(), sol.end());

	for (int i = 0; i < m; i++)
	{
		printf("%d\n", sol[i].second);
	}

	return 0;
}