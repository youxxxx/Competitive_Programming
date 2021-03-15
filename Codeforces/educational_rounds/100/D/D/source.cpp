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

	for (int tc = 0; tc < cases; tc++)
	{
		int n;

		scanf("%d", &n);

		int bit[400001];

		for (int i = 1; i <= 2 * n; i++)
		{
			bit[i] = 1;
		}

		int list[2][200001];

		for (int i = 1; i <= n; i++)
		{
			int input;

			scanf("%d", &input);

			bit[input] = 0;
		}

		int cnt[2] = { 1,1 };

		for (int i = 1; i <= 2 * n; i++)
		{
			list[bit[i]][cnt[bit[i]]++] = i;
		}

		int ptr = 1;

		int ub = 0;

		for (int i = 1; i <= n; i++)
		{
			while (ptr != n + 1 && list[1][ptr]<list[0][i])
			{
				ptr++;
			}

			if (ptr == n + 1)
			{
				break;
			}

			ub++;
			ptr++;
		}

		ptr = 1;

		int lb = 0;

		for (int i = 1; i <= n; i++)
		{
			while (ptr != n + 1 && list[0][ptr]<list[1][i])
			{
				ptr++;
			}

			if (ptr == n + 1)
			{
				break;
			}

			lb++;
			ptr++;
		}

		lb = n - lb;

		printf("%d\n", ub - lb + 1);
	}

	return 0;
}