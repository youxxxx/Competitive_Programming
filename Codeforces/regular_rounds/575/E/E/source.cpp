#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int cases, tc;
	int n, m;
	int i, j;
	int ub;
	int odd, temp;
	pair<int, int> add[5];
	int cnt;

	//freopen("input.txt", "r", stdin);

	scanf("%d", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		scanf("%d %d", &n, &m);

		add[0] = make_pair(0, 2);
		add[1] = make_pair(-1, 2);
		add[2] = make_pair(0, 1);
		add[3] = make_pair(0, 3);
		add[4] = make_pair(1, 2);

		if (m < n)
		{
			temp = m;
			m = n;
			n = temp;

			odd = 0;
		}

		else
		{
			odd = 1;
		}

		if (m > n * 3 + 1)
		{
			printf("NO\n");

			continue;
		}

		printf("YES\n");

		if (n == 1)
		{
			for (i = 0; i < m + 1; i++)
			{
				printf("%d %d\n", add[i].first + 2, add[i].second + odd);
			}

			continue;
		}

		cnt = 0;

		for (i = 1; i <= m / 3; i++)
		{
			for (j = 0; j < 4; j++)
			{
				printf("%d %d\n", i * 2 + add[j].first, add[j].second + odd);
			}
		}

		if (m % 3 == 1)
		{
			printf("%d %d\n", m / 3 * 2 + 1, 2 + odd);
		}

		else if (m % 3 > 1)
		{
			for (i = 0; i < m % 3 + 1; i++)
			{
				printf("%d %d\n", (m / 3 + 1) * 2 + add[i].first, add[i].second + odd);
			}
		}

		for (i = 1; i <= (n - m / 3 - (m % 3 > 1)) / 2; i++)
		{
			printf("%d %d\n", i * 2 - 1, 1 + odd);
			printf("%d %d\n", i * 2 - 1, 3 + odd);
		}

		if ((n - m / 3 - (m % 3 > 1)) % 2)
		{
			printf("%d %d\n", i * 2 - 1, 1 + odd);
		}
	}

	return 0;
} 