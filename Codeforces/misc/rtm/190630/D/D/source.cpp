#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool func(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b)
{
	return a.first.first < b.first.first || a.first.first == b.first.first&&a.first.second < b.first.second;
}

int main()
{
	int n, m, k, q;
	int i, j, l;
	vector<pair<pair<int, int>, int>> broken;
	bool visited[500][500] = { 0, };
	vector<pair<int, int>> v[500][500], h[500][500];
	pair<int, int> cur;
	int vptr, hptr;
	int cand, sol = -1;
	int x, y, t;

	freopen("input.txt", "r", stdin);

	scanf("%d %d %d %d", &n, &m, &k, &q);

	for (i = 0; i < q; i++)
	{
		scanf("%d %d %d", &x, &y, &t);

		broken.push_back(make_pair(make_pair(x - 1, y - 1), t));
	}

	sort(broken.begin(), broken.end(), func);

	for (i = 0; i < q; i++)
	{
		x = broken[i].first.first;
		y = broken[i].first.second;
		t = broken[i].second;

		vptr = -1;
		hptr = -1;

		if (x == 0 || !visited[x - 1][y])
		{
			v[x][y].push_back(make_pair(1, t));
		}

		else
		{
			cur.second = t;

			for (j = 0; j < v[x - 1][y].size(); j++)
			{
				if (v[x - 1][y][j].second > t)
				{
					break;
				}

				if (v[x - 1][y][j].first >= k)
				{
					break;
				}

				cur.first = v[x - 1][y][j].first + 1;

				if (cur.first == k)
				{
					vptr = t;
				}
			}

			if (j != 0)
			{
				v[x][y].push_back(cur);
			}

			l = j;

			for (j = l; j < v[x - 1][y].size(); j++)
			{
				if (v[x - 1][y][j].first >= k)
				{
					break;
				}

				cur.first = v[x - 1][y][j].first + 1;
				cur.second = v[x - 1][y][j].second;

				v[x][y].push_back(cur);

				if (cur.first == k)
				{
					vptr = cur.second;
				}
			}
		}

		if (y == 0 || !visited[x][y - 1])
		{
			h[x][y].push_back(make_pair(1, t));
		}

		else
		{
			cur.second = t;

			for (j = 0; j < h[x][y - 1].size(); j++)
			{
				if (h[x][y - 1][j].second > t)
				{
					break;
				}

				if (h[x][y - 1][j].first >= k)
				{
					break;
				}

				cur.first = h[x][y - 1][j].first + 1;

				if (cur.first == k)
				{
					hptr = t;
				}
			}

			if (j != 0)
			{
				h[x][y].push_back(cur);
			}

			l = j;

			for (j = l; j < h[x][y - 1].size(); j++)
			{
				if (h[x][y - 1][j].first >= k)
				{
					break;
				}

				cur.first = h[x][y - 1][j].first + 1;
				cur.second = h[x][y - 1][j].second;

				h[x][y].push_back(cur);

				if (cur.first == k)
				{
					hptr = cur.second;
				}
			}
		}

		visited[x][y] = true;

		cand = -1;

		if (vptr != -1 && hptr != -1)
		{
			cand = vptr > hptr ? vptr : hptr;
		}

		if (cand!=-1 && (sol == -1 || cand < sol))
		{
			sol = cand;
		}
	}

	printf("%d\n", sol);

	return 0;
}