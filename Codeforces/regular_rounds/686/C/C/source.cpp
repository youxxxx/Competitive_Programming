#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<functional>

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

		int cnt[200001];
		int prev = -1;
		bool hom = true;
		bool exist[200001];
		int prevval = -1;

		for (int i = 1; i <= n; i++)
		{
			cnt[i] = 0;

			exist[i] = false;
		}

		for (int i = 0; i < n; i++)
		{
			int input;

			scanf("%d", &input);

			if (i != 0 && prevval!=input)
			{
				cnt[input]++;
			}

			if (i == n - 1)
			{
				cnt[input]--;
			}

			exist[input] = true;

			if (hom)
			{
				if (prev != -1 && prev != input)
				{
					hom = false;
				}

				prev = input;
			}

			prevval = input;
		}

		if (n == 1 || hom)
		{
			printf("0\n");

			continue;
		}

		int sol = n + 1;

		for (int i = 1; i <= n; i++)
		{
			if (exist[i])
			{
				sol = min(sol, cnt[i] + 1);
			}
		}

		printf("%d\n", sol);
	}

	return 0;
}