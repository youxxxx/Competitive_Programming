#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n, m;
	int adj[101][101];
	int i, j, k;
	char input[101];
	int input2;
	string str;
	int prev, cur;
	int pidx;
	vector<int> arr, sol;
	
	//freopen("input.txt", "r", stdin);

	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		scanf("%s", input);

		str = input;

		for (j = 0; j < n; j++)
		{
			adj[i][j + 1] = str[j] - '0';

			if (adj[i][j + 1] == 0)
			{
				adj[i][j + 1] = -1;
			}
		}
	}

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i == j)
			{
				continue;
			}

			for (k = 1; k <= n; k++)
			{
				if (i == k || j == k)
				{
					continue;
				}

				if (adj[j][i] != -1 && adj[i][k] != -1)
				{
					if (adj[j][k] == -1 || adj[j][i] + adj[i][k] <= adj[j][k])
					{
						adj[j][k] = adj[j][i] + adj[i][k];
					}
				}
			}
		}
	}

	scanf("%d", &m);

	for (i = 0; i < m; i++)
	{
		scanf("%d", &input2);

		arr.push_back(input2);
	}

	prev = arr[0];
	pidx = 0;

	sol.push_back(prev);

	for (i = 1; i < m; i++)
	{
		cur = arr[i];

		if (adj[prev][cur] != i - pidx)
		{
			sol.push_back(arr[i - 1]);
			prev = arr[i - 1];
			pidx = i - 1;
		}
	}

	sol.push_back(arr[m - 1]);

	printf("%d\n", sol.size());

	for (i = 0; i < sol.size(); i++)
	{
		printf("%d ", sol[i]);
	}

	return 0;
}