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

		int arr[101];
		int loc[101];
		int depth[101];

		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &arr[i]);

			loc[arr[i]] = i;
		}

		depth[loc[n]] = 0;

		for (int i = n - 1; i >= 1; i--)
		{
			int left = 101;

			for (int j = loc[i] - 1; j >= 1; j--)
			{
				if (arr[j] > i)
				{
					left = arr[j];

					break;
				}
			}

			int right = 101;

			for (int j = loc[i] + 1; j <= n; j++)
			{
				if (arr[j] > i)
				{
					right = arr[j];

					break;
				}
			}

			if (left < right)
			{
				depth[loc[i]] = depth[loc[left]] + 1;
			}

			else
			{
				depth[loc[i]] = depth[loc[right]] + 1;
			}
		}

		for (int i = 1; i <= n; i++)
		{
			printf("%d ", depth[i]);
		}

		printf("\n");
	}

	return 0;
}