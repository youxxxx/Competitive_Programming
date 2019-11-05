#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<functional>

#define MOD 2520

using namespace std;

int main()
{
	long long n, q;
	long long k[1001];
	long long i, j, l;
	long long visited[1001][MOD], nth[1001][MOD], depth[1001][MOD];
	long long outdeg[1001];
	long long edge[1001][10];
	vector<pair<long long, long long>> path;
	pair<long long,long long> dir[1001][MOD];
	vector<long long> vs;
	int inf[1001];
	long long input;
	long long x;
	long long y;
	long long nx, ny;
	long long cnt;
	long long sol;

	//freopen("input.txt", "r", stdin);
	
	scanf("%lld", &n);

	memset(visited, -1, sizeof(visited));
	memset(inf, -1, sizeof(inf));

	for (i = 1; i <= n; i++)
	{
		scanf("%lld", &input);

		k[i] = (input + (abs(input) + (MOD - 1)) / MOD * MOD) % MOD;
	}

	for (i = 1; i <= n; i++)
	{
		scanf("%lld", &outdeg[i]);

		for (j = 0; j < outdeg[i]; j++)
		{
			scanf("%lld", &edge[i][j]);
		}
	}

	for (i = 1; i <= n; i++)
	{
		for (j = 0; j < MOD; j++)
		{
			dir[i][j] = make_pair(edge[i][(j + k[i]) % outdeg[i]], (j + k[i]) % MOD);
		}
	}

	for (i = 1; i <= n; i++)
	{
		for (j = 0; j < MOD; j++)
		{
			if (visited[i][j] == -1)
			{
				x = i;
				y = j;

				visited[x][y] = i*MOD + j;

				nth[x][y] = 0;

				cnt = 0;

				path.clear();
				vs.clear();

				path.push_back(make_pair(x, y));
				vs.push_back(x);

				inf[x] = i*MOD + j;

				nx = dir[x][y].first;
				ny = dir[x][y].second;

				x = nx;
				y = ny;

				while (visited[x][y] == -1)
				{
					if (x == 3 && y == 2519)
					{
						x = x;
					}

					visited[x][y] = i*MOD + j;

					nth[x][y] = ++cnt;

					path.push_back(make_pair(x, y));
					vs.push_back(x);

					inf[x] = i*MOD + j;

					nx = dir[x][y].first;
					ny = dir[x][y].second;

					x = nx;
					y = ny;
				}

				if (visited[x][y] == i*MOD + j)
				{
					sol = 0;

					for (l = nth[x][y]; l < vs.size(); l++)
					{
						if (inf[vs[l]] == i*MOD + j)
						{
							inf[vs[l]] = -1;

							sol++;
						}
					}
				}

				else
				{
					sol = depth[x][y];
				}

				for (l = 0; l < path.size(); l++)
				{
					depth[path[l].first][path[l].second] = sol;
				}
			}
		}
	}

	scanf("%lld", &q);

	for (i = 0; i < q; i++)
	{
		scanf("%lld %lld", &x, &y);

		y = (y+ (abs(y) + (MOD - 1)) / MOD * MOD) % MOD;

		printf("%lld\n", depth[x][y]);
	}

	return 0;
}