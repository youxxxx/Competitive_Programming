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

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;

		scanf("%d", &n);

		int arr[200001];

		int sol[200001];

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
		}

		bool same = true;

		for (int i = 0; i < n - 1; i++)
		{
			if (arr[i] != arr[i + 1])
			{
				same = false;

				break;
			}
		}

		if (same)
		{
			printf("1\n");

			for (int i = 0; i < n; i++)
			{
				printf("1 ");
			}

			printf("\n");

			continue;
		}

		if (!(n % 2))
		{
			printf("2\n");

			for (int i = 0; i < n; i++)
			{
				printf("%d ",i%2+1);
			}

			printf("\n");

			continue;
		}

		int k = 1;
		int bit = 0;

		for (int i = 0; i < n - 1; i++)
		{
			sol[i] = bit + 1;

			if (arr[i + 1] != arr[i])
			{
				k = 2;

				bit = !bit;
			}
		}

		sol[n - 1] = bit + 1;

		if (n > 2 && arr[0] != arr[n - 1] && sol[0] == sol[n - 1])
		{
			bool found = false;

			for (int i = n - 1; i > 0; i--)
			{
				sol[i] = 3 - sol[i];

				if (arr[i - 1] == arr[i])
				{
					found = true;

					break;
				}
			}

			if (!found)
			{
				k = 3;

				sol[0] = 2;

				sol[n - 1] = 3;
			}
		}

		printf("%d\n", k);

		for (int i = 0; i < n; i++)
		{
			printf("%d ", sol[i]);
		}

		printf("\n");
	}

	return 0;
}