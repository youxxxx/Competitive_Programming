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
		long long k;
		int bit = 0;

		scanf("%d %lld", &n, &k);

		for (int i = 0; i < n; i++)
		{
			long long input;

			scanf("%lld", &input);

			if (!(k % 2) && input == k / 2)
			{
				printf("%d ", bit);

				bit = !bit;

				continue;
			}

			if (input <= k / 2)
			{
				printf("0 ");
			}

			else
			{
				printf("1 ");
			}
		}

		printf("\n");
	}

	return 0;
}