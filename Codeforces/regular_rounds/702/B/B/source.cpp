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
		int cnt[3] = { 0, };

		scanf("%d", &n);

		for (int i = 0; i < n; i++)
		{
			int input;

			scanf("%d", &input);

			cnt[input % 3]++;
		}

		if (cnt[0] == cnt[1] && cnt[1] == cnt[2])
		{
			printf("0\n");

			continue;
		}

		int start = 0;

		for (int i = 0; i < 2; i++)
		{
			if (cnt[i] <= n / 3 && cnt[i + 1] > n / 3)
			{
				start = i + 1;

				break;
			}
		}

		int sol = 0;

		for (int i = start; i <= start + 1; i++)
		{
			sol += cnt[i % 3] - n / 3;

			cnt[(i + 1) % 3] += cnt[i % 3] - n / 3;
		}

		printf("%d\n", sol);
	}

	return 0;
}