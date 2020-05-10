#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int t, z;
	vector<long long> xorlist;
	long long *arr;
	int n;
	long long tot, cur;
	int i, j;
	long long input;
	int bound1, bound2;
	int arrb;
	int temp;

	scanf("%d", &t);

	arr = new long long[50000];

	for (z = 0; z < t; z++)
	{
		scanf("%d", &n);

		tot = 0;

		bound1 = n;
		bound2 = 0;

		for (i = 0; i < n; i++)
		{
			arr[i] = 0;
		}

		if (n % 3 == 0)
		{
			if ((n / 3) % 2)
			{
				bound1 = bound2 = n / 2;
			}

			else
			{
				bound1 = bound2 = n / 2 + 1;
			}
		}

		if (n % 3 != 2)
		{
			arrb = bound1;

			for (i = 0; i < bound1; i++)
			{
				printf("1 %d %d %d\n", i + 1, (i + 1) % bound1 + 1, (i + 2) % bound1 + 1);
				fflush(stdout);

				scanf("%lld", &input);
				tot ^= input;

				xorlist.push_back(input);
			}

			for (i = 0; i < 3; i++)
			{
				cur = tot;

				for (j = 0; j < arrb / 3; j++)
				{
					cur ^= xorlist[(j * 3 + i + 1) % arrb];
				}

				arr[i] = cur;

				for (j = 1; j < arrb / 3 + (i == 0); j++)
				{
					cur ^= xorlist[((j - 1) * 3 + i) % arrb];

					cur ^= xorlist[((j - 1) * 3 + i + 1) % arrb];

					arr[i + j * 3] = cur;
				}
			}
		}
		 
		if (n % 3 != 1)
		{
			tot = 0;

			xorlist.clear();

			arrb = n - bound2;

			for (i = 0; i < n - bound2; i++)
			{
				printf("1 %d %d %d\n", i + 1 + bound2, (i + 1) % (n - bound2) + bound2 + 1, (i + 2) % (n - bound2) + bound2 + 1);
				fflush(stdout);

				scanf("%lld", &input);
				tot ^= input;

				xorlist.push_back(input);
			}

			for (i = 0; i < 3; i++)
			{
				cur = tot;

				for (j = 0; j <= arrb / 3; j++)
				{
					cur ^= xorlist[(j * 3 + i) % arrb];
				}

				arr[bound2 + i] = cur;

				for (j = 1; j < arrb / 3 + (i != 2); j++)
				{
					cur ^= xorlist[((j - 1) * 3 + i) % arrb];

					cur ^= xorlist[((j - 1) * 3 + i + 1) % arrb];

					arr[bound2 + i + j * 3] = cur;
				}
			}
		}

		printf("2");
		fflush(stdout);

		for (i = 0; i < n; i++)
		{
			printf(" %lld", arr[i]);
			fflush(stdout);
		}

		printf("\n");
		fflush(stdout);

		xorlist.clear();

		scanf("%d", &temp);

		if (temp == -1)
		{
			return 0;
		}
	}

	return 0;
}