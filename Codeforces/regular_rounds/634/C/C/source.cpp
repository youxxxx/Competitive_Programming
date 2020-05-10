#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
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
		int arr[200001];
		int cnt[200001];
		int tot = 0;

		scanf("%d", &n);

		for (int i = 1; i <= n; i++)
		{
			cnt[i] = 0;
		}

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);

			if (!(cnt[arr[i]]++))
			{
				tot++;
			}
		}

		int lmax = 0;

		for (int i = 1; i <= n; i++)
		{
			if (cnt[i])
			{
				int cand;

				cand = cnt[i] - 1 < tot ? cnt[i] - 1 : tot;

				if (cand > lmax)
				{
					lmax = cand;
				}

				cand = cnt[i] < tot - 1 ? cnt[i] : tot - 1;

				if (cand > lmax)
				{
					lmax = cand;
				}
			}
		}

		printf("%d\n", lmax);
	}

	return 0;
}