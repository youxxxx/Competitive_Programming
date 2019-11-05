#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<queue>

using namespace std;

bool safe(int x, int y, int n)
{
	return x >= 0 && x < n&&y >= 0 && y < n;
}

class comp
{
public:
	bool operator() (const pair<pair<int, int>, pair<int, int>>& a, const pair<pair<int, int>, pair<int, int>>&b) const
	{
		return (a.second.first)*(a.second.first) + (a.second.second)*(a.second.second) > (b.second.first)*(b.second.first) + (b.second.second)*(b.second.second);
	}
};

int main()
{
	int n;
	int xs, ys;
	int xt, yt;
	int x, y;
	int newx, newy;
	int i, j;
	string str[51];
	char input[100];
	int visited[51][51];
	priority_queue<pair<pair<int, int>, pair<int, int>>, vector<pair<pair<int, int>, pair<int, int>>>, comp> q;
	pair<pair<int, int>, pair<int, int>> cur, next;
	queue<pair<int, int>> nq;
	pair<int, int> ncur;
	int min = 10000;
	int dx[4] = { 0,-1,0,1 };
	int dy[4] = { -1,0,1,0 };
	int newval;

	//freopen("input.txt", "r", stdin);

	scanf("%d", &n);

	scanf("%d %d %d %d", &xs, &ys, &xt, &yt);

	xs--;
	ys--;
	xt--;
	yt--;

	for (i = 0; i < n; i++)
	{
		scanf("%s", input);

		str[i] = input;

		for (j = 0; j < n; j++)
		{
			visited[i][j] = -1;
		}
	}

	ncur.first = xs;
	ncur.second = ys;
	str[xs][ys] = '2';

	nq.push(ncur);

	while (!nq.empty())
	{
		ncur = nq.front();
		nq.pop();
		x = ncur.first;
		y = ncur.second;

		for (i = 0; i < 4; i++)
		{
			newx = x + dx[i];
			newy = y + dy[i];

			if (safe(x + dx[i], y + dy[i], n) && str[newx][newy] == '0')
			{
				str[newx][newy] = '2';

				nq.push(pair<int, int>(newx, newy));
			}
		}
	}

	if (str[xt][yt] == '2')
	{
		printf("0\n");

		return 0;
	}

	ncur.first = xt;
	ncur.second = yt;
	str[xt][yt] = '3';

	nq.push(ncur);

	while (!nq.empty())
	{
		ncur = nq.front();
		nq.pop();
		x = ncur.first;
		y = ncur.second;

		for (i = 0; i < 4; i++)
		{
			newx = x + dx[i];
			newy = y + dy[i];

			if (safe(x + dx[i], y + dy[i], n) && str[newx][newy] == '0')
			{
				str[newx][newy] = '3';

				nq.push(pair<int, int>(newx, newy));
			}
		}
	}

	cur.first.first = xs;
	cur.first.second = ys;
	cur.second.first = 0;
	cur.second.second = 0;

	q.push(cur);

	visited[xs][ys] = 0;

	while (!q.empty())
	{
		cur = q.top();
		q.pop();
		x = cur.first.first;
		y = cur.first.second;

		if (x == xt&&y == yt)
		{
			if ((cur.second.first)*(cur.second.first) + (cur.second.second)*(cur.second.second) < min)
			{
				min = (cur.second.first)*(cur.second.first) + (cur.second.second)*(cur.second.second);
			}

			continue;
		}

		for (i = 0; i < 4; i++)
		{
			newx = x + dx[i];
			newy = y + dy[i];

			if (safe(x + dx[i], y + dy[i], n))
			{
				if (str[x][y] == '2'&&str[newx][newy] == '2' || str[x][y] == '3'&&str[newx][newy] == '3')
				{
					newval = (cur.second.first)*(cur.second.first) + (cur.second.second)*(cur.second.second);
				}

				else
				{
					newval = (cur.second.first + abs(dx[i]))*(cur.second.first + abs(dx[i])) + (cur.second.second + abs(dy[i]))*(cur.second.second + abs(dy[i]));
				}

				if(visited[x + dx[i]][y + dy[i]] == -1 || newval < visited[x + dx[i]][y + dy[i]])
				{
					visited[newx][newy] = newval;

					if (str[x][y] == '2'&&str[newx][newy] == '2' || str[x][y] == '3'&&str[newx][newy] == '3')
					{
						next.first.first = newx;
						next.first.second = newy;
						next.second.first = cur.second.first;
						next.second.second = cur.second.second;

						/*
						if (!cur.second.first && !cur.second.second
						|| !(str[x][y] == '0' && str[newx][newy] == '1'))
						{
						q.push(next);
						}
						*/
					}

					else
					{
						if (i % 2)
						{
							next.first.first = newx;
							next.first.second = newy;
							next.second.first = cur.second.first + 1;
							next.second.second = cur.second.second;
						}

						else
						{
							next.first.first = newx;
							next.first.second = newy;
							next.second.first = cur.second.first;
							next.second.second = cur.second.second + 1;
						}
					}

					q.push(next);
				}
			}
		}
	}

	printf("%d\n", min);

	return 0;
} 