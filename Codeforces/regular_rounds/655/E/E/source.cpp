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

class comp
{
public:
	bool operator() (const pair<int, int> &a, const pair<int, int> &b)
	{
		return a.first > b.first;
	}
};

int main()
{
	freopen("input.txt", "r", stdin);

	int n, m;

	scanf("%d %d", &n, &m);

	int tot = 0;

	vector<int> grid[101];

	for (int i = 0; i < n; i++)
	{
		int k;

		scanf("%d", &k);

		for (int j = 0; j < k; j++)
		{
			int l, r;

			scanf("%d %d", &l, &r);

			grid[i].push_back(r);

			tot++;
		}
	}

	int ptr[101];

	priority_queue < pair<int, int>, vector<pair<int, int>>, comp> pq;

	for (int i = 0; i < n; i++)
	{
		ptr[i] = 1;

		pq.push({ grid[i][0],i });
	}

	int dp[2][10001];

	int lb = 0;
	int lmax = 0;

	for (int i = 0; i <= 100; i++)
	{
		dp[0][i] = 0;
	}

	for (int i = 1; i <= m; i++)
	{
		for (int j = lb; j <= lb + pq.size(); j++)
		{
			dp[i % 2][j] = 0;

			for (int k = lb; k <= j; k++)
			{
				if (dp[!(i % 2)][k] + (j - k)*(j - k) > dp[i % 2][j])
				{
					dp[i % 2][j] = dp[!(i % 2)][k] + (j - k)*(j - k);

					if (dp[i % 2][j] > lmax)
					{
						lmax = dp[i % 2][j];
					}
				}
			}
		}

		while (!pq.empty() && pq.top().first == i)
		{
			const int col = pq.top().first;
			const int row = pq.top().second;

			pq.pop();

			if (ptr[row] < grid[row].size())
			{
				pq.push({ grid[row][ptr[row]++],row });
			}

			lb++;
		}
	}

	printf("%d\n", lmax);

	return 0;
}