#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

bool func(const pair<int, int> &a, const pair<int, int> &b)
{
	return a.second < b.second;
}

int dfs(vector<int> *tree, vector<int> &weight, int cur)
{
	int i;
	int sum = 0;

	if (tree[cur].empty())
	{
		return 1;
	}

	for (i = 0; i < tree[cur].size(); i++)
	{
		sum += dfs(tree, weight, tree[cur][i]);
	}

	weight[cur] = sum;

	return sum;
}

int main()
{
	int n;
	vector<int> *tree;
	vector<int> weight;
	//vector<int> parent = { 0, 0 };
	vector<pair<int, int>> level;
	set<int> nodes;
	set<int>::iterator it;
	int i;
	int input;
	int flag = 1;
	int cur = 0;
	int prev = 0;
	int ptr;

	scanf("%d", &n);

	tree = new vector<int>[n + 1];

	weight.push_back(0);
	weight.push_back(0);

	for (i = 2; i <= n; i++)
	{
		scanf("%d", &input);

		tree[input].push_back(i);

		//parent.push_back(input);

		weight.push_back(0);
	}

	dfs(tree, weight, 1);

	for (i = 1; i <= n; i++)
	{
		level.push_back(pair<int, int>(i, weight[i]));
	}

	sort(level.begin(), level.end(), func);

	for (i = 0; i < n; i++)
	{
		printf("%d ", level[i].second + !level[i].second);
	}

	/*
	for (i = 2; i <= n; i++)
	{
		if (tree[i].empty())
		{
			level[0].push_back(pair<int, int>(i, 0));
		}
	}

	cur = level[0].size();

	for (i = 0; i < cur; i++)
	{
		printf("1 ");
	}

	for (i = 0; i < level[0].size(); i++)
	{
		nodes.insert(parent[level[0][i].first]);
	}

	for (it = nodes.begin(); it != nodes.end(); it++)
	{
		level[1].push_back(pair<int, int>(*it, tree[*it].size()));
	}

	sort(level[1].begin(), level[1].end(), func);

	level[0].clear();

	nodes.clear();

	while (level[flag][0].first)
	{
		for (i = 0; i < level[flag].size(); i++)
		{
			cur += level[flag][i].second;

			printf("%d ", cur);
		}

		for (i = 0; i < level[flag].size(); i++)
		{
			nodes.insert(parent[level[flag][i].first]);
		}

		for (it = nodes.begin(); it != nodes.end(); it++)
		{
			level[!flag].push_back(pair<int, int>(*it, tree[*it].size()));
		}

		sort(level[!flag].begin(), level[!flag].end(), func);

		level[flag].clear();

		flag = !flag;

		nodes.clear();
	}
	*/
	return 0;
}