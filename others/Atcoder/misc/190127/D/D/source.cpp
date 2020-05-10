#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>

using namespace std;

bool func(const pair<pair<long long, long long>, long long> &a, pair<pair<long long, long long>, long long> &b)
{
	return a.second > b.second;
}

int main()
{
	int n, m;
	queue<int> q;
	int *indeg;
	int *parent;
	vector<int> *graph;
	int i;
	int input1, input2;
	int cur;

	scanf("%d %d", &n, &m);

	indeg = new int[n + 1];
	parent = new int[n + 1];
	graph = new vector<int>[n + 1];

	for (i = 1; i <= n; i++)
	{
		indeg[i] = 0;
		parent[i] = -1;
	}

	for (i = 0; i < n + m - 1; i++)
	{
		scanf("%d %d", &input1, &input2);

		graph[input1].push_back(input2);

		indeg[input2]++;
	}

	for (i = 1; i <= n; i++)
	{
		if (!indeg[i])
		{
			parent[i] = 0;

			q.push(i);

			break;
		}
	}

	while (!q.empty())
	{
		cur = q.front();

		q.pop();

		for (i = 0; i < graph[cur].size(); i++)
		{
			if (!(--indeg[graph[cur][i]]))
			{
				parent[graph[cur][i]] = cur;

				q.push(graph[cur][i]);
			}
		}
	}

	for (i = 1; i <= n; i++)
	{
		printf("%d\n", parent[i]);
	}

	return 0;
}