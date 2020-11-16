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
vector<pair<int,int>> graph[200001][2];
vector<pair<int, int>> loc[200001];
int color[200001];
vector<int> res[2];

bool dfs(int cur, int bit)
{
	for (int i = 0; i < graph[cur][bit].size(); i++)
	{
		const int next = graph[cur][bit][i].first;
		const int nextbit = graph[cur][bit][i].second;

		if (color[next] == !nextbit)
		{
			return false;
		}

		if (color[next] == -1)
		{
			res[nextbit].push_back(next + 1);
			color[next] = nextbit;
			bool ret = dfs(next, nextbit);

			if (!ret)
			{
				false;
			}
		}
	}

	return true;
}

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;

		scanf("%d", &n);

		for (int i = 0; i <= n; i++)
		{
			graph[i][0].clear();
			graph[i][1].clear();
			loc[i].clear();

			color[i] = -1;
		}

		bool valid = true;

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int input;

				scanf("%d", &input);

				if (loc[input].size() == 2)
				{
					valid = false;
				}

				loc[input].push_back({ j,i });
			}
		}

		if (!valid)
		{
			printf("-1\n");

			continue;
		}

		for (int i = 1; i <= n; i++)
		{
			const int x1 = loc[i][0].first;
			const int x2 = loc[i][1].first;
			const int y1 = loc[i][0].second;
			const int y2 = loc[i][1].second;

			if (x1 != x2)
			{
				graph[x1][y1].push_back({ x2,!y2 });
				graph[x1][!y1].push_back({ x2,y2 });
				graph[x2][y2].push_back({ x1,!y1 });
				graph[x2][!y2].push_back({ x1,y1 });
			}
		}

		vector<int> sol;

		for (int i = 0; i < n; i++)
		{
			if (color[i] == -1)
			{
				color[i] = 0;
				res[0].clear();
				res[1].clear();
				res[0].push_back(i + 1);
				bool ret = dfs(i, 0);

				int idx = 0;

				if (res[0].size() > res[1].size())
				{
					idx = 1;
				}

				for (int i = 0; i < res[idx].size(); i++)
				{
					sol.push_back(res[idx][i]);
				}
			}
		}

		printf("%d\n", sol.size());

		for (int i = 0; i < sol.size(); i++)
		{
			printf("%d ", sol[i]);
		}

		printf("\n");
	}

	return 0;
}