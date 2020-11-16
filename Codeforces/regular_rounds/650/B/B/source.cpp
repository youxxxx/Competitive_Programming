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
		int n;

		scanf("%d", &n);

		int cnt[2] = { 0, };

		for (int i = 0; i < n; i++)
		{
			int input;

			scanf("%d", &input);

			if (i % 2 != input % 2)
			{
				cnt[i % 2]++;
			}
		}

		if (cnt[0] != cnt[1])
		{
			printf("-1\n");
		}

		else
		{
			printf("%d\n", cnt[0]);
		}
	}

	return 0;
}