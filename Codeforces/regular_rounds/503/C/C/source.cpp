#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n, m;
	int p, c;
	int* votes;
	int i, j;

	vector<int>* cost;

	scanf("%d %d", &n, &m);

	votes = new int[m + 1];
	cost = new vector<int>[m + 1];

	for (i = 1; i <= m; i++)
	{
		votes[i] = 0;
	}

	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &p, &c);

		votes[p]++;

		if (p > 1)
		{
			cost[p].push_back(c);
		}
	}

	for (i = 2; i <= m; i++)
	{
		sort(cost[p].begin(), cost[p].end());
	}


}