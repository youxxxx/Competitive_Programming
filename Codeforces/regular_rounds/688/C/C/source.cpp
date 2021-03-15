#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<functional>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	vector<string> arr;
	vector<pair<int, int>> coord[10];

	for (int tc = 0; tc < cases; tc++)
	{
		int n;

		scanf("%d", &n);

		int cnt[10] = { 0, };
		int xmin[10];
		int xmax[10] = { 0, };
		int ymin[10];
		int ymax[10] = { 0, };

		arr.clear();

		for (int i = 0; i < 10; i++)
		{
			xmin[i] = ymin[i] = 2001;

			coord[i].clear();
		}

		for (int i = 0; i < n; i++)
		{
			char input[2001];

			scanf("%s", input);

			const string str = input;

			arr.push_back(str);

			for (int j = 0; j < n; j++)
			{
				const int d = str[j] - '0';

				cnt[d]++;

				xmin[d] = min(xmin[d], i);
				xmax[d] = max(xmax[d], i);
				ymin[d] = min(ymin[d], j);
				ymax[d] = max(ymax[d], j);

				coord[d].push_back({ i,j });
			}
		}

		int sol[10] = { 0, };

		for (int i = 0; i < 10; i++)
		{
			if (cnt[i] < 2)
			{
				continue;
			}

			for (int j = 0; j < coord[i].size(); j++)
			{
				const int x = coord[i][j].first;
				const int y = coord[i][j].second;

				sol[i] = max(sol[i], max(x, n - 1 - x)*abs(y - ymin[i]));
				sol[i] = max(sol[i], max(x, n - 1 - x)*abs(y - ymax[i]));
				sol[i] = max(sol[i], max(y, n - 1 - y)*abs(x - xmin[i]));
				sol[i] = max(sol[i], max(y, n - 1 - y)*abs(x - xmax[i]));
			}
		}

		for (int i = 0; i < 10; i++)
		{
			printf("%d ", sol[i]);
		}

		printf("\n");
	}

	return 0;
}