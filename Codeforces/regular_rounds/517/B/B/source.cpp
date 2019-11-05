#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>

using namespace std;

int main()
{
	int n;
	bool **orbit, **andbit;
	bool **realbit;
	bool **visited;
	bool des;
	bool dir;
	bool prevvalue;
	int max = 0;
	int cap;
	int input;
	int i, j;
	int a, b;
	int temp1, temp2;
	vector<int> or, and;
	queue<pair<pair<bool, int>, pair<int, int>>> q;
	pair<pair<bool,bool>,pair<int, int>> cur, next;

	scanf("%d", &n);

	for (i = 0; i < n - 1; i++)
	{
		scanf("%d", &input);

		or.push_back(input);

		if (input > max)
		{
			max = input;
		}
	}

	//cap = (int)(log((double)max) / log(2.0)) + 1;
	cap = 2;

	orbit = new bool*[n];
	andbit = new bool*[n];
	realbit = new bool*[n];
	visited = new bool*[n];

	for (i = 0; i < n; i++)
	{
		orbit[i] = new bool[cap];
		andbit[i] = new bool[cap];
		realbit[i] = new bool[cap];
		visited[i] = new bool[cap];

		for (j = 0; j < cap; j++)
		{
			visited[i][j] = false;
		}
	}

	for (i = 0; i < n - 1; i++)
	{
		scanf("%d", &input);

		and.push_back(input);
	}

	for (i = 0; i < n - 1; i++)
	{
		temp1 = or[i];
		temp2 = and[i];

		for (j = 0; j < cap; j++)
		{
			orbit[i][j] = temp1 % 2;

			temp1 >>= 1;
		}

		for (j = 0; j < cap; j++)
		{
			andbit[i][j] = temp2 % 2;

			temp2 >>= 1;
		}

		for (j = 0; j < cap; j++)
		{
			if (!orbit[i][j] && andbit[i][j])
			{
				printf("NO\n");

				return 0;
			}
		}
	}

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < cap; j++)
		{
			if (!(orbit[i][j] || andbit[i][j])
				|| (orbit[i][j] && andbit[i][j])
				)
			{
				visited[i][j] = true;
			}
			
			if (i > 0)
			{
				if (!(orbit[i][j] || andbit[i][j]) && (orbit[i - 1][j] && andbit[i - 1][j])
					|| !(orbit[i - 1][j] || andbit[i - 1][j]) && (orbit[i][j] && andbit[i][j])
					)
				{
					printf("NO\n");

					return 0;
				}
			}

			if (i < n - 2)
			{
				if (!(orbit[i][j] || andbit[i][j]) && (orbit[i + 1][j] && andbit[i + 1][j])
					|| !(orbit[i + 1][j] || andbit[i + 1][j]) && (orbit[i][j] && andbit[i][j])
					)
				{
					printf("NO\n");

					return 0;
				}
			}
		}
	}

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < cap; j++)
		{
			if (!(orbit[i][j] || andbit[i][j]))
			{
				realbit[i][j] = 0;
				realbit[i+1][j] = 0;

				visited[i][j] = true;

				next.first.first = 0;
				next.second.second = j;

				if (i > 0 && !visited[i - 1][j])
				{
					next.second.first = i - 1;
					next.first.second = 0;

					visited[i - 1][j] = true;

					q.push(next);
				}

				if (i < n - 2 && !visited[i + 1][j])
				{
					next.second.first = i + 1;
					next.first.second = 1;

					visited[i + 1][j] = true;

					q.push(next);
				}
			}

			else if (orbit[i][j] && andbit[i][j])
			{
				realbit[i][j] = 1;
				realbit[i+1][j] = 1;

				visited[i][j] = true;

				next.first.first = 1;
				next.second.second = j;

				if(i > 0 && !visited[i - 1][j])
				{
					next.second.first = i - 1;
					next.first.second = 0;

					visited[i - 1][j] = true;

					q.push(next);
				}

				if (i < n - 2 && !visited[i + 1][j])
				{
					next.second.first = i + 1;
					next.first.second = 1;

					visited[i + 1][j] = true;

					q.push(next);
				}
			}
		}
	}

	while (!q.empty())
	{
		cur = q.front();

		q.pop();

		a = cur.second.first;
		b = cur.second.second;
		des = cur.first.first;
		dir = cur.first.second;
		/*
		if ((des != realbit[a][b])
			|| (des != realbit[a+1][b])
//			|| des != (orbit[a][b] && andbit[a][b])
//			|| des != (orbit[a][b] || andbit[a][b]) 
		)
		{
			printf("NO\n");

			return 0;
		}
		*/
		if (!des)
		{
			realbit[a + dir][b] = !realbit[a + !dir][b];
		}

		else
		{
			realbit[a + dir][b] = !realbit[a + !dir][b];
		}

		next.first.first = !realbit[a + dir][b];
		next.first.second = dir;
		next.second.second = b;

		if (!dir&&a > 0 && !visited[a - 1][b])
		{
			next.second.first = a - 1;

			visited[a - 1][b] = true;

			q.push(next);
		}

		if (dir&&a < n - 2&& !visited[a + 1][b])
		{
			next.second.first = a + 1;

			visited[a + 1][b] = true;

			q.push(next);
		}
	}

	for (j = 0; j < cap; j++)
	{
		prevvalue = false;

		if (!visited[0][j])
		{
			des = 0;

			prevvalue = true;

			realbit[0][j] = des;
		}

		i = 0;

		while (++i < n - 1)
		{
			if (visited[i][j] || visited[i-1][j])
			{
				prevvalue = false;

				continue;
			}

			if (!prevvalue)
			{
				prevvalue = true;

				des = 0;

				realbit[i][j] = des;
			}

			else
			{
				des = !des;

				realbit[i][j] = des;
			}
		}

		if (!visited[n - 2][j])
		{
			realbit[i][j] = !realbit[i - 1][j];
		}
	}

	printf("YES\n");

	for (i = 0; i < n; i++)
	{
		printf("%d ", realbit[i][0] + realbit[i][1] * 2);
	}

	return 0;
}