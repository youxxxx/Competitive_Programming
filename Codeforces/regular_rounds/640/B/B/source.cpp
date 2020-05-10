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
		int n, k;

		scanf("%d %d", &n, &k);

		if (n % 2)
		{
			if (k % 2)
			{
				if (n >= k)
				{
					printf("YES\n");

					for (int i = 0; i < k - 1; i++)
					{
						printf("1 ");
					}

					printf("%d\n", n - (k - 1));
				}

				else
				{
					printf("NO\n");
				}
			}
			 
			else
			{
				printf("NO\n");
			}
		}

		else
		{
			if (k % 2)
			{
				if (n >= k * 2)
				{
					printf("YES\n");

					for (int i = 0; i < k - 1; i++)
					{
						printf("2 ");
					}

					printf("%d\n", n - 2 * (k - 1));
				}

				else
				{
					printf("NO\n");
				}
			}

			else
			{
				if (n >= k)
				{
					printf("YES\n");

					for (int i = 0; i < k - 1; i++)
					{
						printf("1 ");
					}

					printf("%d\n", n - (k - 1));
				}

				else
				{
					printf("NO\n");
				}
			}
		}
	}

	return 0;
}