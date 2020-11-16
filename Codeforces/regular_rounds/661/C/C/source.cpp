#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<functional>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;

		int arr[101];

		scanf("%d", &n);

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
		}

		sort(&arr[0], &arr[n]);

		int sol = 0;

		for (int i = 2; i <= 100; i++)
		{
			int ptr = n - 1;
			int cand = 0;

			for (int j = 0; j < n - 1; j++)
			{
				while (ptr > j&&arr[j] + arr[ptr] > i)
				{
					ptr--;
				}

				if (ptr <= j)
				{
					break;
				}

				if (arr[j] + arr[ptr] == i)
				{
					cand++;

					ptr--;
				}

				if (ptr <= j)
				{
					break;
				}
			}

			if (cand > sol)
			{
				sol = cand;
			}
		}

		printf("%d\n", sol);
	}

	return 0;
}