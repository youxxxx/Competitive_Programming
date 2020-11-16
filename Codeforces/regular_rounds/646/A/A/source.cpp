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
		int n, m;

		scanf("%d %d", &n, &m);

		int cnt[2] = { 0, };

		for (int i = 0; i < n; i++)
		{
			int input;

			scanf("%d", &input);

			cnt[input % 2]++;
		}

		if (!cnt[1])
		{
			printf("No\n");

			continue;
		}

		bool found = false;

		for (int i = 1; i <= cnt[1] && i <= m; i += 2)
		{
			if (cnt[0] >= m - i)
			{
				found = true;

				break;
			}
		}

		if (found)
		{
			printf("Yes\n");
		}

		else
		{
			printf("No\n");
		}
	}

	return 0;
}