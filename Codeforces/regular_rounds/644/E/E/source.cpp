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

bool safe(int x, int y, int n)
{
	return x >= 0 && x < n&&y >= 0 && y < n;
}

int main()
{
	//freopen("input.txt", "r", stdin);

	const int dx[2] = { 0, -1 };
	const int dy[2] = { -1, 0 };

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;

		scanf("%d", &n);

		vector<string> arr;

		for (int i = 0; i < n; i++)
		{
			char input[51];

			scanf("%s", input);

			string str = input;

			arr.push_back(str);
		}

		if (n == 1)
		{
			printf("YES\n");

			continue;
		}

		arr[n - 1][n - 1] = '0';

		queue < pair<int, int>> q;

		for (int i = 0; i < n - 1; i++)
		{
			if (arr[i][n - 1] == '1')
			{
				arr[i][n - 1] = '2';

				if (arr[i][n - 2] == '1')
				{
					arr[i][n - 2] = '2';

					q.push({ i,n - 2 });
				}
			}

			if (arr[n - 1][i] == '1')
			{
				arr[n - 1][i] = '2';

				if (arr[n - 2][i] == '1')
				{
					arr[n - 2][i] = '2';

					q.push({ n - 2, i });
				}
			}
		}

		while (!q.empty())
		{
			const int x = q.front().first;
			const int y = q.front().second;
			q.pop();

			for (int i = 0; i < 2; i++)
			{
				const int nx = x + dx[i];
				const int ny = y + dy[i];

				if (safe(nx, ny, n) && arr[nx][ny]=='1')
				{
					arr[nx][ny] = '2';

					q.push({ nx,ny });
				}
			}
		}

		bool valid = true;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (arr[i][j] == '1')
				{
					valid = false;

					break;
				}
			}
		}

		if (valid)
		{
			printf("YES\n");
		}

		else
		{
			printf("NO\n");
		}
	}

	return 0;
}