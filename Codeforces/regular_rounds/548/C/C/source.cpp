#include<cstdio>
#include<string>
#include<vector>
#include<stack>
#include<set>

using namespace std;

int n, k;
vector<pair<int, int>> emp;
vector<int> emp2;
vector<vector<pair<int, int>>> graph;
vector<vector<int>>	good;

pair<vector<int>,vector<int>> dfs(int prev,int cur,vector<int> red,vector<int> black, bool blackedge)
{
	int i, j;
	int next;
	int color;
	vector<int> add;
	vector<int> nred, nblack;
	pair<vector<int>, vector<int>> ret;

	/*
	add = black;
	//add.reserve = (red.size() + black.size());
	add.insert(add.end(), red.begin(), red.end());
	add.insert(add.end(), black.begin(), black.end());
	*/

	if (prev && graph[cur].size() == 1)
	{
		if (!blackedge)
		{
			ret.first.push_back(cur);
		}

		else
		{
			ret.second.push_back(cur);
		}

		return ret;
	}

	for (i = 0; i < graph[cur].size(); i++)
	{
		next = graph[cur][i].first;

		if (next == prev)
		{
			continue;
		}

		color = graph[cur][i].second;

		if (color)
		{
			for (j = 0; j < red.size(); j++)
			{
				good[red[j]].push_back(next);
				good[next].push_back(red[j]);
			}

			for (j = 0; j < black.size(); j++)
			{
				good[black[j]].push_back(next);
				good[next].push_back(black[j]);
			}

			black.insert(black.end(), red.begin(), red.end());
			red.clear();
			red.push_back(next);

			ret = dfs(cur, next, red, black, true);

			black.insert(black.end(), ret.first.begin(), ret.first.end());
			black.insert(black.end(), ret.second.begin(), ret.second.end());
		}

		else
		{
			for (j = 0; j < black.size(); j++)
			{
				good[black[j]].push_back(next);
				good[next].push_back(black[j]);
			}

			red.push_back(next);

			ret = dfs(cur, next, red, black, false);

			red.insert(red.end(), ret.first.begin(), ret.first.end());
			black.insert(black.end(), ret.second.begin(), ret.second.end());
		}
	}

	if (!blackedge)
	{
		ret.first.push_back(cur);
	}

	else
	{
		ret.second.insert(ret.second.end(), ret.first.begin(), ret.first.end());
		ret.first.clear();
		ret.second.push_back(cur);
	}

	return ret;
}
int main()
{
	int i, j;
	int z;
	int u, v, color;
	//bool visited[100001] = { 0, };
	vector<int> start;
	long long *dpr[2],*dpb[2];
	long long sum = 0;
	long long prev = 0;
	long long pwr;

	scanf("%d %d", &n, &z);

	dpr[0] = new long long[n + 1];
	dpr[1] = new long long[n + 1];
	dpb[0] = new long long[n + 1];
	dpb[1] = new long long[n + 1];

	for (i = 0; i <= n; i++)
	{
		graph.push_back(emp);
		good.push_back(emp2);
		dpr[0][i] = 1;
		dpb[0][i] = 0;
	}

	for (i = 0; i < n - 1; i++)
	{
		scanf("%d %d %d", &u, &v, &color);

		graph[u].push_back(pair<int, int>(v, color));
		graph[v].push_back(pair<int, int>(u, color));
	}

	//visited[1] = true;

	start.push_back(1);

	dfs(0, 1, start, emp2, false);

	pwr = 1;

	for (i = 1; i < z; i++)
	{
		pwr = pwr*n % 1000000007;

		for (j = 1; j <= n; j++)
		{
			dpb[i % 2][j] = 0;
		}

		for (j = 1; j <= n; j++)
		{
			for (k = 0; k < good[j].size(); k++)
			{
				dpb[i % 2][good[j][k]] = (dpb[i % 2][good[j][k]] + dpr[!(i % 2)][j]) % 1000000007;
			}

			dpb[i % 2][j] = (dpb[i % 2][j] + prev) % 1000000007;
		}

		prev = 0;

		for (j = 1; j <= n; j++)
		{
			prev = (prev + dpb[i % 2][j]) % 1000000007;

			dpr[i % 2][j] = (pwr - dpb[i % 2][j] + 1000000007) % 1000000007;
		}
	}

	for (i = 1; i <= n; i++)
	{
		sum = (sum + dpb[!(z % 2)][i]) % 1000000007;
	}

	printf("%I64d\n", sum);

	return 0;
}