#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<functional>

using namespace std;

int main()
{
	vector<int> arr, list;
	int n, m, qr;
	int i, j;
	int *next, *lmin, *prev, *bound;
	int *stk, *visited, *last;
	int input, input2;
	//queue<pair<int, int>> *q;
	pair<int, int> cur;
	int curmin;
	int idx = 0;
	int ub = 0;

	//freopen("input.txt", "r", stdin);

	scanf("%d %d %d", &n, &m, &qr);

	next = new int[m + 1];
	prev = new int[m + 1];
	bound = new int[m + 1];
	stk = new int[n + 1];
	visited = new int[n + 1];
	last = new int[n + 1];
	//q = new queue<pair<int,int>>[n + 1];

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		arr.push_back(input);

		stk[i] = -1;

		visited[i] = -1;

		last[i] = -1;

		bound[i] = -1;
	}

	stk[n] = last[n] = bound[n] = -1;

	for (i = 0; i < n; i++)
	{
		prev[arr[i]] = arr[(i + n - 1) % n];
		next[arr[i]] = arr[(i + 1) % n];
	}

	if (n == 1)
	{
		for (i = 0; i < qr; i++)
		{
			scanf("%d %d", &input, &input2);

			printf("1");
		}

		return 0;
	}

	lmin = new int[m + 1];

	for (i = 0; i < m; i++)
	{
		scanf("%d", &input);

		list.push_back(input);

		stk[i] = -1;

		lmin[i] = -1;
	}
	/*
	q[next[list[0]]].push(pair<int, int>(0, 1));

	for (i = 1; i < m; i++)
	{
		while (!q[list[i]].empty())
		{
			cur = q[list[i]].front();
			q[list[i]].pop();

			if (cur.second == n - 1)
			{
				stk[cur.first] = i;
			}

			else
			{
				q[next[list[i]]].push(pair<int, int>(cur.first, cur.second + 1));
			}
		}

		q[next[list[i]]].push(pair<int, int>(i, 1));
	}

	//delete[] q;
	*/

	idx = 0;

	for (i = 0; i < m; i++)
	{
		last[list[i]] = i;

		if (stk[prev[list[i]]] == -1)
		{
			visited[list[i]] = idx;

			stk[list[i]] = 1;

			visited[next[list[i]]] = idx;
		}

		else
		{
			stk[list[i]] = stk[prev[list[i]]] + 1;

			if (stk[list[i]] == n)
			{
				ub = last[prev[list[i]]];

				for (j = 0; j < n - 2; j++)
				{
					ub = bound[ub];
				}

				for (j = idx; j <= ub; j++)
				{
					lmin[j] = i;
				}

				idx = j;

				stk[list[i]] = 1;
			}

			visited[next[list[i]]] = idx;

			bound[i] = last[prev[list[i]]];
		}
	}

	delete[] next;
	delete[] prev;
	//delete[] stk;

	/*
	curmin = -1;

	for (i = m - 1; i >= 0; i--)
	{
		if (stk[i] != -1)
		{
			if (stk[i] < curmin || curmin == -1)
			{
				curmin = stk[i];
			}
		}

		lmin[i] = curmin;
	}
	*/

	for (i = 0; i < qr; i++)
	{
		scanf("%d %d", &input, &input2);

		if (lmin[input - 1] != -1 && lmin[input - 1] <= input2 - 1)
		{
			printf("1");
		}

		else
		{
			printf("0");
		}
	}

	delete[] lmin;

	return 0;
}