#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<queue>

using namespace std;

int main()
{
	int n, m;
	int k;
	vector<int> g[500001], group[500001], list;
	bool visited[500001], visited2[500001];
	int sol[500001];
	int rep[500001];
	int input;
	int ansc;
	int sum;
	int cur;
	int i, j, l;
	int cnt;
	queue<int> q;

	scanf("%d %d", &n, &m);

	for (i = 1; i <= n; i++)
	{
		rep[i] = i;

		sol[i] = 0;
	}

	for (i = 0; i < m; i++)
	{
		scanf("%d", &k);

		list.clear();

		if (k != 0)
		{
			ansc = -1;

			for (j = 0; j < k; j++)
			{
				scanf("%d", &input);

				cur = input;

				while (cur != rep[cur])
				{
					cur = rep[cur];
				}

				list.push_back(input);

				if (ansc == -1 || cur < ansc)
				{
					ansc = cur;
				}
			}

			cur = ansc;

			while (cur != rep[cur])
			{
				cur = rep[cur];
			}

			for (j = 0; j < k; j++)
			{
				rep[list[j]] = cur;
			}
		}
	}

	for (i = 1; i <= n; i++)
	{
		cur = rep[i];

		while (cur != rep[cur])
		{
			cur = rep[cur];
		}

		rep[i] = cur;
	}

	for (i = 1; i <= n; i++)
	{
		sol[rep[i]]++;
	}

	for (i = 1; i <= n; i++)
	{
		printf("%d ", sol[rep[i]]);
	}

	return 0;
}