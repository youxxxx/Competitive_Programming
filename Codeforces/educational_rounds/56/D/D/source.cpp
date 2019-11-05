#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int *check;
bool *visited;

long long dfs(vector<vector<int>> &graph, int cur, int parent, bool odd)
{
	int i;
	int next;
	long long sum = 0;
	long long rvalue;
	bool found = false;

	visited[cur] = true;

	if (graph[cur].size() == 1 && parent != 0)
	{
		if (odd)
		{
			return 2;
		}

		return 1;
	}

	for (i = 0; i < graph[cur].size(); i++)
	{
		next = graph[cur][i];
		
		if (next == parent)
		{
			continue;
		}

		if (check[next] == check[cur])
		{
			return -1;
		}

		rvalue = 0;

		if (check[next] == -1)
		{
			found = true;

			check[next] = (int)(!odd);

			rvalue = dfs(graph, next, cur, !odd);
		}

		if (rvalue == -1)
		{
			return -1;
		}

		sum = (sum + rvalue) % 998244353;
	}

	if (!found)
	{
		if (odd)
		{
			return 2;
		}

		return 1;
	}

	if (odd)
	{
		return (sum * 2) % 998244353;
	}

	return sum;
}

int main()
{
	int t, z;
	int n, m;
	int i, j;
	vector<vector<int>> graph;
	vector<int> emp;
	int input1, input2;
	long long sol0, sol1, sum, total;
	bool valid;

	check = new int[300001];

	visited = new bool[300001];

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d %d", &n, &m);

		total = 1;

		valid = true;

		for (i = 0; i <= n; i++)
		{
			graph.push_back(emp);

			visited[i] = false;
		}

		for (i = 0; i < m; i++)
		{
			scanf("%d %d", &input1, &input2);

			graph[input1].push_back(input2);
			graph[input2].push_back(input1);
		}

		for (j = 1; j <= n; j++)
		{
			if (visited[j])
			{
				continue;
			}

			visited[j] = true;

			if (graph[j].size() == 0)
			{
				total = (total * 3) % 998244353;

				continue;
			}

			for (i = 0; i <= n; i++)
			{
				check[i] = -1;
			}

			check[j] = 0;

			sol0 = dfs(graph, j, 0, false);

			if (sol0 == -1)
			{
				valid = false;
				
				break;
			}

			else
			{
				for (i = 0; i <= n; i++)
				{
					check[i] = -1;
				}

				check[j] = 1;

				sol1 = dfs(graph, j, 0, true);

				if (sol1 == -1)
				{
					valid = false;

					break;
				}

				else
				{
					sum = (sol0 + sol1) % 998244353;
				}
			}

			total = (total*sum) % 998244353;
		}

		if (!valid)
		{
			printf("0\n");
		}

		else
		{
			printf("%I64d\n", total);
		}

		graph.clear();
	}

	return 0;
}