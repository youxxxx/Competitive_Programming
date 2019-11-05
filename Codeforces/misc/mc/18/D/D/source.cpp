#include<cstdio>
#include<cmath>
#include<vector>
#include<set>
#include<queue>

using namespace std;

int main()
{
	vector<int> *graph;
	bool *visited;
	int n;
	int i;
	int input1, input2;
	int curind;
	int cnt = 1;
	queue<pair<int, int>> q;
	pair<int, int> cur;
	set<int> valid, test;

	scanf("%d", &n);

	graph = new vector<int>[n + 1];
	visited = new bool[n + 1];

	for (i = 0; i < n - 1; i++)
	{
		scanf("%d %d", &input1, &input2);

		graph[input1].push_back(input2);
		graph[input2].push_back(input1);

		visited[i + 2] = false;
	}

	visited[1] = true;

	scanf("%d", &input1);

	if (input1 != 1)
	{
		printf("No");

		for (i = 0; i < n - 1; i++)
		{
			scanf("%d", &input2);
		}

		return 0;
	}

	for (i = 0; i < graph[1].size(); i++)
	{
		q.push(pair<int, int>(graph[1][i], 1));

		visited[graph[1][i]] = true;

		valid.insert(graph[1][i]);
	}

	while (!valid.empty())
	{
		for (i = 0; i < valid.size(); i++)
		{
			scanf("%d", &input1);

			cnt++;

			test.insert(input1);
		}

		if (valid != test)
		{
			printf("No");

			for (i = 0; i < n - cnt; i++)
			{
				scanf("%d", &input2);
			}

			return 0;
		}

		if (q.empty())
		{
			break;
		}

		valid.clear();

		cur = q.front();
		curind = cur.second;

		while (!q.empty() && cur.second == curind)
		{
			for (i = 0; i < graph[cur.first].size(); i++)
			{
				if (!visited[graph[cur.first][i]])
				{
					visited[graph[cur.first][i]] = true;

					q.push(pair<int, int>(graph[cur.first][i], curind + 1));

					valid.insert(graph[cur.first][i]);
				}
			}

			q.pop();

			if (q.empty())
			{
				break;
			}

			cur = q.front();
		}

		test.clear();
	}

	printf("Yes");

	return 0;
}