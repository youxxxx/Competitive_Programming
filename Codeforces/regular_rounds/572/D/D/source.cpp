#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

vector<int> graph[100001];
int deg[100001] = { 0, };
bool leaf[100001] = { 0, };

int main()
{
	int n;
	int u, v;
	int i, j;

	scanf("%d", &n);

	if (n == 2)
	{
		printf("YES\n");

		return 0;
	}

	if (n == 3)
	{
		printf("NO\n");

		return 0;
	}

	for (i = 0; i < n - 1; i++)
	{
		scanf("%d %d", &u, &v);

		graph[u].push_back(v);

		graph[v].push_back(u);
	}

	for (i = 1; i <= n; i++)
	{
		if (graph[i].size() == 1)
		{
			leaf[i] = true;

			deg[graph[i][0]]++;

			if (graph[graph[i][0]].size() == 2)
			{
				printf("NO\n");

				return 0;
			}
		}
	}

	for (i = 1; i <= n; i++)
	{
		if (!leaf[i])
		{
			if (graph[i].size() == 2)
			{
				printf("NO\n");

				return 0;
			}
		}
	}

	printf("YES\n");

	return 0;
}