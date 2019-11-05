#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	bool **a;
	int n, m;
	int input;
	bool tar;
	int i, j;
	int cnt = 0;

	freopen("input.txt", "r", stdin);

	scanf("%d %d", &n, &m);

	a = new bool*[n];

	for (i = 0; i < n; i++)
	{
		a[i] = new bool[m];

		for (j = 0; j < m; j++)
		{
			scanf("%d", &input);

			tar = (bool)input;

			a[i][j] = tar;
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &input);

			tar = (bool)input;

			cnt += (a[i][j] && !tar || !a[i][j] && tar);
		}
	}

	if (cnt % 2)
	{
		printf("No\n");
	}

	else
	{
		printf("Yes\n");
	}

	return 0;
}