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

int group[1001];
int rank1[1001] = { 0 , };

int uf(int a)
{
	if (a == group[a])
	{
		return a;
	}

	else return group[a] = uf(group[a]);
}

void disj(int a, int b)
{
	int ar, br;

	ar = uf(a);
	br = uf(b);

	if (ar == br)
	{
		return;
	}

	if (rank1[ar] <= rank1[br])
	{
		group[ar] = br;
	}

	else
	{
		group[br] = ar;
	}

	if (rank1[ar] == rank1[br])
	{
		rank1[ar]++;
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);

	int n;

	pair<long long, long long> coord[1001];

	scanf("%d", &n);

	long long link[1001][1001];
	vector<pair<long long,long long>> graph[1001];

	memset(link, -1, sizeof(link));

	vector<long long> x, y;

	for (int i = 0; i < n; i++)
	{
		long long xi, yi;

		scanf("%lld %lld", &xi, &yi);

		coord[i] = { xi,yi };

		x.push_back(xi);
		y.push_back(yi);

		for (int j = 0; j < i; j++)
		{
			if (coord[i].first == coord[j].first)
			{
				const long long dist = abs(coord[i].second - coord[j].second);
				link[i][j] = dist;

				graph[i].push_back({ dist ,j });
				graph[j].push_back({ dist ,i });
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	long long lb = 1;
	long long ub = 1000000001;

	for (long long next = (lb + ub) / 2; ub - lb > 1; next = (lb + ub) / 2)
	{
		bool visited[1001] = { 0, };

		for (int i = 0; i < n; i++)
		{
			group[i] = i;
			rank1[i] = 0;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < graph[i].size(); j++)
			{
				if (graph[i][j].first > next)
				{
					break;
				}

				const int node = graph[i][j].second;

				if (!visited[node])
				{
					visited[node] = true;

					disj(i, node);
				}
			}
		}

		vector<int> grouplist;
		bool exist[1001] = { 0, };
		vector<pair<long long, pair<long long, long long>>> xmem[1001], ymem[1001];

		for (int i = 0; i < n; i++)
		{
			if (!exist[uf(i)])
			{
				exist[group[i]] = true;

				grouplist.push_back(group[i]);
			}
		}
	}

	return 0;
}