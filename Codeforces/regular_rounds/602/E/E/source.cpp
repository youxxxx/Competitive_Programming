#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

const int dx[8] = { -1,-1,-1,0,0,1,1,1 };
const int dy[8] = { -1,0,1,-1,1,-1,0,1 };
int n, m;
int searched = 1;
vector<string> arr;
vector<vector<int>> visited;
vector<pair<pair<int, int>, int>> lmax;
int tot = 0;

bool func(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b)
{
	return a.second < b.second;
}

bool safe(int x, int y)
{
	return x >= 0 && x < n + 2 && y >= 0 && y < m + 2;
}

int bin_search(int lb, int ub)
{
	searched++;

	if (ub - lb < 2)
	{
		return lb;
	}

	int next;

	next = (lb + ub) / 2;

	vector<pair<pair<int, int>, int>>::iterator it, ret;
	pair<pair<int, int>, int> dummy;

	dummy.second = next + 1;

	ret = lower_bound(lmax.begin(), lmax.end(), dummy, func);

	queue<pair<pair<int, int>, int>> q;

	int cnt = 0;

	for (it = ret; it != lmax.end(); it++)
	{
		q.push({ {it->first.first, it->first.second}, 0 });

		visited[it->first.first][it->first.second] = searched;
		cnt++;
	}

	bool valid = true;

	while (!q.empty())
	{
		int x, y, val;
		int nx, ny;

		x = q.front().first.first;
		y = q.front().first.second;
		val = q.front().second;
		q.pop();

		if (val < next)
		{
			for (int i = 0; i < 8; i++)
			{
				nx = x + dx[i];
				ny = y + dy[i];

				if (safe(nx, ny) && visited[nx][ny] != searched)
				{
					if (arr[nx][ny] == '.')
					{
						valid = false;

						break;
					}
					visited[nx][ny] = searched;

					q.push({ { nx,ny },val + 1 });

					cnt++;
				}
			}

			if (!valid)
			{
				break;
			}
		}
	}

	if (valid && cnt == tot)
	{
		return bin_search(next, ub);
	}

	return bin_search(lb, next);
}

int main()
{
	vector<string> sol;
	vector<int> zero;
	string def, def2;

	//freopen("input.txt", "r", stdin);

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m + 2; i++)
	{
		def.push_back('.');

		zero.push_back(false);
	}

	for (int i = 0; i < m; i++)
	{
		def2.push_back('.');
	}

	arr.push_back(def);
	visited.push_back(zero);

	for (int i = 0; i < n; i++)
	{
		char input[1000001];
		string str;
		string emp;

		scanf("%s", input);
		str = input;

		emp.push_back('.');
		emp.append(str);
		emp.push_back('.');

		arr.push_back(emp);
		sol.push_back(def2);
		visited.push_back(zero);
	}

	arr.push_back(def);
	visited.push_back(zero);

	queue<pair<pair<int, int>, int>> q;

	for (int i = 0; i < n + 2; i++)
	{
		for (int j = 0; j < m + 2; j++)
		{
			if (arr[i][j] == '.')
			{
				visited[i][j] = 1;

				q.push({ {i,j},0 });
			}
		}
	}

	while (!q.empty())
	{
		int x, y, val;
		int nx, ny;

		x = q.front().first.first;
		y = q.front().first.second;
		val = q.front().second;

		q.pop();

		for (int i = 0; i < 8; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];

			if (safe(nx, ny) && !visited[nx][ny])
			{
				visited[nx][ny] = 1;

				lmax.push_back({ {nx,ny},val + 1 });

				q.push({ { nx,ny },val + 1 });

				tot++;
			}
		}
	}

	int ub = (n < m ? n : m) + 1;
	int num;

	num = bin_search(0, ub);

	vector<pair<pair<int, int>, int>>::iterator it, ret;
	pair<pair<int, int>, int> dummy;

	dummy.second = num + 1;

	ret = lower_bound(lmax.begin(), lmax.end(), dummy, func);

	for (it = ret; it != lmax.end(); it++)
	{
		sol[it->first.first - 1][it->first.second - 1] = 'X';
	}

	printf("%d\n", num);

	for (int i = 0; i < n; i++)
	{
		printf("%s\n", sol[i].c_str());
	}

	return 0;
}