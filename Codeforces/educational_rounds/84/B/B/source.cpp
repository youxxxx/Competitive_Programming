#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cstring>

#define MOD 998244353

using namespace std;

int main()
{
	int cases;

	//freopen("input.txt", "r", stdin);

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;
		int x[100001];
		int y[100001];

		memset(x, -1, sizeof(x));
		memset(y, -1, sizeof(y));

		scanf("%d", &n);

		for (int i = 1; i <= n; i++)
		{
			int k;

			scanf("%d", &k);

			for (int j = 0; j < k; j++)
			{
				int input;

				scanf("%d", &input);

				if (x[i] == -1 && y[input] == -1)
				{
					x[i] = input;
					y[input] = i;
				}
			}
		}

		int xptr = 0, yptr = 0;

		for (int i = 1; i <= n; i++)
		{
			if (x[i] == -1)
			{
				xptr = i;

				break;
			}
		}

		for (int i = 1; i <= n; i++)
		{
			if (y[i] == -1)
			{
				yptr = i;

				break;
			}
		}

		if (xptr != 0)
		{
			printf("IMPROVE\n%d %d\n", xptr, yptr);
		}

		else
		{
			printf("OPTIMAL\n");
		}
	}

	return 0;
}