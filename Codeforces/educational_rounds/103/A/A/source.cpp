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
		int n, k;

		scanf("%d %d", &n, &k);

		if (n > k)
		{
			if (!(n%k))
			{
				printf("1\n");
			}

			else
			{
				printf("2\n");
			}

			continue;
		}

		if (!(k%n))
		{
			printf("%d\n", k / n);

			continue;
		}

		printf("%d\n", k / n + 1);
	}

	return 0;
}