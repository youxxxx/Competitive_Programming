#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<functional>

using namespace std;

int main()
{
	int n, m;
	int z;
	int i, j, k;
	long long one[3], two, three;
	long long sol = 0, cand[4], crd[4][3];
	long long input1, input2;
	long long dp[2][10] = { 0, };
	long long val;
	int cnt = 0, ub;
	int bit = 0;

	//freopen("input.txt", "r", stdin);

	scanf("%d", &n);

	for (z = 0; z < n; z++)
	{
		scanf("%d", &m);


		for (i = 0; i < 3; i++)
		{
			one[i] = 0;

			for (j = 0; j < 3; j++)
			{
				crd[i + 1][j] = 0;
			}
		}

		two = three = 0;

		for (i = 0; i < m; i++)
		{
			scanf("%lld %lld", &input1, &input2);

			switch (input1)
			{
			case 1:
				for (j = 0; j < 3; j++)
				{
					if (input2 > one[j])
					{
						for (k = 2; k > j; k--)
						{
							one[k] = one[k - 1];
						}

						one[j] = input2;

						break;
					}
				}
				break;
			case 2:
				if (input2 > two)
				{
					two = input2;
				}
				break;
			default:
				if (input2 > three)
				{
					three = input2;
				}
				break;
			}
		}

		for (i = 1; i <= 3; i++)
		{
			cand[i] = 0;
		}

		if (three > cand[1])
		{
			cand[1] = three;

			crd[1][0] = three;
		}

		if (two > cand[1])
		{
			cand[1] = two;

			crd[1][0] = two;
		}

		if (one[0] > cand[1])
		{
			cand[1] = one[0];

			crd[1][0] = one[0];
		}

		if (two > 0 && one[0] > 0 && two + one[0] > cand[2])
		{
			cand[2] = two + one[0];

			crd[2][0] = two;
			crd[2][1] = one[0];
		}

		if (one[0] > 0 && one[1] > 0 && one[0] + one[1] > cand[2])
		{
			cand[2] = one[0] + one[1];

			crd[2][0] = one[0];
			crd[2][1] = one[1];
		}

		if (one[0] > 0 && one[1] > 0 && one[2] > 0)
		{
			cand[3] = one[0] + one[1] + one[2];

			for (i = 0; i < 3; i++)
			{
				crd[3][i] = one[i];
			}
		}

		for (i = 1; i <= 3; i++)
		{
			sort(&crd[i][0], &crd[i][3], greater<int>());
		}

		for (i = 0; i < 10; i++)
		{
			dp[bit][i] = dp[!bit][i];
		}

		ub = 9 < cnt ? 9 : cnt;

		for (i = 0; i <= ub; i++)
		{
			for (j = 1; j <= 3; j++)
			{
				if (cand[j])
				{
					val = dp[!bit][i] + cand[j];

					if (i + j >= 10)
					{
						val += crd[j][0];
					}

					if (val > dp[bit][(i + j) % 10])
					{
						dp[bit][(i + j) % 10] = val;
					}
				}
			}
		}

		for (i = 2; i <= 3; i++)
		{
			if (!cand[i])
			{
				break;
			}
		}

		cnt += i - 1;

		bit = !bit;
	}

	sol = 0;

	for (i = 0; i < 10; i++)
	{
		if (dp[!(n % 2)][i] > sol)
		{
			sol = dp[!(n % 2)][i];
		}
	}

	printf("%lld\n", sol);

	return 0;
}