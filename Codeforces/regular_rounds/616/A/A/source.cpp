#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n, m, k;
		vector<int> arr(3500);

		scanf("%d %d %d", &n, &m, &k);

		if (k > m - 1)
		{
			k = m - 1;
		}

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
		}

		vector<int> lmax;

		for (int i = 0; i < m; i++)
		{
			int l;

			l = arr[i] > arr[i + n - m] ? arr[i] : arr[i + n - m];

			lmax.push_back(l);
		}

		int sol = 0;

		for (int i = 0; i <= k; i++)
		{
			int lmin = 1000000001;

			for (int j = 0; j < lmax.size() - k; j++)
			{
				if (lmax [i + j] < lmin)
				{
					lmin = lmax[i + j];
				}
			}

			if (lmin > sol)
			{
				sol = lmin;
			}
		}

		printf("%d\n", sol);
	}

	return 0;
}