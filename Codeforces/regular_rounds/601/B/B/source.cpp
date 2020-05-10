#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n, m;
		vector<pair<int, int>> cost;

		scanf("%d %d", &n, &m);

		int sol = 0;

		for (int i = 1; i <= n; i++)
		{
			int input;

			scanf("%d", &input);

			cost.push_back(make_pair(input, i));

			sol += input;
		}

		sol *= 2;

		if (n == 2 || n > m)
		{
			printf("-1\n");

			continue;
		}

		sort(cost.begin(), cost.end());

		sol += (cost[0].first + cost[1].first) * (m - n);

		printf("%d\n", sol);

		for (int i = 0; i < n; i++)
		{
			printf("%d %d\n", i + 1, (i + 1) % n + 1);
		}

		for (int i = 0; i < m - n; i++)
		{
			printf("%d %d\n", cost[0].second, cost[1].second);
		}
	}

	return 0;
}