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

		int sol[3] = { 0, };

		sol[2] = (n + 6) / 7;

		int diff = sol[2] * 7 - n;

		if (n % 2 != sol[2] % 2)
		{
			sol[2]++;

			diff += 7;
		}

		if (!diff)
		{
			printf("0 0 %d\n", sol[2]);

			continue;
		}

		if (diff % 2 || diff > sol[2] * 4)
		{
			printf("-1\n");

			continue;
		}

		sol[0] = diff / 4;
		sol[2] -= diff / 4;
		diff %= 4;
		sol[1] = diff / 2;
		sol[2] -= diff / 2;

		printf("%d %d %d\n", sol[0], sol[1], sol[2]);
	}

	return 0;
}