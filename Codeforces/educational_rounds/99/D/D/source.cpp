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
		int n, x;

		scanf("%d %d", &n, &x);

		int arr[501];
		
		int prev = -1;

		bool inv = false;

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);

			if (arr[i] < prev)
			{
				inv = true;
			}

			prev = arr[i];
		}

		if (!inv)
		{
			printf("0\n");

			continue;
		}

		bool start = true;
		int cur = x;
		prev = 0;
		int sol = 0;
		int add = 0;

		for (int i = 0; i < n; i++)
		{
			if (arr[i] > cur)
			{
				prev = cur;

				cur = arr[i];

				start = false;

				add++;
			}

			else if (arr[i] < cur)
			{
				if (prev > arr[i])
				{
					sol = -1;

					break;
				}

				sol += add;
				add = 0;

				prev = arr[i];
			}
		}

		printf("%d\n", sol);
	}

	return 0;
}