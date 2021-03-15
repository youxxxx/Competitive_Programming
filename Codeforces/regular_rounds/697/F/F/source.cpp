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

#define N 1000

int assign[2 * N + 1][2];
vector<pair<int, int>> graph[2 * N + 1][2];
vector < vector<pair<int, int>>> scc;
int cnt = 0;
int depth[2 * N + 1][2];
int group[2 * N + 1][2];
stack<pair<int, int>> s;
int in[4 * N + 1] = { 0, };
set<int> out[4 * N + 1];
int sccval[4 * N + 1] = { 0, };
int curdepth = 0;

int dfs(int cur, int pos)
{
	s.push({ cur,pos });

	int rvalue = depth[cur][pos] = curdepth++;

	for (int i = 0; i < (int)graph[cur][pos].size(); i++)
	{
		const int next = graph[cur][pos][i].first;
		const int nextpos = graph[cur][pos][i].second;

		if (depth[next][nextpos] == -1)
		{
			const int ret = dfs(next, nextpos);

			if (ret < rvalue)
			{
				rvalue = ret;
			}

			continue;
		}

		if (group[next][nextpos] == -1)
		{
			if (depth[next][nextpos] < rvalue)
			{
				rvalue = depth[next][nextpos];
			}
		}
	}

	if (depth[cur][pos] == rvalue)
	{
		vector<pair<int, int>> temp;

		int next, nextpos;

		do
		{
			next = s.top().first;
			nextpos = s.top().second;
			s.pop();

			group[next][nextpos] = cnt;

			temp.push_back({ next,nextpos });
		} while (!(next == cur&&nextpos == pos));

		scc.push_back(temp);

		cnt++;
	}

	return rvalue;
}


int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	vector<string> mat;

	for (int tc = 0; tc < cases; tc++)
	{
		int n, m;

		scanf("%d", &n);

		mat.clear();

		for (int i = 1; i <= 2 * n; i++)
		{
			depth[i][0] = depth[i][1] = group[i][0] = group[i][1] = assign[i][0] = assign[i][1] = -1;

			graph[i][0].clear();
			graph[i][1].clear();
		}

		for (int i = 1; i <= 4 * n; i++)
		{
			out[i].clear();
		}

		while (!s.empty())
		{
			s.pop();
		}

		scc.clear();
		cnt = 0;
		curdepth = 0;
		fill(&sccval[0], &sccval[4 * n + 1], -1);
		fill(&in[0], &in[4 * n + 1], -1);

		for (int i = 1; i <= 2 * n; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				graph[i][j].clear();
			}
		}

		for (int i = 0; i < n; i++)
		{
			char input[1001];

			scanf("%s", input);
			const string str = input;

			mat.push_back(str);
		}

		for (int i = 0; i < n; i++)
		{
			char input[1001];

			scanf("%s", input);
			const string str = input;

			for (int j = 0; j < n; j++)
			{
				const int bit = (str[j] != mat[i][j]);

				graph[i + 1][0].push_back({ j + 1 + n,bit });
				graph[i + 1][1].push_back({ j + 1 + n,!bit });
				graph[j + 1 + n][0].push_back({ i + 1,bit });
				graph[j + 1 + n][1].push_back({ i + 1,!bit });
			}
		}

		for (int i = 1; i <= 2 * n; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				if (group[i][j] == -1)
				{
					dfs(i, j);
				}
			}
		}

		bool valid = true;

		for (int i = 1; i <= 2 * n; i++)
		{
			if (group[i][0] == group[i][1])
			{
				valid = false;

				break;
			}
		}

		if (valid)
		{
			printf("YES\n");
		}

		else
		{
			printf("NO\n");
		}
	}

	return 0;
}