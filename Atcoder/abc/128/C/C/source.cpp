#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<queue>

using namespace std;

bool connected[11][11] = { 0, };
int n, m, k;
int odd[11];

int rec(int cur, int sheet[11])
{
	int i, j;
	int bulb[11];
	int res = 1;
	int sol;

	if (cur == n + 1)
	{
		for (i = 1; i <= m; i++)
		{
			bulb[i] = !odd[i];
		}

		for (i = 1; i <= n; i++)
		{
			if (sheet[i])
			{
				for (j = 1; j <= m; j++)
				{
					if (connected[i][j])
					{
						bulb[j] = !bulb[j];
					}
				}
			}
		}

		for (i = 1; i <= m; i++)
		{
			res = res&&bulb[i];
		}

		return res;
	}

	sheet[cur] = 0;
	sol = rec(cur + 1, sheet);
	sheet[cur] = 1;
	return sol + rec(cur + 1, sheet);
}

int main()
{
	int i, j;
	int input;
	int sheet[11];

	scanf("%d %d", &n, &m);

	for (i = 0; i < m; i++)
	{
		scanf("%d", &k);

		for (j = 0; j < k; j++)
		{
			scanf("%d", &input);

			connected[input][i + 1] = true;
		}
	}

	for (i = 0; i < m; i++)
	{
		scanf("%d", &odd[i + 1]);
	}

	printf("%d\n", rec(1, sheet));

	return 0;
}