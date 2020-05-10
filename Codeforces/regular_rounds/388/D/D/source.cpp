#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

int main()
{
	int n, m;
	set<pair<int, int>> list;
	vector<int> bids[200001];

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int a, b;

		scanf("%d %d", &a, &b);

		bids[a].push_back(b);
	}

	for (int i = 1; i <= n; i++)
	{
		if (!bids[i].empty())
		{
			list.insert({ bids[i].back(),i });
		}
	}

	scanf("%d", &m);

	for (int i = 0; i < m; i++)
	{
		int k;

		scanf("%d", &k);

		vector<int> del;

		for (int j = 0; j < k; j++)
		{
			int input;

			scanf("%d", &input);

			if (!bids[input].empty())
			{
				del.push_back(input);

				set<pair<int, int>>::iterator ret;

				ret = list.find({ bids[input].back(),input });

				list.erase(ret);
			}
		}

		set<pair<int, int>>::iterator it, it2;

		if (list.empty())
		{
			printf("0 0\n");
		}

		else
		{
			it = list.end();

			it--;

			if (it == list.begin())
			{
				printf("%d %d\n", it->second, bids[it->second].front());
			}

			else
			{
				it2 = it;

				it2--;

				vector<int>::iterator ret;

				ret = upper_bound(bids[it->second].begin(), bids[it->second].end(), it2->first);

				printf("%d %d\n", it->second, *ret);
			}
		}

		for (int j = 0; j < del.size(); j++)
		{
			list.insert({ bids[del[j]].back(),del[j] });
		}
	}

	return 0;
}
