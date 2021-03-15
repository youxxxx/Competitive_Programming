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

#define MAX 1000000000

int main()
{
	//freopen("input.txt", "r", stdin);

	int n[4];

	for (int i = 0; i < 4; i++)
	{
		scanf("%d", &n[i]);
	}

	pair<int, int> arr[4][150001];
	int inv[4][150001];

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < n[i]; j++)
		{
			int input;

			scanf("%d", &input);

			arr[i][j] = { input,j };
		}
	}

	for (int i = 0; i < 4; i++)
	{
		if (i)
		{
			int l;

			scanf("%d", &l);

			vector<int> list[150001];

			for (int j = 0; j < l; j++)
			{
				int u, v;

				scanf("%d %d", &u, &v);

				list[v - 1].push_back(inv[i - 1][u - 1]);
			}

			for (int j = 0; j < n[i]; j++)
			{
				int prev = -1;

				int cur = MAX;

				sort(list[j].begin(), list[j].end());

				for (int k = 0; k < (int)list[j].size(); k++)
				{
					if (list[j][k] > prev + 1)
					{
						cur = min(cur, min(MAX, arr[i - 1][prev + 1].first));

						break;
					}

					prev = list[j][k];
				}

				if (prev != n[i - 1] - 1)
				{
					cur = min(cur, min(MAX, arr[i - 1][prev + 1].first));
				}

				arr[i][j].first = min(MAX, arr[i][j].first + cur);
			}
		}

		sort(&arr[i][0], &arr[i][n[i]]);

		for (int j = 0; j < n[i]; j++)
		{
			inv[i][arr[i][j].second] = j;
		}
	}

	int sol = arr[3][0].first;

	if (sol == MAX)
	{
		printf("-1\n");
	}

	else
	{
		printf("%d\n", sol);
	}

	return 0;
}