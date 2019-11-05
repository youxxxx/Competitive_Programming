#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<cstring>

using namespace std;

bool func(const pair<long long, pair<int, int>> &a, const  pair<long long, pair<int, int>> &b)
{
	return a.first < b.first;
}

int main()
{
	int n, m, k;
	int i, j, l;
	vector <pair<long long, pair<int, int>>> path;
	vector <pair<long long, pair<int, int>>>::iterator ret;
	pair<long long, pair<int, int>> cur;
	set<int> vertex;
	set<int>::iterator it;
	long long dist;
	int u, v;
	int arrsize, range;
	int rev[200001];
	int vsize;
	long long table[800][800];
	vector<long long> edge;

	memset(table, -1, sizeof(table));

	//freopen("input.txt", "r", stdin);

	scanf("%d %d %d", &n, &m, &k);

	for (i = 0; i < m; i++)
	{
		scanf("%d %d %lld", &u, &v, &dist);

		path.push_back(make_pair(dist, make_pair(u, v)));
	}

	sort(path.begin(), path.end());

	range = m < k ? m : k;

	for (i = 0; i < range; i++)
	{
		vertex.insert(path[i].second.first);
		vertex.insert(path[i].second.second);
	}
	
	vsize = 0;

	for (it = vertex.begin(); it != vertex.end(); it++)
	{
		rev[*it] = vsize++;
	}

	for (i = 0; i < range; i++)
	{
		table[rev[path[i].second.first]][rev[path[i].second.second]] = path[i].first;
		table[rev[path[i].second.second]][rev[path[i].second.first]] = path[i].first;
	}

	for (i = 0; i < vsize; i++)
	{
		for (j = 0; j < vsize; j++)
		{
			if (i == j)
			{
				continue;
			}

			for (l = 0; l < vsize; l++)
			{
				if (l == i || l == j)
				{
					continue;
				}

				if (table[j][i] != -1 && table[i][l] != -1 && (table[j][l] == -1 || table[j][i] + table[i][l] < table[j][l]))
				{
					table[j][l] = table[l][j] = table[j][i] + table[i][l];
				}
			}
		}
	}

	for (i = 0; i < vsize; i++)
	{
		for (j = i; j < vsize; j++)
		{
			if (table[i][j] != -1)
			{
				edge.push_back(table[i][j]);
			}
		}
	}

	sort(edge.begin(), edge.end());

	printf("%lld\n", edge[k - 1]);

	return 0;
}