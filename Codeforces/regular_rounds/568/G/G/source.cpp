#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>

using namespace std;

struct sheet
{
	int last;
	int taken;
};

int main()
{
	int n, m;
	vector<sheet> dp[226];
	int num[226][32768][3] = { 0, };
	//bool visited[226][32768][4] = { 0, };
	vector<pair<int, int>> songs;
	int i, j, k, l;
	int len, genre;
	int sum = 0;
	int select;
	sheet cur, next;

	//freopen("input.txt", "r", stdin);

	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &len, &genre);

		songs.push_back(pair<int, int>(len, genre - 1));
	}

	cur.last = 3;
	cur.taken = 0;
	num[0][0][0] = 1;

	dp[0].push_back(cur);

	for (i = 0; i <= m; i++)
	{
		for (j = 0; j < dp[i].size(); j++)
		{
			cur.last = dp[i][j].last;
			cur.taken = dp[i][j].taken;

			select = 1;

			for (k = 0; k < n; k++)
			{
				if (!(cur.taken&select) && songs[k].second != cur.last && songs[k].first + i <= m)
				{
					next.last = songs[k].second;
					next.taken = select | cur.taken;

					if (num[songs[k].first + i][next.taken][next.last] == 0)
					{
						dp[songs[k].first + i].push_back(next);

						//visited[songs[k].first + i][next.taken][next.last] = true;
					}

					num[songs[k].first + i][next.taken][next.last] = (num[songs[k].first + i][next.taken][next.last] + num[i][cur.taken][cur.last]) % 1000000007;
				}

				select *= 2;
			}
		}
	}

	for (i = 0; i < dp[m].size(); i++)
	{
		sum = sum + (num[m][dp[m][i].taken][dp[m][i].last]) % 1000000007;
	}

	printf("%lld\n", sum);
	
	return 0;
}