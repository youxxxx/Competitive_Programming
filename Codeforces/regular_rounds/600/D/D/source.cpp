#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int group[200001];

int uf(int a)
{
	if (a == group[a])
	{
		return a;
	}

	else return group[a] = uf(group[a]);
}

void disj(int a, int b)
{
	int next;
	int rvalue;
	int ar, br;

	ar = uf(a);
	br = uf(b);

	group[br] = ar;
}

int main()
{
	int n, m;

	//freopen("input.txt", "r", stdin);

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		group[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int u, v;

		scanf("%d %d", &u, &v);

		int temp;

		if (uf(group[u]) > uf(group[v]))
		{
			temp = u;
			u = v;
			v = temp;
		}

		disj(u, v);
	}

	int lmin = n + 1;

	bool visited[200001] = { 0, };

	int sol = 0;

	for (int i = n; i >= 1; i--)
	{
		int ugroup = uf(group[i]);

		if (ugroup <= lmin)
		{
			lmin = ugroup;
		}

		else
		{
			sol++;

			disj(lmin, ugroup);
		}
	}

	printf("%d\n", sol);

	return 0;
}