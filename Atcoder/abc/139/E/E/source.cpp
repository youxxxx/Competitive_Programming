#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

int main()
{
	int n;
	vector<pair<int,int>> out[1001][1001];
	int in[1001][1001] = { 0, };
	int i, j;
	int u, v, temp;
	int pu, pv;
	queue<pair<int, int>> q, buf;
	int cnt = 0, sol = 0;
	pair<int, int> cur;

	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		u = i;

		scanf("%d", &v);

		if (u > v)
		{
			temp = u;
			u = v;
			v = temp;
		}

		pu = u;
		pv = v;

		for (j = 1; j < n - 1; j++)
		{
			u = i;

			scanf("%d", &v);

			if (u > v)
			{
				temp = u;
				u = v;
				v = temp;
			}

			out[pu][pv].push_back(make_pair(u, v));
			in[u][v]++;

			pu = u;
			pv = v;
		}
	}

	for (i = 1; i < n; i++)
	{
		for (j = i + 1; j <= n; j++)
		{
			if (!in[i][j])
			{
				q.push(make_pair(i, j));
			}
		}
	}

	for (i = 0; i < n*n; i++)
	{
		if (cnt + q.size() == n*(n - 1) / 2 || q.empty())
		{
			break;
		}

		while (!q.empty())
		{
			cur = q.front();
			q.pop();

			cnt++;

			u = cur.first;
			v = cur.second;

			for (j = 0; j < out[u][v].size(); j++)
			{
				if (!(--in[out[u][v][j].first][out[u][v][j].second]))
				{
					buf.push(out[u][v][j]);
				}
			}
		}

		i = i;

		while (!buf.empty())
		{
			q.push(buf.front());
			buf.pop();
		}
	}

	if (cnt + q.size() != n*(n - 1) / 2)
	{
		printf("-1\n");
	}

	else
	{
		printf("%d\n", i + 1);
	}

	return 0;
}