#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int x, y;

		scanf("%d %d", &x, &y);

		if (x == 1)
		{
			if (y == 1)
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		}

		else if (x <= 3)
		{
			if (y <= 3)
			{
				printf("YES\n");
			}

			else
			{
				printf("NO\n");
			}
		}

		else
		{
			printf("YES\n");
		}
	}

	return 0;
}