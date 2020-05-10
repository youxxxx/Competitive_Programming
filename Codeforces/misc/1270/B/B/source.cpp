#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;
		vector<int> arr;

		scanf("%d", &n);

		for (int i = 0; i < n; i++)
		{
			int input;

			scanf("%d", &input);

			arr.push_back(input);
		}
		
		int lmin, lmax = 0;
		int minidx, maxidx;

		minidx = 0;
		lmin = arr[0];

		bool found = false;

		for (int i = 1; i < n; i++)
		{
			if (arr[i] > lmin && arr[i] - lmin > i - minidx)
			{
				found = true;

				maxidx = i;

				break;
			}

			if (i - minidx > arr[i] - lmin)
			{
				minidx = i;
				lmin = arr[i];
			}
		}

		if (found)
		{
			printf("YES\n%d %d\n", minidx + 1, maxidx + 1);

			continue;
		}

		maxidx = 0;
		lmax = arr[0];

		for (int i = 1; i < n; i++)
		{
			if (lmax > arr[i] && lmax - arr[i] > i - maxidx)
			{
				found = true;

				minidx = i;

				break;
			}

			if (i - maxidx > lmax - arr[i])
			{
				maxidx = i;
				lmax = arr[i];;
			}
		}

		if (found)
		{
			printf("YES\n%d %d\n", maxidx + 1, minidx + 1);

			continue;
		}

		printf("NO\n");
	}

	return 0;
}
