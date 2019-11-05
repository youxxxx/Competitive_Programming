#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool func(const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b)
{
	return a.first < b.first || a.first == b.first&&a.second.first < b.second.first;
}

int main()
{
	int t, tc;
	int n, h;
	int x, a, b, c, d;
	int lb, ub;
	vector<pair<int,int>> graph[52];
	vector<pair<int,pair<int, int>>> ladder;
	vector<pair<int, int>> piece;
	int i, j, k;
	bool full;

	scanf("%d", &tc);

	for (t = 0; t < tc; t++)
	{
		scanf("%d %d", &n, &h);

		full = false;

		ladder.clear();

		for (i = 0; i <= n + 1; i++)
		{
			graph[i].clear();
		}

		ladder.push_back(make_pair(0, make_pair(0, 0)));

		for (i = 0; i < n; i++)
		{
			scanf("%d %d %d", &x, &a, &b);

			if (a == 0 && b == h)
			{
				full = true;
			}

			ladder.push_back(make_pair(x, make_pair(a, b)));
		}

		if (full)
		{
			printf("Case #%d: -1\n", t + 1);

			continue;
		}

		sort(ladder.begin(), ladder.end(), func);

		for (i = 1; i <= n; i++)
		{
			x = ladder[i].first;
			a = ladder[i].second.first;
			b = ladder[i].second.second;

			piece.push_back(make_pair(a, b));

			for (j = i + 1; j < n; j++)
			{
				if (ladder[i].first == ladder[j].first)
				{
					continue;
				}

				c = ladder[i].second.first;
				d = ladder[i].second.second;

				for (k = piece.size() - 1; k >= 0; k--)
				{
					lb = piece[k].first;
					ub = piece[k].second;

					if (lb >= c&&ub <= d)
					{
						graph[i].push_back(make_pair(j, ub - lb));

						piece.erase(piece.begin() + k);
					}

					else if (lb<c&&ub>d)
					{
						graph[i].push_back(make_pair(j, d - c));

						piece[k].second = c;

						piece.insert(piece.begin() + k, make_pair(d, ub));
					}

					else if (lb >= c&&lb <= d&&ub > d)
					{

						graph[i].push_back(make_pair(j, d - c));
					}
				}
			}
		}
	}

	return 0;
}