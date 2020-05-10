#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n, m;
	long long debt[300001] = { 0, };

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		int u, v;
		long long val;

		scanf("%d %d %lld", &u, &v, &val);

		debt[u] += val;
		debt[v] -= val;
	}

	vector<pair<int,long long>> give, take;

	for (int i = 1; i <= n; i++)
	{
		if (debt[i] > 0)
		{
			give.push_back({ i,debt[i] });
		}

		else if (debt[i] < 0)
		{
			take.push_back({ i,-debt[i] });
		}
	}

	int i = 0, j = 0;

	vector<pair<pair<int, int>, long long>> sol;

	while (i < give.size() || j < take.size())
	{
		if (give[i].second == take[j].second)
		{
			sol.push_back({ {give[i].first, take[j].first}, give[i].second });

			i++;
			j++;
		}

		else if (give[i].second < take[j].second)
		{
			sol.push_back({ { give[i].first, take[j].first }, give[i].second });

			take[j].second -= give[i].second;

			i++;
		}

		else
		{
			sol.push_back({ { give[i].first, take[j].first }, take[j].second });

			give[i].second -= take[j].second;

			j++;
		}
	}

	printf("%d\n", sol.size());

	for (int i = 0; i < sol.size(); i++)
	{
		printf("%d %d %lld\n", sol[i].first.first, sol[i].first.second, sol[i].second);
	}

	return 0;
}