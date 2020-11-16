#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
#include<cstring>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n, m, a, b;

		scanf("%d %d %d %d", &n, &m, &a, &b);

		if (n*a != m*b)
		{
			printf("NO\n");

			continue;
		}

		printf("YES\n");

		vector<int> res;

		for (int i = 0; i < a; i++)
		{
			res.push_back(1);
		}

		for (int i = a; i < m; i++)
		{
			res.push_back(0);
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				printf("%d", res[(j + i * a) % m]);
			}

			printf("\n");
		}
	}

	return 0;
}