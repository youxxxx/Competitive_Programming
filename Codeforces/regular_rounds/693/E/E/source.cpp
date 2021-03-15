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

	pair<pair<int, int>, int> coord[200001];
	pair<pair<int, int>, int> list[400001];

	for (int tc = 0; tc < cases; tc++)
	{
		int n;

		scanf("%d", &n);

		for (int i = 1; i <= n; i++)
		{
			int x, y;

			scanf("%d %d", &x, &y);

			coord[i] = { { x,y },i };
			list[i * 2 - 1] = { {x,y},i };
			list[i * 2] = { {y,x},i };
		}

		sort(&coord[1], &coord[n + 1]);
		sort(&list[1], &list[n * 2 + 1]);

		int ptr = 1;
		int lmin = 1000000001;
		int lidx = -1;

		int sol[200001];

		for (int i = 1; i <= n; i++)
		{
			while (ptr != n * 2 + 1 && list[ptr].first.first < coord[i].first.first)
			{
				if (list[ptr].first.second < lmin)
				{
					lmin = list[ptr].first.second;

					lidx = list[ptr].second;
				}

				ptr++;
			}

			if (lmin >= coord[i].first.second)
			{
				sol[coord[i].second] = -1;
			}

			else
			{
				sol[coord[i].second] = lidx;
			}
		}

		for (int i = 1; i <= n; i++)
		{
			printf("%d ", sol[i]);
		}

		printf("\n");
	}

	return 0;
}