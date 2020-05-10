#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

vector<int> graph[2][2001];
int interv[2][1001][1001] = { 0, };
int parent[2][2001];
int link[2][2001] = { 0, };
int n, m[2];

pair<pair<int,int>,int> dfs(int type, int cur)
{
	vector<pair<pair<int, int>, int>> ret;

	if (graph[type][cur].empty())
	{
		return{ {link[type][cur],link[type][cur]},0 };
	}

	for (int i = 0; i < graph[type][cur].size(); i++)
	{
		int next;

		next = graph[type][cur][i];

		ret.push_back(dfs(type, next));

		ret.back().second++;

		interv[type][ret.back().first.first][ret.back().first.second]++;
	}

	sort(ret.begin(), ret.end());

	for (int i = 0; i < ret.size() - 1; i++)
	{
		for (int k = ret[i].first.first; k <= ret[i].first.second; k++)
		{
			int base, acc = 0;

			base = interv[type][k][ret[i].first.second];

			for (int j = i + 1; j < ret.size(); j++)
			{
				for (int l = ret[j].first.first; l < ret[j].first.second; l++)
				{
					interv[type][k][l] = base + interv[type][ret[j].first.first][l] + acc;
				}

				interv[type][k][ret[j].first.second] = base + interv[type][ret[j].first.first][ret[j].first.second] + acc;

				acc += ret[j].second;
			}
		}
	}

	return{ {ret.front().first.first,ret.back().first.second},interv[type][ret.front().first.first][ret.back().first.second] };
}

int main()
{
	//freopen("input.txt", "r", stdin);

	scanf("%d", &n);

	for (int i = 0; i < 2; i++)
	{
		scanf("%d", &m[i]);

		for (int j = 2; j <= m[i]; j++)
		{
			scanf("%d", &parent[i][j]);

			graph[i][parent[i][j]].push_back(j);
		}

		for (int j = 1; j <= n; j++)
		{
			int input;

			scanf("%d", &input);

			link[i][input] = j;
		}
	}

	dfs(0, 1);
	dfs(1, 1);

	int sol[2][1001][1001];

	memset(sol, -1, sizeof(sol));

	sol[0][0][1] = sol[1][0][1] = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				if (sol[!j][i - 1][k] == -1)
				{
					break;
				}

				if (sol[j][i][1] == -1 || sol[!j][i - 1][k] + interv[j][i][i] > sol[j][i][1])
				{
					sol[j][i][1] = sol[!j][i - 1][k] + interv[j][i][i];
				}
			}
		}

		for (int j = 0; j < 2; j++)
		{
			for (int k = 2; k <= n; k++)
			{
				if (sol[j][i - 1][k - 1] == -1)
				{
					break;
				}

				sol[j][i][k] = sol[j][i - 1][k - 1] + interv[j][i - k + 1][i] - interv[j][i - k + 1][i - 1];
			}
		}
	}

	int lmax = 0;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (sol[i][n][j] > lmax)
			{
				lmax = sol[i][n][j];
			}
		}
	}

	printf("%d\n", lmax);

	return 0;
}