#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>

using namespace std;

int main()
{
	int cases;

	//freopen("input.txt", "r", stdin);

	scanf("%d", &cases);

	vector<int> arr(100001);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;

		bool allemp = true;
		
		scanf("%d", &n);

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);

			if (arr[i] != -1)
			{
				allemp = false;
			}
		}

		if (allemp)
		{
			printf("0 1\n");

			continue;
		}

		int lmin = -1, lmax = -1;
		int maxdiff = 0;

		for (int i = 0; i < n; i++)
		{
			if (arr[i] != -1)
			{
				int idx;

				idx = i - 1;

				if (idx >= 0 && idx < n)
				{
					if (arr[idx] == -1)
					{
						if (lmin == -1 || arr[i] < lmin)
						{
							lmin = arr[i];
						}

						if (lmax == -1 || arr[i] > lmax)
						{
							lmax = arr[i];
						}
					}

					else
					{
						if (abs(arr[i] - arr[idx]) > maxdiff)
						{
							maxdiff = abs(arr[i] - arr[idx]);
						}
					}
				}

				idx = i + 1;

				if (idx >= 0 && idx < n)
				{
					if (arr[idx] == -1)
					{
						if (lmin == -1 || arr[i] < lmin)
						{
							lmin = arr[i];
						}

						if (lmax == -1 || arr[i] > lmax)
						{
							lmax = arr[i];
						}
					}

					else
					{
						if (abs(arr[i] - arr[idx]) > maxdiff)
						{
							maxdiff = abs(arr[i] - arr[idx]);
						}
					}
				}
			}
		}

		int cand;

		cand = (lmin + lmax) / 2;

		if (abs(cand - lmax) > maxdiff)
		{
			maxdiff = abs(cand - lmax);
		}

		printf("%d %d\n", maxdiff, cand);
	}

	return 0;
}