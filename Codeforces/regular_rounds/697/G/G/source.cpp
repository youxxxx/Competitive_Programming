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

	vector<int> div[200001];

	for (int i = 1; i <= 200000; i++)
	{
		const int ub = (int)sqrt((double)i);

		for (int j = 1; j <= ub; j++)
		{
			if (!(i%j))
			{
				div[i].push_back(j);
				div[i].push_back(i / j);
			}
		}

		if (ub*ub == i)
		{
			div[i].pop_back();
		}
	}

	int cases;

	scanf("%d", &cases);

	map<int, int> list;

	for (int tc = 0; tc < cases; tc++)
	{
		list.clear();

		int n;

		scanf("%d", &n);

		int arr[200001];

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
		}

		sort(&arr[0], &arr[n]);

		int lmax = 1;

		for (int i = 0; i < n; i++)
		{
			int curmax = 1;

			for (int j = 0; j < (int)div[arr[i]].size(); j++)
			{
				map<int, int>::iterator ret = list.find(div[arr[i]][j]);

				if (ret != list.end())
				{
					curmax = max(ret->second + 1, curmax);
				}
			}

			list[arr[i]] = curmax;

			lmax = max(curmax, lmax);
		}

		printf("%d\n", n - lmax);
	}

	return 0;
}