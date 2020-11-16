#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
#include<cstring>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n, m;

		scanf("%d %d", &n, &m);

		vector<string> arr;

		for (int i = 0; i < n; i++)
		{
			char input[11];

			scanf("%s", input);

			string str = input;

			arr.push_back(str);
		}

		int dp[2][1024] = { 0, };
		const int ub = (int)pow(2.0, n);

		dp[1][ub - 1] = 1;
		vector<vector<string>> str(2);

		for (int i = 0; i < ub; i++)
		{
			string emp;

			str[0].push_back(emp);
			str[1].push_back(emp);
		}

		for (int i = 0; i < m; i++)
		{
			vector<pair<int, string>> cand;

			for (int j = 0; j < ub; j++)
			{
				dp[i % 2][j] = 0;

				if (dp[!(i % 2)][j])
				{
					cand.push_back({ j , str[!(i % 2)][j] });
				}
			}

			for (char j = 'a'; j <= 'z'; j++)
			{
				int mask = 0;

				for (int k = 0; k < n; k++)
				{
					mask = mask * 2 + (arr[k][i] == j);
				}

				for (int k = 0; k < cand.size(); k++)
				{
					if ((mask | cand[k].first) == ub - 1)
					{
						const int next = mask & cand[k].first;

						if (!dp[i % 2][next])
						{
							string cur = cand[k].second;

							dp[i % 2][next] = 1;

							cur.push_back(j);

							str[i % 2][next] = cur;
						}
					}
				}
			}
		}

		bool found = false;

		for (int i = 0; i < ub; i++)
		{
			if (dp[!(m % 2)][i])
			{
				printf("%s\n", str[!(m % 2)][i].c_str());

				found = true;
				
				break;
			}
		}

		if (!found)
		{
			printf("-1\n");
		}
	}

	return 0;
}