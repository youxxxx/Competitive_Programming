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

		int arr[3001];

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
		}

		int lmin = n - 1;

		for (int i = 0; i < n; i++)
		{
			int base = 0;

			for (int j = 0; j <= i; j++)
			{
				base += arr[j];
			}

			int cur = 0;

			bool valid = true;

			int cnt = i;

			for (int j = i + 1; j < n; j++)
			{
				if (cur)
				{
					cnt++;
				}

				cur += arr[j];

				if (cur > base)
				{
					valid = false;

					break;
				}

				cur %= base;
			}

			if (!valid || cur)
			{
				continue;
			}

			lmin = min(lmin, cnt);
		}

		printf("%d\n", lmin);
	}

	return 0;
}