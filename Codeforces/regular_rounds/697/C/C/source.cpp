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

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	map<pair<int, int>, int> list;
	pair<int, int> link[200001];

	for (int tc = 0; tc < cases; tc++)
	{
		list.clear();

		int a, b, n;

		scanf("%d %d %d", &a, &b, &n);

		int cnt[2][200001];

		for (int i = 1; i <= max(a, b); i++)
		{
			cnt[0][i] = cnt[1][i] = 0;
		}

		long long sol = (long long)n*(long long)(n - 1) / 2;

		for (int i = 0; i < n; i++)
		{
			int v;

			scanf("%d", &v);

			sol -= (long long)(cnt[0][v]++);

			link[i].first = v;
		}

		for (int i = 0; i < n; i++)
		{
			int v;

			scanf("%d", &v);

			sol -= (long long)(cnt[1][v]++);

			link[i].second = v;
		}

		for (int i = 0; i < n; i++)
		{
			map<pair<int, int>, int>::iterator ret = list.find(link[i]);

			if (ret == list.end())
			{
				list[link[i]] = 1;
			}

			else
			{
				sol += (long long)(ret->second++);
			}
		}

		printf("%lld\n", sol);
	}

	return 0;
}