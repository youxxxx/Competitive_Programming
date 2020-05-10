#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>

#define MOD 1000000007
#define N 600000

using namespace std;

int tree[N + 2] = { 0, };

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

int psum(int l, int r)
{
	return get(r) - get(l);
}

int main()
{
	int n, m;
	int pos[300001];
	int lmin[300001], lmax[300001] = { 0, };
	
	//freopen("input.txt", "r", stdin);

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		pos[i] = n - i + 1;

		add(i, 1);

		lmin[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int usr;

		scanf("%d", &usr);

		lmin[usr] = 1;

		lmax[usr] = max(lmax[usr], psum(pos[usr] - 1, n + i));

		add(pos[usr], -1);

		pos[usr] = n + i + 1;

		add(pos[usr], 1);
	}

	for (int i = 1; i <= n; i++)
	{
		int usr;

		usr = i;

		lmax[usr] = max(lmax[usr], psum(pos[usr] - 1, n + m));

		printf("%d %d\n", lmin[usr], lmax[usr]);
	}

	return 0;
}