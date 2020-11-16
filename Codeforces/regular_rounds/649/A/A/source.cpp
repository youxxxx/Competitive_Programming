#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
#include<cstring>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n, x;
		int arr[100001];

		scanf("%d %d", &n, &x);

		int sum = 0;

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);

			sum += arr[i];
		}

		if (sum%x)
		{
			printf("%d\n", n);

			continue;
		}

		int lmax = -1;

		for (int i = 0; i < n - 1; i++)
		{
			if (arr[i] % x)
			{
				lmax = n - i - 1;

				break;
			}
		}

		for (int i = n - 1; i >= 1; i--)
		{
			if (arr[i] % x)
			{
				if (i > lmax)
				{
					lmax = i;
				}

				break;
			}
		}

		printf("%d\n", lmax);
	}

	return 0;
}