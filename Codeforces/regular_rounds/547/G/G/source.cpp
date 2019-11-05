#include<cstdio>
#include<vector>
#include<map>
#include<queue>

using namespace std;

int main()
{
	int n, k;
	int cnt[200001] = { 0, };
	int i;
	int input1, input2;
	vector<vector<int>> graph;
	vector<int> emp;
	map<int, int> deg;
	map<int, int>::iterator it, ret;
	int acc = 0;
	int idx = 0;
	queue < pair<int, int>> q;
	pair<int, int> cur;
	int clr;

	scanf("%d %d", &n, &k);

	for (i = 0; i <= n; i++)
	{
		graph.push_back(emp);
	}

	for (i = 0; i < n - 1; i++)
	{
		scanf("%d %d", &input1, &input2);

		cnt[input1]++;
		cnt[input2]++;

		graph[input1].push_back(input2);
		graph[input2].push_back(input1);
	}

	for (i = 1; i <= n; i++)
	{
		ret = deg.find(cnt[i]);

		if (ret == deg.end())
		{
			deg[cnt[i]] = 1;
		}

		else
		{
			ret->second++;
		}
	}

	for (it = deg.begin(); it != deg.end(); it++)
	{
		if (acc + it->second > (n - k))
		{
			break;
		}

		acc += it->second;
		idx++;
	}

	idx = n - idx;

	clr = 1;

	for (i = 0; i < graph[1].size(); i++)
	{

	}

	while (!q.empty())
	{
		cur = q.front();
		q.pop();


	}

	return 0;
}