#include<cstdio>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<queue>
#include<functional>

using namespace std;

int main()
{
	int n, m;
	priority_queue<int, vector<int>, std::greater<int> > q;
	int i, j;
	vector<vector<int>> graph;
	vector<int> emp;
	int input1, input2;
	int cur;
	bool visited[100001] = { 0, };
	vector<int> list;

	//freopen("input.txt", "r", stdin);

	scanf("%d %d", &n, &m);

	for (i = 0; i <= n; i++)
	{
		graph.push_back(emp);
	}

	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &input1, &input2);

		graph[input1].push_back(input2);

		graph[input2].push_back(input1);
	}

	q.push(1);
	visited[1] = true;

	while (!q.empty())
	{
		cur = q.top();
		q.pop();

		list.push_back(cur);

		for (i = 0; i < graph[cur].size(); i++)
		{
			if (!visited[graph[cur][i]])
			{
				visited[graph[cur][i]] = true;

				q.push(graph[cur][i]);
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		printf("%d ", list[i]);
	}

	return 0;
}