#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int safe(int x, int y)
{
	return x >= 0 && x <= 1000000000 && y >= 0 && y <= 1000000000;
}

int main()
{
	int n;
	int sx, sy;
	vector<pair<int, int>> arr;
	int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };

	scanf("%d %d %d", &n, &sx, &sy);

	for (int i = 0; i < n; i++)
	{
		int x, y;

		scanf("%d %d", &x, &y);

		arr.push_back({ x,y });
	}

	int lmax = 0;
	int tx, ty;

	for (int i = 0; i < 4; i++)
	{
		int x, y;

		x = sx + dx[i];
		y = sy + dy[i];

		if (!safe(x, y))
		{
			continue;
		}

		int cnt = 0;

		for (int j = 0; j < n; j++)
		{
			if ((arr[j].first >= x&&x >= sx) || (arr[j].first <= x&&x <= sx))
			{
				if ((arr[j].second >= y&&y >= sy) || (arr[j].second <= y&&y <= sy))
				{
					cnt++;
				}
			}
		}

		if (cnt >= lmax)
		{
			lmax = cnt;

			tx = x;
			ty = y;
		}
	}

	printf("%d\n%d %d\n", lmax, tx, ty);

	return 0;
}