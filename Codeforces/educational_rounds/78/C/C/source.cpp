#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	long long cases;

	scanf("%lld", &cases);

	for (long long tc = 0; tc < cases; tc++)
	{
		int n;
		int lmin[2][200001];
		int arr[200001];
		int base = 0;

		scanf("%d", &n);

		for (int i = 1; i <= n; i++)
		{
			lmin[0][100000 + i] = lmin[1][100000 + i] = lmin[0][100000 - i] = lmin[1][100000 - i] = -1;
		}

		lmin[0][100000] = lmin[1][100000] = 0;

		for (int i = 0; i < n * 2; i++)
		{
			int input;

			scanf("%d", &input);

			if (input == 1)
			{
				arr[i] = -1;
			}

			else
			{
				arr[i] = 1;
			}

			base += arr[i];
		}

		if (base == 0)
		{
			printf("0\n");

			continue;
		}

		int cur = 0;

		for (int i = n - 1; i >= 0; i--)
		{
			cur += arr[i];

			if (lmin[0][cur + 100000] == -1)
			{
				lmin[0][cur + 100000] = n - i;
			}
		}

		cur = 0;

		for (int i = n; i < n * 2; i++)
		{
			cur += arr[i];

			if (lmin[1][cur + 100000] == -1)
			{
				lmin[1][cur + 100000] = i - n + 1;
			}
		}

		int sol = 99999999;

		for (int i = -n; i <= n; i++)
		{
			if (base - i<-n || base - i>n)
			{
				continue;
			}

			if (lmin[0][i + 100000] != -1 && lmin[1][(base - i) + 100000] != -1)
			{
				if (lmin[0][i + 100000] + lmin[1][(base - i) + 100000] < sol)
				{
					sol = lmin[0][i + 100000] + lmin[1][(base - i) + 100000];
				}
			}
		}

		printf("%d\n", sol);
	}

	return 0;
}