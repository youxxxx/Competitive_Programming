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

	scanf("%d", &cases);

	for (int tc = 1; tc <= cases; tc++)
	{
		int n;

		scanf("%d", &n);

		int arr[101][101];

		int k = 0, r = 0, c = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &arr[i][j]);
			}

			k += arr[i][i];
		}

		for (int i = 0; i < n; i++)
		{
			bool cnt[101] = { 0, };
			int valid = 0;

			for (int j = 0; j < n; j++)
			{
				if (cnt[arr[i][j]]++)
				{
					valid = 1;
				}
			}

			r += valid;
		}

		for (int i = 0; i < n; i++)
		{
			bool cnt[101] = { 0, };
			int valid = 0;

			for (int j = 0; j < n; j++)
			{
				if (cnt[arr[j][i]]++)
				{
					valid = 1;
				}
			}

			c += valid;
		}

		printf("Case #%d: %d %d %d\n", tc, k, r, c);
	}

	return 0;
}