#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<functional>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int n, m;

	scanf("%d %d", &n, &m);

	if (n == 1)
	{
		printf("0\n");

		return 0;
	}

	if (n > 3)
	{
		printf("-1\n");

		return 0;
	}

	vector<string> temp;

	for (int i = 0; i < n; i++)
	{
		char input[1000001];

		scanf("%s", input);

		string str = input;

		temp.push_back(str);
	}

	vector<vector<int>> arr;

	for (int i = 0; i < m; i++)
	{
		vector<int> emp;

		for (int j = 0; j < n; j++)
		{
			emp.push_back(temp[j][i] - '0');
		}

		arr.push_back(emp);
	}

	if (n == 2)
	{
		int sol = 0;

		for (int i = 0; i < m; i++)
		{
			if (i % 2)
			{
				sol += (arr[i][0] == arr[i][1]);
			}

			else
			{
				sol += (arr[i][0] != arr[i][1]);
			}
		}

		int cand = 0;

		for (int i = 0; i < m; i++)
		{
			if (i % 2)
			{
				cand += (arr[i][0] != arr[i][1]);
			}

			else
			{
				cand += (arr[i][0] == arr[i][1]);
			}
		}

		if (cand < sol)
		{
			sol = cand;
		}

		printf("%d\n", sol);

		return 0;
	}

	int type[8][3] = { { 0,0,0 },{ 0,0,1 },{ 0,1,0 },{ 0,1,1 },{ 1,0,0 },{ 1,0,1 },{ 1,1,0 } ,{ 1,1,1 } };
	int prev[8][2] = { { 2,5 },{ 3, 4 },{ 0, 7 },{ 1,6 },{ 1,6 },{ 0, 7 },{ 3, 4 },{ 2,5 } };

	int dp[2][8];

	for (int i = 0; i < 8; i++)
	{
		dp[0][i] = 0;

		for (int j = 0; j < 3; j++)
		{
			dp[0][i] += (type[i][j] != arr[0][j]);
		}
	}

	for (int i = 1; i < m; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			dp[i % 2][j] = 0;
		}

		for (int j = 0; j < 8; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				dp[i % 2][j] += (type[j][k] != arr[i][k]);
			}

			dp[i % 2][j] += (dp[!(i % 2)][prev[j][0]] < dp[!(i % 2)][prev[j][1]] ? dp[!(i % 2)][prev[j][0]] : dp[!(i % 2)][prev[j][1]]);
		}
	}
	
	int sol = n*m + 1;

	for (int i = 0; i < 8; i++)
	{
		if (dp[!(m % 2)][i] < sol)
		{
			sol = dp[!(m % 2)][i];
		}
	}

	printf("%d\n", sol);

	return 0;
}