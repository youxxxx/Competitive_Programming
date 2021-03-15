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

bool safe(int x, int y, int n, int m)
{
	return x >= 0 && x < n&&y >= 0 && y < m;
}

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	vector<string> arr[2];

	for (int tc = 0; tc < cases; tc++)
	{
		arr[0].clear();
		arr[1].clear();

		int n, m;

		scanf("%d %d", &n, &m);

		int sol = 0;

		for (int i = 0; i < n; i++)
		{
			char input[501];

			scanf("%s", input);
			const string str = input;

			arr[0].push_back(str);
			arr[1].push_back(str);

			for (int j = 0; j < m; j++)
			{
				sol += (str[j] == '*');
			}
		}

		const int dx[3] = { -1,0,0 };
		const int dy[3] = { 0,-1,1 };

		for (int k = 0; k < min(n, m); k++)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (arr[!(k%2)][i][j] == '.')
					{
						arr[k%2][i][j] = '.';

						continue;
					}

					bool valid = true;

					for (int l = 0; l < 3; l++)
					{
						const int nx = i + dx[l];
						const int ny = j + dy[l];

						if (!safe(nx, ny, n, m) || arr[!(k%2)][nx][ny] == '.')
						{
							valid = false;

							break;
						}
					}

					if (valid)
					{
						arr[k%2][i][j] = '*';

						sol++;
					}

					else
					{
						arr[k%2][i][j] = '.';
					}
				}
			}
		}

		printf("%d\n", sol);
	}

	return 0;
}