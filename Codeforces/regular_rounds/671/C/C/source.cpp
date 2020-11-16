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

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n, m;

		scanf("%d %d", &n, &m);

		bool allsame = true;
		bool same = false;
		int sum = 0;

		for (int i = 0; i < n; i++)
		{
			int input;

			scanf("%d", &input);

			if (input == m)
			{
				same = true;
			}

			else
			{
				allsame = false;
			}

			sum += input;
		}

		if (allsame)
		{
			printf("0\n");

			continue;
		}

		if (same || sum == n*m)
		{
			printf("1\n");

			continue;
		}

		printf("2\n");
	}

	return 0;
}