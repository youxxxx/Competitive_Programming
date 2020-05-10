#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int t, tc;
	int n, m, k;
	int x[3], y[3];
	int i;

	freopen("on_the_run.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &tc);

	for (t = 0; t < tc; t++)
	{
		scanf("%d %d %d", &n, &m, &k);

		for (i = 0; i <= k; i++)
		{
			scanf("%d %d", &x[i], &y[i]);
		}

		if (k == 1)
		{
			if ((n >= 2 && m >= 2) || (abs(x[0]-x[1])+abs(y[0]-y[1])) % 2)
			{
				printf("Case #%d: N\n", t + 1);
			}

			else
			{
				printf("Case #%d: Y\n", t + 1);
			}
		}

		else
		{
			if ((abs(x[0] - x[1]) + abs(y[0] - y[1])) % 2 || (abs(x[0] - x[2]) + abs(y[0] - y[2])) % 2)
			{
				printf("Case #%d: N\n", t + 1);
			}

			else
			{
				printf("Case #%d: Y\n", t + 1);
			}
		}
	}

	return 0;
}