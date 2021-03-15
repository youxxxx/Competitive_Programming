#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<functional>
#include<cstring>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;

		scanf("%d", &n);

		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if ((j - i) < (i + n - j))
				{
					printf("1 ");
				}

				else if ((j - i) > (i + n - j))
				{
					printf("-1 ");
				}

				else
				{
					printf("0 ");
				}
			}
		}

		printf("\n");
	}

	return 0;
}