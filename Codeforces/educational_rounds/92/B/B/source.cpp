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
		int arr[100001];
		int n;
		int k;
		int z;

		scanf("%d %d %d", &n, &k, &z);

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
		}

		int cur = arr[0];
		int lmax = 0;
		int sol = 0;

		for (int i = 1; i < n && i <= k; i++)
		{
			cur += arr[i];

			if (arr[i] + arr[i - 1] > lmax)
			{
				lmax = arr[i] + arr[i - 1];
			}

			const int mlt = z < (k - i) / 2 ? z : (k - i) / 2;

			int cand = cur + lmax*mlt;

			if (mlt < z && (k - i) - mlt * 2)
			{
				cand += arr[i - 1];
			}

			if (cand > sol)
			{
				sol = cand;
			}
		}

		printf("%d\n", sol);
	}

	return 0;
}