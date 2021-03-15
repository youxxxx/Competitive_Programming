#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<functional>
#include<cstring>

using namespace std;

#define N 200000

int tree[N + 2] = { 0, };

void add(int idx, int val)
{
	for (; idx <= N; idx += idx&(-idx))
	{
		tree[idx] += val;
	}
}

int get(int idx)
{
	int rvalue = 0;

	for (; idx; idx -= idx&(-idx))
	{
		rvalue += tree[idx];
	}

	return rvalue;
}


int main()
{
	//freopen("input.txt", "r", stdin);

	int n, k;

	scanf("%d %d", &n, &k);

	int arr[200001];

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	int median[200001];

	for (int i = 0; i < n; i++)
	{
		add(arr[i], 1);

		int lb = 0, ub = n;

		for (int next = (lb + ub) / 2; ub - lb > 1; next = (lb + ub) / 2)
		{
			if (get(next) < (i + 1) / 2)
			{
				lb = next;
			}

			else
			{
				ub = next;
			}
		}

		median[i] = ub;
	}

	for (int i = 0; i < n; i++)
	{
		add(arr[i], -1);
	}

	for (int i = 0; i < k; i++)
	{
		add(arr[i], 1);
	}

	int lb = 0, ub = n;

	for (int next = (lb + ub) / 2; ub - lb > 1; next = (lb + ub) / 2)
	{
		if (get(next) < (k + 1) / 2)
		{
			lb = next;
		}

		else
		{
			ub = next;
		}
	}

	int sol = ub;
	int cur = 0;

	for (int i = k; i < n; i++)
	{
		while (cur <= i - k && median[cur] <= sol)
		{
			add(arr[cur++], -1);
		}

		add(arr[i], 1);

		int lb = 0, ub = n;

		for (int next = (lb + ub) / 2; ub - lb > 1; next = (lb + ub) / 2)
		{
			if (get(next) < (k + 1) / 2)
			{
				lb = next;
			}

			else
			{
				ub = next;
			}
		}

		sol = max(sol, ub);

		while (cur <= i - k && median[cur] <= sol)
		{
			add(arr[cur++], -1);
		}

		for (int next = (lb + ub) / 2; ub - lb > 1; next = (lb + ub) / 2)
		{
			if (get(next) < (k + 1) / 2)
			{
				lb = next;
			}

			else
			{
				ub = next;
			}
		}

		sol = max(sol, ub);
	}

	printf("%d\n", sol);

	return 0;
}