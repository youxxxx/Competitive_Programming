#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int t, z;
	long long dp[2][9000];
	vector<int> graph[9001];
	int stamp[9001];
	int i, j, h;
	int n, m, k, q;
	int input1, input2;
	long long sum;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d %d %d", &n, &m, &k);

		for (i = 1; i <= n; i++)
		{
			graph[i].push_back(i);
		}

		for (i = 0; i < m; i++)
		{
			scanf("%d %d", &input1, &input2);

			graph[input1].push_back(input2);
			graph[input2].push_back(input1);
		}

		for (i = 0; i <= k; i++)
		{
			stamp[i] = 0;
		}

		scanf("%d", &q);

		for (i = 0; i < q; i++)
		{
			scanf("%d %d", &input1, &input2);
			
			if (stamp[input2] && stamp[input2] != input1)
			{
				printf("0\n");

				for (j = 1; j <= n; j++)
				{
					graph[j].clear();
				}

				break;
			}
			
			stamp[input2] = input1;
		}

		if (i != q)
		{
			continue;
		}

		if (stamp[0] >= 2)
		{
			printf("0\n");

			for (i = 1; i <= n; i++)
			{
				graph[i].clear();
			}

			continue;
		}

		dp[0][1] = 1;

		for (j = 2; j <= n; j++)
		{
			dp[0][j] = 0;
		}

		for (i = 1; i <= k; i++)
		{
			if (!stamp[i])
			{
				for (j = 1; j <= n; j++)
				{
					dp[i % 2][j] = 0;

					for (h = 0; h < graph[j].size(); h++)
					{
						dp[i % 2][j] = (dp[i % 2][j] + dp[!(i % 2)][graph[j][h]]) % 1000000007;
					}
				}
			}

			else
			{
				for (j = 1; j <= n; j++)
				{
					dp[i % 2][j] = 0;
				}

				for (h = 0; h < graph[stamp[i]].size(); h++)
				{
					dp[i % 2][stamp[i]] = (dp[i % 2][stamp[i]] + dp[!(i % 2)][graph[stamp[i]][h]]) % 1000000007;
				}
			}
		}

		sum = 0;

		for (i = 1; i <= n; i++)
		{
			sum = (sum + dp[k % 2][i]) % 1000000007;
		}

		printf("%lld\n", sum);

		for (i = 1; i <= n; i++)
		{
			graph[i].clear();
		}
	}

	return 0;
}