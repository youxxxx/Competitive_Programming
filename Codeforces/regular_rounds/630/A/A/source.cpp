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
	int cases;

	//freopen("input.txt", "r", stdin);

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int x, y, lx, ly, ux, uy;
		int dir[4];

		for (int i = 0; i < 4; i++)
		{
			scanf("%d", &dir[i]);
		}

		scanf("%d %d %d %d %d %d", &x, &y, &lx, &ly, &ux, &uy);

		int dx, dy;
		dx = dir[1] - dir[0];
		dy = dir[3] - dir[2];

		bool valid = true;

		if (x + dx > ux || x + dx < lx)
		{
			valid = false;
		}

		if (y + dy > uy || y + dy < ly)
		{
			valid = false;
		}

		if ((dir[0] || dir[1]) && x == lx&&x == ux)
		{
			valid = false;
		}

		if ((dir[2] || dir[3]) && y == ly&&y == uy)
		{
			valid = false;
		}

		if (valid)
		{
			printf("Yes\n");
		}

		else
		{
			printf("No\n");
		}
	}

	return 0;
}