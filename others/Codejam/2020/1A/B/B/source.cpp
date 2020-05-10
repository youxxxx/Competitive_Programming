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
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 1; tc <= cases; tc++)
	{
		int n;

		scanf("%d", &n);

		if (n <= 30)
		{
			if (n == 1)
			{
				printf("Case #%d:\n", tc);
				printf("1 1\n");

				continue;
			}

			if (n == 2)
			{
				printf("Case #%d:\n", tc);
				printf("1 1\n");
				printf("2 1\n");

				continue;
			}

			if (n == 3)
			{
				printf("Case #%d:\n", tc);
				printf("1 1\n");
				printf("2 1\n");
				printf("3 1\n");

				continue;
			}

			int sum = 2;

			printf("Case #%d:\n", tc);
			printf("1 1\n");
			printf("2 1\n");

			int idx = 0;

			for (int i = 2; ; i++)
			{
				if (sum + i > n)
				{
					idx = i;

					break;
				}

				if (sum + i == n)
				{
					sum += i;

					printf("%d 2\n", i + 1);

					break;
				}

				if (sum + i < n)
				{
					sum += i;

					printf("%d 2\n", i + 1);
				}
			}

			if (sum < n)
			{
				for (int i = idx; i < idx + n - sum; i++)
				{
					printf("%d 1\n", i);
				}
			}
		}

		else
		{
			int temp;

			temp = n - 30;

			vector<int> bits;

			printf("Case #%d:\n", tc);

			while (temp)
			{
				bits.push_back(temp % 2);

				temp /= 2;
			}

			bool dir = 0;

			int cnt = 0;

			for (int i = 0; i < bits.size(); i++)
			{
				cnt += !bits[i];

				if (bits[i])
				{
					if (!dir)
					{
						for (int j = 1; j <= i + 1; j++)
						{
							printf("%d %d\n", i + 1, j);
						}
					}

					else
					{
						for (int j = i + 1; j >= 1; j--)
						{
							printf("%d %d\n", i + 1, j);
						}
					}

					dir = !dir;
				}

				else
				{
					if (!dir)
					{
						printf("%d 1\n", i + 1);
					}

					else
					{
					 	printf("%d %d\n", i + 1, i + 1);
					}
				}
			}

			for (int i = bits.size(); i < bits.size() + 30 - cnt; i++)
			{
				if (!dir)
				{
					printf("%d 1\n", i + 1);
				}

				else
				{
					printf("%d %d\n", i + 1, i + 1);
				}
			}
		}
	}

	return 0;
}