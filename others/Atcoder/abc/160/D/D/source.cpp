#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<cstring>
#include<functional>

using namespace std;

int main()
{
	int n, x, y;
	int dist[2001][2001];

	memset(dist, -1, sizeof(dist));

	scanf("%d %d %d", &n, &x, &y);

	int cnt[2001] = { 0, };

	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			dist[i][j] = dist[j][i] = j - i;

			int ix, iy, jx, jy;

			ix = abs(i - x);
			iy = abs(i - y);
			jx = abs(j - x);
			jy = abs(j - y);

			int id, jd;

			id = ix < iy ? ix : iy;
			jd = jx < jy ? jx : jy;

			if (id + jd + 1 < dist[i][j])
			{
				dist[i][j] = id + jd + 1;
			}

			cnt[dist[i][j]]++;
		}
	}

	for (int i = 1; i < n; i++)
	{
		printf("%d\n", cnt[i]);
	}

	return 0;
}