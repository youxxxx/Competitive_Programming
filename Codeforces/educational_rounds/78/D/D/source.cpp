#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>

using namespace std;

bool func(const pair<int, int> &a, const pair<int, int> &b)
{
	return a.first<b.first || a.first == b.first&&a.second>b.second;
}

bool visited[500000] = { 0 };
vector<int> graph[500000];

void dfs(int cur)
{
	for (int i = 0; i < graph[cur].size(); i++)
	{
		int next;

		next = graph[cur][i];

		if (!visited[next])
		{
			visited[next] = true;

			dfs(next);
		}
	}
}

int main()
{
	int n;
	vector<pair<int, int>> arr;

	//freopen("input.txt", "r", stdin);

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int l, r;

		scanf("%d %d", &l, &r);

		arr.push_back({ l,r });
	}

	sort(arr.begin(), arr.end(), func);

	int prev = -1;

	map<int,int> s;

	int cnt = 0;

	s[arr[0].second] = 0;

	for (int i = 1; i < n; i++)
	{
		map<int,int>::iterator ret;

		ret = s.lower_bound(arr[i].first);

		for (map<int, int>::iterator it = ret; it != s.end(); it++)
		{
			if (it->first > arr[i].second)
			{
				break;
			}

			if (++cnt >= n)
			{
				break;
			}

			graph[it->second].push_back(i);
			graph[i].push_back(it->second);
		}

		if (cnt >= n)
		{
			break;
		}

		s[arr[i].second] = i;
	}

	if (cnt != n - 1)
	{
		printf("NO\n");

		return 0;
	}

	visited[0] = true;

	dfs(0);

	for (int i = 1; i < n; i++)
	{
		if (!visited[i])
		{
			printf("NO\n");

			return 0;
		}
	}

	printf("YES\n");

	return 0;
}