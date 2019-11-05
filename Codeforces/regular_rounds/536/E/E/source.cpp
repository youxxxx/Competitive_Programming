#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

struct env
{
	long long start;
	long long end;
	long long ext;
	long long val;
	long long idx;
};

class mycomparison
{
public:
	bool operator() (const env &a, const env &b) const
	{
		return a.val < b.val || a.val == b.val&&a.ext < b.ext;
	}
};

bool func(const env &a, const env &b)
{
	return a.start < b.start;
}

int main()
{
	env cur;
	vector<env> arr, ori;
	long long n, m, k;
	long long i, j;
	long long ptr = 0;
	long long *choice;
	long long **dp;
	long long min;
	long long input[4];

	priority_queue<env, vector<env>, mycomparison> q;

	//freopen("input.txt", "r", stdin);

	scanf("%I64d %I64d %I64d", &n, &m, &k);

	choice = new long long[n + 1];

	dp = new long long*[n + 2];

	for (i = 1; i <= n + 1; i++)
	{
		dp[i] = new long long[m + 1];

		for (j = 0; j <= m; j++)
		{
			dp[i][j] = -1;
		}
	}

	dp[1][0] = 0;

	for (i = 0; i < k; i++)
	{
		scanf("%I64d %I64d %I64d %I64d", &input[0], &input[1], &input[2], &input[3]);

		cur.start = input[0];
		cur.end = input[1];
		cur.ext = input[2];
		cur.val = input[3];

		cur.idx = i;

		arr.push_back(cur);

		ori.push_back(cur);
	}

	sort(arr.begin(), arr.end(), func);

	for (i = 1; i <= n; i++)
	{
		while (!q.empty()&&q.top().end < i)
		{
			q.pop();
		}

		while (ptr < k&&arr[ptr].start == i)
		{
			q.push(arr[ptr++]);
		}

		if (q.empty())
		{
			choice[i] = -1;
		}
		
		else
		{
			choice[i] = q.top().idx;
		}
	}
	
	for (i = 1; i <= n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (dp[i][j] != -1)
			{
				if (choice[i] == -1)
				{
					if (dp[i + 1][j] == -1 || dp[i + 1][j] > dp[i][j])
					{
						dp[i + 1][j] = dp[i][j];
					}
				}

				else
				{
					if (dp[ori[choice[i]].ext + 1][j] == -1 || dp[ori[choice[i]].ext + 1][j] > dp[i][j] + ori[choice[i]].val)
					{
						dp[ori[choice[i]].ext + 1][j] = dp[i][j] + ori[choice[i]].val;
					}

					if (dp[i + 1][j + 1] == -1 || dp[i + 1][j + 1] > dp[i][j])
					{
						dp[i + 1][j + 1] = dp[i][j];
					}
				} 
			}
		}

		if (dp[i][m] != -1)
		{
			if (choice[i] == -1)
			{
				if (dp[i + 1][m] == -1 || dp[i + 1][m] > dp[i][m])
				{
					dp[i + 1][m] = dp[i][m];
				}
			}

			else
			{
				if (dp[ori[choice[i]].ext + 1][m] == -1 || dp[ori[choice[i]].ext + 1][m] > dp[i][m] + ori[choice[i]].val)
				{
					dp[ori[choice[i]].ext + 1][m] = dp[i][m] + ori[choice[i]].val;
				}
			}
		}
	}

	min = 9999999999999999;

	for (i = 0; i <= m; i++)
	{
		if (dp[n + 1][i] != -1 && dp[n + 1][i] < min)
		{
			min = dp[n + 1][i];
		}
	}

	printf("%I64d\n", min);

	return 0;
}