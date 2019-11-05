#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main()
{
	int n, m;
	int u, v;
	int i, j, k;
	vector<int> graph[200001];
	bool visited[200001] = { false };
	bool target[200001] = { false };
	queue<pair<int,long long>> q;
	pair<int, long long> cur;
	int next;
	vector<long long> branch[200001], totmax;
	int dead[200001] = { 0, };
	long long val[200001];
	long long add = 0;
	long long lmax = 0;
	long long sol = 0;
	int vertex;
	long long cost;
	bool inbranch = false;
	long long base = 0, acc = 0;
	int s;

	//freopen("input.txt", "r", stdin);

	scanf("%d %d", &n, &m);

	for (i = 1; i <= n; i++)
	{
		scanf("%lld", &val[i]);
	}

	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &u, &v);

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	scanf("%d", &s);

	for (i = 1; i <= n; i++)
	{
		if (graph[i].size() == 1)
		{
			visited[i] = true;

			next = graph[i][0];

			if (graph[i].size() == dead[i])
			{
				for (j = 0; j < branch[i].size(); j++)
				{
					sol += branch[i][j];
				}

				printf("%lld\n", sol);

				return 0;
			}

			for (j = 0; j < branch[next].size(); j++)
			{
				if (val[i] > branch[next][j])
				{
					branch[next].insert(branch[next].begin() + j, val[i]);

					break;
				}
			}

			if (j == branch[next].size())
			{
				branch[next].push_back(val[i]);
			}

			if (branch[next].size() == 3)
			{
				branch[next].pop_back();
			}

			if (graph[next].size() - ++dead[next] <= 1)
			{
				q.push(make_pair(next, val[i]));
			}

			dead[i]++;
		}
	}

	while (!q.empty())
	{
		cur = q.front();
		q.pop();

		vertex = cur.first;
		cost = cur.second;

		visited[vertex] = true;

		if (graph[vertex].size() == dead[i])
		{
			sol = 0;

			for (j = 0; j < branch[vertex].size(); j++)
			{
				sol += branch[vertex][j];
			}

			printf("%lld\n", sol);

			return 0;
		}

		if (vertex == s)
		{
			inbranch = true;

			if (branch[vertex][0] > sol)
			{
				sol = branch[vertex][0];
			}

			acc += val[s];

			target[s] = true;
		}

		for (i = 0; i < graph[vertex].size(); i++)
		{
			next = graph[vertex][i];

			if (visited[next])
			{
				continue;
			}

			if (graph[next].size() - ++dead[next] <= 1)
			{
				if (!target[vertex])
				{
					q.push(make_pair(next, cost + val[vertex]));
				}

				else
				{
					q.push(make_pair(next, 0));

					target[next] = true;
				}
			}

			if(!target[vertex])
			{
				for (j = 0; j < branch[next].size(); j++)
				{
					if (val[i] > branch[next][j])
					{
						branch[next].insert(branch[next].begin() + j, val[i]);

						break;
					}
				}

				if (j == branch[next].size())
				{
					branch[next].push_back(val[i]);
				}

				if (branch[next].size() == 3)
				{
					branch[next].pop_back();
				}
			}
		}

		dead[vertex]++;
	}

	for (i = 1; i <= n; i++)
	{
		if (!target[i] && dead[i] != graph[i].size())
		{
			add += val[i];
		
			for (k = 0; k < branch[i].size(); k++)
			{
				for (j = 0; j < totmax.size(); j++)
				{
					if (branch[i][k] > totmax[j])
					{
						totmax.insert(totmax.begin() + j, branch[i][k]);

						break;
					}
				}

				if (j == totmax.size())
				{
					totmax.push_back(branch[i][k]);
				}

				if (totmax.size() == 2)
				{
					totmax.pop_back();
				}
			}
		}
	}

	for (i = 0; i < totmax.size(); i++)
	{
		lmax += totmax[i];
	}

	if (lmax + add + acc > sol)
	{
		sol = lmax + add + acc;
	}

	printf("%lld\n", sol);


	return 0;
}