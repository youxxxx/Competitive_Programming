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

#define MAX 2001

int n, m;

bool safe(int x, int y)
{
	return x >= 1 && x <= n&&y >= 1 && y <= m;
}

int main()
{
	//freopen("input.txt", "r", stdin);

	scanf("%d %d", &n, &m);
	
	vector<string> arr;

	string str;

	arr.push_back(str);

	for (int i = 0; i < n; i++)
	{
		char input[2001];

		scanf("%s", input);

		string str = input;
		string base = " ";
		
		base.append(str);

		arr.push_back(base);
	}

	int link[2001][2001] = { 0, };
	int visited[2001][2001] = { 0, };
	int val[2001][2001];


	const int dx[4] = { -1,1,0,0 };
	const int dy[4] = { 0,0,-1,1 };

	queue<pair<int, int>> q;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			val[i][j] = MAX;

			for (int k = 0; k < 4; k++)
			{
				const int nx = i + dx[k];
				const int ny = j + dy[k];

				if (safe(nx, ny))
				{
					if (arr[nx][ny] == arr[i][j])
					{
						link[i][j]++;
					}
				}
			}

			if (link[i][j] != 4)
			{
				q.push({ i,j });

				val[i][j] = 1;

				visited[i][j] = 4;
			}
		}
	}

	while (!q.empty())
	{
		const int x = q.front().first;
		const int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			const int nx = x + dx[i];
			const int ny = y + dy[i];

			if (safe(nx, ny))
			{
				if (link[nx][ny] == 4 && val[nx][ny] == MAX)
				{
					val[nx][ny] = val[x][y] + 1;

					q.push({ nx, ny });
				}
			}
		}
	}

	long long sol = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			sol += val[i][j];
		}
	}

	printf("%lld\n", sol);

	return 0;
}