#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<functional>

using namespace std;

int main()
{
	int n, k;
	string str;
	vector<string> arr;
	char input[3000];
	int i, j;
	int rs[2000], re[2000];
	int cs[2000], ce[2000];
	int ers[2000], ere[2000];
	int ecs[2000], ece[2000];
	int rmax[2000][2000], cmax[2000][2000];
	int cur = 0, ccur = 0,lmax = 0;
	priority_queue<int, vector<int>, greater<int>> sq, csq;
	priority_queue<int, vector<int>, greater<int>> eq, ceq;

	//freopen("input.txt", "r", stdin);

	scanf("%d %d", &n, &k);

	memset(rs, -1, sizeof(rs));
	memset(cs, -1, sizeof(cs));
	memset(ers, -1, sizeof(ers));
	memset(ecs, -1, sizeof(ecs));
	memset(ere, -1, sizeof(ere));
	memset(ece, -1, sizeof(ece));

	for (i = 0; i < n; i++)
	{
		scanf("%s", input);

		str = input;

		arr.push_back(input);
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (arr[i][j] == 'B')
			{
				if (rs[i] == -1)
				{
					rs[i] = j;
				}

				re[i] = j;
			}
		}

		if (rs[i] != -1 && re[i] - rs[i] < k)
		{
			ers[i] = re[i] - (k - 1) > 0 ? re[i] - (k - 1) : 0;
			ere[i] = rs[i] < n - k ? rs[i] : n - k;

			ere[i]++;
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (arr[j][i] == 'B')
			{
				if (cs[i] == -1)
				{
					cs[i] = j;
				}

				ce[i] = j;
			}
		}

		if (cs[i] != -1 && ce[i] - cs[i] < k)
		{
			ecs[i] = ce[i] - (k - 1) > 0 ? ce[i] - (k - 1) : 0;
			ece[i] = cs[i] < n - k ? cs[i] : n - k;

			ece[i]++;
		}
	}

	for (i = 0; i < k; i++)
	{
		if (ecs[i] == 0 && ecs[i] != -1)
		{
			cur++;
			ccur++;

			eq.push(ece[i]);
		}

		else if(ecs[i] != -1)
		{
			sq.push(ecs[i]);

			eq.push(ece[i]);
		}
	}

	cmax[0][0] = cur;

	for (j = k; j < n; j++)
	{
		if (ecs[j - k] == 0 && ecs[j - k] != -1)
		{
			cur--;
		}

		if (ecs[j] == 0 && ecs[j] != -1)
		{
			cur++;
		}

		cmax[0][j - k + 1] = cur;
	}

	for (i = k; i < n; i++)
	{
		while (!eq.empty() && eq.top() == i - k + 1)
		{
			eq.pop();

			ccur--;
		}

		while (!sq.empty() && sq.top() == i - k + 1)
		{
			sq.pop();

			ccur++;
		}

		cur = ccur;

		cmax[i - k + 1][0] = cur;

		for (j = k; j < n; j++)
		{
			if (ecs[j - k] != -1 && i - k + 1 >= ecs[j - k] && i - k + 1 < ece[j - k])
			{
				cur--;
			}

			if (ecs[j] != -1 && i - k + 1 >= ecs[j] && i - k + 1 < ece[j])
			{
				cur++;
			}

			cmax[i - k + 1][j - k + 1] = cur;
		}
	}

	cur = ccur = 0;

	while (!sq.empty())
	{
		sq.pop();
	}

	while (!eq.empty())
	{
		eq.pop();
	}

	for (i = 0; i < k; i++)
	{
		if (ers[i] == 0 && ers[i] != -1)
		{
			cur++;
			ccur++;

			eq.push(ere[i]);
		}

		else if(ers[i] != -1)
		{
			sq.push(ers[i]);

			eq.push(ere[i]);
		}
	}

	rmax[0][0] = cur;

	for (j = k; j < n; j++)
	{
		if (ers[j - k] == 0 && ers[j - k] != -1)
		{
			cur--;
		}

		if (ers[j] == 0 && ers[j] != -1)
		{
			cur++;
		}

		rmax[j - k + 1][0] = cur;
	}

	for (i = k; i < n; i++)
	{
		while (!eq.empty() && eq.top() == i - k + 1)
		{
			eq.pop();

			ccur--;
		}

		while (!sq.empty() && sq.top() == i - k + 1)
		{
			sq.pop();

			ccur++;
		}

		cur = ccur;

		rmax[0][i - k + 1] = cur;

		for (j = k; j < n; j++)
		{
			if (ers[j - k] != -1 && i - k + 1 >= ers[j - k] && i - k + 1 < ere[j - k])
			{
				cur--;
			}

			if (ers[j] != -1 && i - k + 1 >= ers[j] && i - k + 1 < ere[j])
			{
				cur++;
			}

			rmax[j - k + 1][i - k + 1] = cur;
		}
	}
	
	for (i = 0; i <= n - k; i++)
	{
		for (j = 0; j <= n - k; j++)
		{
			if (cmax[i][j] + rmax[i][j] > lmax)
			{
				lmax = cmax[i][j] + rmax[i][j];
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (arr[i][j] == 'B')
			{
				break;
			}
		}

		if (j == n)
		{
			lmax++;
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (arr[j][i] == 'B')
			{
				break;
			}
		}

		if (j == n)
		{
			lmax++;
		}
	}

	printf("%d\n", lmax);

	return 0;
}