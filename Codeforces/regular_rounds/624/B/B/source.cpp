#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int cases;

	//freopen("input.txt", "r", stdin);

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n, m;

		scanf("%d %d", &n, &m);

		int a[101], b[101];

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}

		for (int i = 0; i < m; i++)
		{
			scanf("%d", &b[i]);
		}

		sort(&b[0], &b[m]);

		int start, prev;

		start = prev = b[0];

		for (int i = 1; i < m; i++)
		{
			if (b[i] != prev + 1)
			{
				sort(&a[start - 1], &a[prev + 1]);

				start = b[i];
			}

			prev = b[i];
		}

		sort(&a[start - 1], &a[prev + 1]);

		bool valid = true;

		for (int i = 0; i < n - 1; i++)
		{
			if (a[i] > a[i + 1])
			{
				valid = false;

				break;
			}
		}

		if (valid)
		{
			printf("YES\n");
		}

		else
		{
			printf("NO\n");
		}
	}

	return 0;
}