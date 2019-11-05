#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int n;

void first(vector<vector<int>> &graph, vector<long long> &cost, int cur, int parent, long long dis, long long &max)
{
	int i;

	max += dis*cost[cur];

	for (i = 0; i < graph[cur].size(); i++)
	{
		if (graph[cur][i] == parent)
		{
			continue;
		}

		first(graph, cost, graph[cur][i], cur, dis + 1, max);
	}
}

void dfs(vector<vector<int>> &graph, vector<long long> &cost, int cur, int parent, long long cand, long long &max, long long sum)
{
	int i;

	if (parent != 0)
	{
		cand -= sum;
	}

	if (cand > max)
	{
		max = cand;
	}

	sum -= cost[cur] * 2;

	for (i = 0; i < graph[cur].size(); i++)
	{
		if (graph[cur][i] == parent)
		{
			continue;
		}

		dfs(graph, cost, graph[cur][i], cur, cand, max, sum);
	}
}

int main()
{
	int i;
	int input;
	vector<vector<int>> graph;
	vector<int> emp;
	vector<long long> cost;
	int input1, input2;
	int root = 0;
	long long max = 0;
	long long sum = 0;

	cost.push_back(0);
	graph.push_back(emp);

	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		scanf("%d", &input1);
		
		cost.push_back(input1);
		graph.push_back(emp);

		sum += input1;
	}

	for (i = 1; i < n; i++)
	{
		scanf("%d %d", &input1, &input2);

		graph[input1].push_back(input2);
		graph[input2].push_back(input1);
	}

	for (i = 1; i <= n; i++)
	{
		if (graph[i].size() == 1)
		{
			root = i;

			break;
		}
	}

	first(graph, cost, root, 0, 0, max);
	dfs(graph, cost, root, 0, max, max, sum);

	printf("%I64d\n", max);

	return 0;
}