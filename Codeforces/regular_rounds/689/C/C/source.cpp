#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<functional>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n, m;

		scanf("%d %d", &n, &m);

		int arr[100001];

		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &arr[i]);
		}

		int valid = 0;

		for (int i = n; i >= 1; i--)
		{
			if (arr[i] != i)
			{
				valid = i;

				break;
			}
		}

		double sol = 1.0;

		for (int i = 0; i < m; i++)
		{
			int idx;
			double prob;

			scanf("%d %lf", &idx, &prob);

			if (idx < valid)
			{
				continue;
			}

			sol *= (1.0 - prob);
		}

		if (valid == 0)
		{
			printf("%.8lf\n", 1.0);

			continue;
		}

		printf("%.8lf\n", 1.0 - sol);
	}

	return 0;
}