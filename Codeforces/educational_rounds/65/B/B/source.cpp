#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int res[4];
	int nums[6] = { 4,8,15,16,23,42 };
	int prod[6][6];
	int sol[6];
	int i, j, k;
	pair<int, int> div[4];
	bool taken[6] = { 0, };

	for (i = 0; i < 6; i++)
	{
		for (j = i + 1; j < 6; j++)
		{
			prod[i][j] = nums[i] * nums[j];
		}
	}

	for (i = 0; i < 4; i++)
	{
		printf("? %d %d\n", i + 1, i + 2);
		
		fflush(stdout);

		scanf("%d", &res[i]);

		for (k = 0; k < 6; k++)
		{
			for (j = k + 1; j < 6; j++)
			{
				if (res[i] == prod[k][j])
				{
					div[i] = pair<int, int>(k, j);
				}
			}
		}
	}

	if (div[0].first == div[1].first)
	{
		sol[0] = div[0].second;
		sol[1] = div[0].first;
		sol[2] = div[1].second;
	}

	else if (div[0].first == div[1].second)
	{
		sol[0] = div[0].second;
		sol[1] = div[0].first;
		sol[2] = div[1].first;
	}

	else if (div[0].second == div[1].first)
	{
		sol[0] = div[0].first;
		sol[1] = div[0].second;
		sol[2] = div[1].second;
	}

	else
	{
		sol[0] = div[0].first;
		sol[1] = div[0].second;
		sol[2] = div[1].first;
	}

	for (i = 3; i < 5; i++)
	{
		if (div[i - 1].first == sol[i - 1])
		{
			sol[i] = div[i - 1].second;
		}

		else
		{
			sol[i] = div[i - 1].first;
		}
	}

	for (i = 0; i < 5; i++)
	{
		taken[sol[i]] = true;
	}

	for (i = 0; i < 6; i++)
	{
		if (!taken[i])
		{
			sol[5] = i;

			break;
		}
	}

	printf("!");

	for (i = 0; i < 6; i++)
	{
		printf(" %d", nums[sol[i]]);
	}

	return 0;
}