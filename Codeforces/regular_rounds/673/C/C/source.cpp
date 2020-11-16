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

		int last[300001];
		int lmax[300001] = { 0, };

		for (int i = 1; i <= n; i++)
		{
			last[i] = -1;
		}

		for (int i = 0; i < n; i++)
		{
			int input;

			scanf("%d", &input);

			if (i - last[input] > lmax[input])
			{
				lmax[input] = i - last[input];
			}

			last[input] = i;
		}

		for (int i = 1; i <= n; i++)
		{
			if (last[i] != -1 && n - last[i] > lmax[i])
			{
				lmax[i] = n - last[i];
			}
		}

		int val[300001];
		val[0] = 0;

		for (int i = 1; i <= n; i++)
		{
			val[i] = val[i - 1];

			if (lmax[i] != 0 && (val[i] == 0 || lmax[i] < val[i]))
			{
				val[i] = lmax[i];
			}
		}

		int ptr = n;

		int sol[300001];

		for (int i = 1; i <= n; i++)
		{
			while (ptr&&val[ptr] <= i && val[ptr])
			{
				ptr--;
			}

			if (ptr == n)
			{
				printf("-1 ");

				continue;
			}

			printf("%d ", ptr + 1);
		}

		printf("\n");
	}

	return 0;
}