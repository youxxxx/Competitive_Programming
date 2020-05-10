#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>

#define MOD 1000000007

using namespace std;

int arr[300000][8];
int n, m;
int a, b;

void bin_search(int lb, int ub)
{
	int pos[256];

	if (ub - lb < 2)
	{
		return;
	}

	int next;

	next = (lb + ub) / 2;

	memset(pos, -1, sizeof(pos));

	for (int i = 0; i < n; i++)
	{
		int mask = 0;

		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] >= next)
			{
				mask |= 1 << j;
			}
		}

		pos[mask] = i;
	}

	for (int i = (1 << m) - 1; i >= 0; i--)
	{
		if (pos[i] != -1)
		{
			for (int j = 0; j < m; j++)
			{
				pos[i&(~(1 << j))] = pos[i];
			}
		}
	}

	bool valid = false;

	for (int i = 0; i < (1 << m); i++)
	{
		if (pos[i] != -1)
		{
			int another;

			another = ~i&((1 << m) - 1);

			if (pos[~i&((1 << m) - 1)] != -1)
			{
				a = pos[i];
				b = pos[another];

				valid = true;
				break;
			}
		}
	}

	if (valid)
	{
		bin_search(next, ub);
	}

	else
	{
		bin_search(lb, next);
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);

	scanf("%lld %lld", &n, &m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	if (n == 1)
	{
		printf("1 1\n");

		return 0;
	}

	bin_search(0, 1000000001);

	printf("%d %d\n", a + 1, b + 1);

	return 0;
}