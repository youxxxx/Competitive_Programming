#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int n;
vector<int> graph[200001];
vector<int> leaf, ldepth;
pair<int, int> range[200001];
int ansc[200001];
int xdepth;

int search(int cnt, int cur, int parent, int ycoord)
{
	int i;
	int next;
	bool found = false;
	int rvalue = 0;

	ansc[cur] = parent;
	range[cur].first = cnt;

	for (i = 0; i < graph[cur].size(); i++)
	{
		next = graph[cur][i];

		if (next == parent)
		{
			continue;
		}

		rvalue += search(cnt + rvalue, next, cur, ycoord + 1);

		found=true;
	}

	if (!found)
	{
		leaf.push_back(cur);
		ldepth.push_back(ycoord);
		rvalue = 1;
	}

	range[cur].second = leaf.size();

	return rvalue;
}

int main()
{
	int i;
	int u, v;
	int target, next, depth, lca, temp;
	int ub;

	scanf("%d", &n);

	for (i = 0; i < n - 1; i++)
	{
		scanf("%d %d", &u, &v);

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	printf("d 1\n");
	fflush(stdout);

	scanf("%d", &xdepth);

	if (xdepth == 0)
	{
		printf("! 1\n");
		fflush(stdout);

		return 0;
	}

	search(0, 1, 0, 0);

	printf("s 1\n");
	fflush(stdout);

	scanf("%d", &target);

	if (xdepth == 1)
	{
		printf("! %d\n", target);
		fflush(stdout);

		return 0;
	}

	while (1)
	{
		next = (range[target].first + range[target].second) / 2;

		if (next == range[target].first)
		{
			temp = leaf[next];

			for (i = 0; i < ldepth[next] - xdepth; i++)
			{
				temp = ansc[temp];
			}

			printf("! %d\n", temp);
			fflush(stdout);

			return 0;
		}

		printf("d %d\n", leaf[next]);
		fflush(stdout);

		scanf("%d", &depth);
		if (depth == -1)
		{
			return 0;
		}

		if (depth == 0)
		{
			printf("! %d\n", leaf[next]);
			fflush(stdout);

			return 0;
		}

		if (depth == 1)
		{
			printf("! %d\n", ansc[leaf[next]]);
			fflush(stdout);

			return 0;
		}

		temp = leaf[next];

		ub = (ldepth[next] - ((ldepth[next] + xdepth) - depth) / 2);

		if (ub == 0)
		{
			printf("! %d\n", temp);
			fflush(stdout);

			return 0;
		}

		for (i = 0; i < ub; i++)
		{
			temp = ansc[temp];
		}

		lca = temp;

		printf("s %d\n", lca);
		fflush(stdout);

		scanf("%d", &target);
		if (target == -1)
		{
			return 0;
		}
	}

	return 0;
}