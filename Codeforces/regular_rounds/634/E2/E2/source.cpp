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

#define MAXN 200000
#define MAXA 200

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		vector<int> arr;
		vector<int> acc[MAXA + 1];

		int n;

		scanf("%d", &n);

		arr.push_back(0);

		for (int j = 1; j <= MAXA; j++)
		{
			acc[j].push_back(0);
		}

		for (int i = 1; i <= n; i++)
		{
			int input;

			scanf("%d", &input);

			arr.push_back(input);

			for (int j = 1; j <= MAXA; j++)
			{
				acc[j].push_back(acc[j].back() + (input == j));
			}
		}

		int lmax = 0;

		for (int i = 1; i <= MAXA; i++)
		{
			int ptr1, ptr2;

			ptr1 = 1;

			while (ptr1 != n + 1 && arr[ptr1] != i)
			{
				ptr1++;
			}

			ptr2 = n;

			while (ptr2 != 0 && arr[ptr2] != i)
			{
				ptr2--;
			}

			if (ptr1 > ptr2)
			{
				continue;
			}

			if (ptr1 == ptr2)
			{
				if (lmax < 1)
				{
					lmax = 1;
				}

				continue;
			}

			int outline = 1;

			while (ptr1 < ptr2)
			{
				for (int j = 1; j <= MAXA; j++)
				{
					if (i == j)
					{
						continue;
					}

					if (acc[j][ptr2 - 1] - acc[j][ptr1] + outline * 2 > lmax)
					{
						lmax = acc[j][ptr2 - 1] - acc[j][ptr1] + outline * 2;
					}
				}

				ptr1++;
				ptr2--;

				while (ptr1 != n + 1 && arr[ptr1] != i)
				{
					ptr1++;
				}

				while (ptr2 != 0 && arr[ptr2] != i)
				{
					ptr2--;
				}

				if (ptr1 == ptr2)
				{
					if (outline * 2 + 1 > lmax)
					{
						lmax = outline * 2 + 1;
					}
				}

				outline++;
			}
		}

		printf("%d\n", lmax);
	}

	return 0;
}