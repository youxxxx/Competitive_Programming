#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
#include<set>

using namespace std;

int main()
{
	int tc, cases;
	int n;
	int lmin;
	int i, j;
	int input;
	int arr[100][100];

	scanf("%d", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		scanf("%d", &n);

		if (!(n % 2))
		{
			printf("NO\n");
		}

		else
		{
			printf("YES\n");

			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					arr[i][j] = 0;
				}
			}

			for (i = 0; i < n; i++)
			{
				for (j = i + 1; j <= i + (n / 2); j++)
				{
					arr[i][j%n] = 1;
				}
			}

			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					printf("%d", arr[i][j]);
				}

				printf("\n");
			}
		}
	}

	return 0;
}