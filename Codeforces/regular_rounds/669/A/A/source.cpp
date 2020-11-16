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
		int cnt[2] = { 0, };

		scanf("%d", &n);

		for (int i = 0; i < n; i++)
		{
			int input;

			scanf("%d", &input);

			cnt[input]++;
		}

		if (!(n / 2 % 2))
		{
			printf("%d\n", n / 2);

			int num = 1;

			if (cnt[0] >= n / 2)
			{
				num = 0;
			}

			for (int i = 0; i < n / 2; i++)
			{
				printf("%d ", num);
			}

			printf("\n");
		}

		else
		{
			if (cnt[0] >= n / 2 + 1)
			{
				printf("%d\n", n / 2 + 1);

				for (int i = 0; i < n / 2 + 1; i++)
				{
					printf("0 ");
				}

				printf("\n");
			}

			else if (cnt[1] >= n / 2 + 1)
			{
				printf("%d\n", n / 2 + 1);

				for (int i = 0; i < n / 2 + 1; i++)
				{
					printf("1 ");
				}

				printf("\n");
			}

			else
			{
				printf("%d\n", n / 2);

				for (int i = 0; i < n / 2; i++)
				{
					printf("0 ");
				}

				printf("\n");
			}
		}
	}

	return 0;
}