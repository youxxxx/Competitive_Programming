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

		scanf("%d", &n);

		int cur = 0;

		int amax = 0;

		for (int i = 0; i < n; i++)
		{
			int input;

			scanf("%d", &input);
			cur += input;
			amax = max(amax, cur);
		}

		cur = 0;

		scanf("%d", &m);

		int bmax = 0;

		for (int i = 0; i < m; i++)
		{
			int input;

			scanf("%d", &input);
			cur += input;
			bmax = max(bmax, cur);
		}

		printf("%d\n", amax + bmax);
	}

	return 0;
}