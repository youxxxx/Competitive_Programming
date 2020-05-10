#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> graph[100001];
bool avisited[100001] = { 0, };
bool bvisited[100001] = { 0, };
int dist[100001];
int bdist[100001];
int lmax = 0;

void mark(int cur, int curdist)
{
	dist[cur] = curdist;

	for (int i = 0; i < graph[cur].size(); i++)
	{
		int next;

		next = graph[cur][i];

		if (!avisited[next])
		{
			avisited[next] = true;

			mark(next, curdist + 1);
		}
	}
}

void dfs(int cur, int curdist)
{
	bdist[cur] = curdist;

	if (dist[cur] - 1 > lmax)
	{
		lmax = dist[cur] - 1;
	}

	if (curdist < dist[cur])
	{
		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next;

			next = graph[cur][i];

			if (!bvisited[next])
			{
				bvisited[next] = true;

				dfs(next, curdist + 1);
			}
		}
	}
}

int main()
{
	int n;
	int u, v;

	//freopen("input.txt", "r", stdin);

	scanf("%d %d %d", &n, &u, &v);

	for (int i = 0; i < n - 1; i++)
	{
		int a, b;

		scanf("%d %d", &a, &b);

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	avisited[v] = true;
	mark(v, 0);

	bvisited[u] = true;
	dfs(u, 0);

	printf("%d\n", lmax);

	return 0;
}
