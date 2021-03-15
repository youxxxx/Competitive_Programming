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
#define N 200000
#define MAX 1000000000

int mintree[N * 4];
int maxtree[N * 4];

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
		return 0;
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

int setmax(int idx, int val, int cur, int l, int r)
{
	if (l == r)
	{
		return maxtree[cur] = val;
	}

	const int mid = (l + r) / 2;

	int ret;

	if (idx <= mid)
	{
		ret = setmax(idx, val, cur * 2, l, mid);
	}

	else
	{
		ret = setmax(idx, val, cur * 2 + 1, mid + 1, r);
	}

	if (ret > maxtree[cur])
	{
		maxtree[cur] = ret;
	}

	return maxtree[cur];
}

int getmax(int lb, int ub, int cur, int l, int r)
{
	if (l == r)
	{
		return maxtree[cur];
	}

	if (l > ub || r < lb)
	{
		return 0;
	}

	if (l >= lb && r <= ub)
	{
		return maxtree[cur];
	}

	const int mid = (l + r) / 2;

	if (ub <= mid)
	{
		return getmax(lb, ub, cur * 2, l, mid);
	}

	if (lb >= mid + 1)
	{
		return getmax(lb, ub, cur * 2 + 1, mid + 1, r);
	}

	const int left = getmax(lb, ub, cur * 2, l, mid);
	const int right = getmax(lb, ub, cur * 2 + 1, mid + 1, r);

	return left > right ? left : right;
}

int tree[N + 2];

void add(int idx, int val)
{
	for (; idx <= N; idx += (idx&-idx))
	{
		tree[idx] += val;
	}
}

int get(int idx)
{
	int rvalue = 0;

	for (; idx; idx -= (idx&-idx))
	{
		rvalue += tree[idx];
	}

	return rvalue;
}

int psum(int r, int l)
{
	return get(r) - get(l);
}

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);
	
	for (int tc = 0; tc < cases; tc++)
	{
		int n, m;

		scanf("%d %d", &n, &m);

		char input[N + 1];

		scanf("%s", input);
		const string str = input;

		for (int i = 0; i < n * 4; i++)
		{
			mintree[i] = MAX;
			maxtree[i] = -MAX;
		}

		for (int i = 0; i <= n + 1; i++)
		{
			tree[i] = 0;
		}

		setmin(1, 0, 1, 1, n + 1);
		setmax(1, 0, 1, 1, n + 1);

		int curval = 0;

		for (int i = 0; i < n; i++)
		{
			if (str[i] == '+')
			{
				curval++;

				add(i + 1, 1);
			}

			else
			{
				curval--;

				add(i + 1, -1);
			}

			setmin(i + 2, curval, 1, 1, n + 1);
			setmax(i + 2, curval, 1, 1, n + 1);
		}

		for (int i = 0; i < m; i++)
		{
			int l, r;

			scanf("%d %d", &l, &r);

			l++;
			r++;

			int lmin = getmin(1, l - 1, 1, 1, n + 1);
			int lmax = getmax(1, l - 1, 1, 1, n + 1);

			if (r <= n)
			{
				int rmin = getmin(r + 1, n + 1, 1, 1, n + 1);
				int rmax = getmax(r + 1, n + 1, 1, 1, n + 1);

				int del = -psum(r - 1, l - 2);

				printf("%d\n", max(lmax,rmax + del) - min(lmin, rmin + del) + 1);
			}

			else
			{
				printf("%d\n", lmax - lmin + 1);
			}
		}
	}

	return 0;
}