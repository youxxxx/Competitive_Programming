#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int n, r, input;
	vector<int> heater;
	int *dp;
	int i, j;
	int min, max, next;

	scanf("%d %d", &n, &r);

	r--;

	dp = new int[n + 1];

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		if (input)
		{
			heater.push_back(i);
		}

		dp[i + 1] = -1;
	}
	
	if (heater.empty()||heater[0] - r > 0)
	{
		printf("-1");
	}

	else
	{
		dp[0] = -1;
		min = 0;
		next = 0;
		max = 0;

		for (i = 0; i < heater.size(); i++)
		{
			for (j = min; j <= max; j++)
			{
				if (dp[j] + 1 >= heater[i] - r)
				{
					dp[j + 1] = heater[i] + r;

					max = j + 1;

					break;
				}

				next = j;
			}

			min = next;
		}

		for (i = 1; i <= max; i++)
		{
			if (dp[i] >= n - 1)
			{
				printf("%d", i);

				break;
			}
		}

		if (i == max + 1)
		{
			printf("-1");
		}
	}

	return 0;
}