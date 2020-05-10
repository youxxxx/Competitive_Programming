#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int lmax = -1, lmin = 1000000001;
	int maxidx, minidx;
	int n, k;
	int arr[501];
	int cnt[501] = { 0, };


	scanf("%d %d", &n, &k);

	for (int i = 0; i < k + 1; i++)
	{
		printf("?");

		for (int j = 0; j < k; j++)
		{
			printf(" %d", (i + j) % (k + 1) + 1);
		}

		printf("\n");

		fflush(stdout);

		int idx, val;

		scanf("%d %d", &idx, &val);

		arr[idx] = val;
		cnt[idx]++;

		if (val > lmax)
		{
			lmax = val;
			maxidx = idx;
		}

		if (val < lmin)
		{
			lmin = val;
			minidx = idx;
		}
	}

	printf("! %d\n", cnt[maxidx]);
	fflush(stdout);

	return 0;
}