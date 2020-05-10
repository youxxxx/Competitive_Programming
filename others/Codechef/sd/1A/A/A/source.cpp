#include<cstdio>
#include<cmath>
#include<vector>

using namespace std;

int main()
{
	vector<pair<int, int>> house;
	char input[301];
	int t, n, m, z;
	int i, j, k, l;
	//int off[300][1200] = { 0, };
	//int **off;
	vector<int> off[300];
	int dis[600] = { 0, };

	scanf("%d", &t);
	/*
	off = new int*[300];

	for (i = 0; i < 300; i++)
	{
		off[i] = new int[1200];

		for (j = 0; j < 1200; j++)
		{
			off[i][j] = 0;
		}
	}
	*/
	for (z = 0; z < t; z++)
	{
		scanf("%d %d", &n, &m);

		for (i = 0; i < m; i++)
		{
			for (j = 0; j < m; j++)
			{
				off[i].push_back(0);
			}
		}

		for (i = 0; i < n; i++)
		{
			scanf("%s", &input);

			for (k = 0; k < m; k++)
			{
				off[k].insert(off[k].begin(), 0);
			}

			for (j = 0; j < m; j++)
			{
				if (input[j] == '1')
				{
					//house.push_back(pair<int, int>(i, j));

					for (k = 0; k < m; k++)
					{
						off[k][abs(j - k)]++;

						//off[k][600 + abs(j - k) - i]++; 

						//dis[abs(j - k)]++;
					}
					
					for (l = 1; l < m + i; l++)
					{
						dis[l] += off[j][l];
					}
				}
			}
		}

		for (i = 1; i <= n + m - 2; i++)
		{
			printf("%d ", dis[i]);

			dis[i] = 0;
		}

		printf("\n");

		for (i = 0; i < 300; i++)
		{
			off[i].clear();
		}

		//house.clear();
	}

	return 0;
}