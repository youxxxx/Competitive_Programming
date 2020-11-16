#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
#include<cstring>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int cnt = 0;
		int n, x;

		scanf("%d %d", &n, &x);

		if (n == 1)
		{
			printf("Ayush\n");
			
			continue;
		}

		for (int i = 0; i < n - 1; i++)
		{
			int u, v;

			scanf("%d %d", &u, &v);

			if (u == x || v == x)
			{
				cnt++;
			}
		}

		if (cnt == 1)
		{
			printf("Ayush\n");
		}

		else
		{
			if (n % 2)
			{
				printf("Ashish\n");
			}

			else
			{
				printf("Ayush\n");
			}
		}
	}

	return 0;
}