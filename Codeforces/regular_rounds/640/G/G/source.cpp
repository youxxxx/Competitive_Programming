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

		if (n < 4)
		{
			printf("-1\n");

			continue;
		}

		if (n == 4)
		{
			printf("3 1 4 2\n");

			continue;
		}

		if (n % 2)
		{
			for (int i = 1; i <= n; i += 2)
			{
				printf("%d ", i);
			}

			printf("%d %d ", n - 3, n - 1);

			for (int i = n - 5; i >= 2; i -= 2)
			{
				printf("%d ", i);
			}
		}

		else
		{
			for (int i = 1; i <= n; i += 2)
			{
				printf("%d ", i);
			}

			printf("%d %d %d ", n - 4, n, n - 2);

			for (int i = n - 6; i >= 2; i -= 2)
			{
				printf("%d ", i);
			}
		}

		printf("\n");
	}

	return 0;
}