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

vector<int> graph[300001];
int parent[300001];
int height[300001];

void dfs(int cur, int parent, int h)
{
	height[cur] = h;

	for (int i = 0; i < graph[cur].size(); i++)
	{
		const int next = graph[cur][i];

		if (next == parent)
		{
			continue;
		}

		dfs(next, cur, h + 1);
	}
}

bool func(const pair<int, int> &a, const pair<int, int> &b)
{
	return height[a.first] < height[b.first] || height[a.first] == height[b.first] && height[a.second] < height[b.second];
}

int main()
{
	//freopen("input.txt", "r", stdin);

	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &parent[i]);

		graph[parent[i]].push_back(i);
	}

	pair<int, int> arr[300001];

	for (int i = 0; i < m; i++)
	{
		int x, y;

		scanf("%d %d", &x, &y);

		arr[i] = { x,y };
	}

	dfs(0, -1, 0);

	sort(&arr[0], &arr[m], func);

	for (int i = 0; i < m; i++)
	{
		const int x = arr[i].first;
		const int y = arr[i].second;


	}

	return 0;
}