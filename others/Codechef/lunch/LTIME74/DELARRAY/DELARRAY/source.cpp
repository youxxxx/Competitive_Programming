#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int cases, tc;
	int i, j;
	vector<long long> arr;
	long long input;
	long long cur;
	int n;
	long long cnt;

	scanf("%d", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		scanf("%d", &n);

		arr.clear();

		cnt = 0;

		for (i = 0; i < n; i++)
		{
			scanf("%lld", &input);

			arr.push_back(input);
		}

		j = n - 1;
		cur = arr[j];

		for (i = n - 2; i >= 0; i--)
		{
			if (arr[i] >= cur)
			{
				break;
			}

			cur = arr[i];
		}

		j = i + 1;
		
		if (j == 0)
		{
			j++;
		}

		cnt += n - j;

		cur = arr[0];

		while (j != n&&arr[j] <= cur)
		{
			j++;
		}

		if (j == 1)
		{
			j++;
		}

		cnt += n - j + 1;

		for (i = 1; i < n - 1; i++)
		{
			if (arr[i] <= cur)
			{
				break;
			}

			cur = arr[i];

			while (j != n&&arr[j] <= cur)
			{
				j++;
			}

			if (j == i + 1)
			{
				j++;
			}

			cnt += n - j + 1;
		}

		printf("%lld\n", cnt);
	}

	return 0;
}