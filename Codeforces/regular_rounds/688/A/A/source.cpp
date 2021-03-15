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

		int cnt[101] = { 0, };

		for (int i = 0; i < n; i++)
		{
			int input;

			scanf("%d", &input);

			cnt[input]++;
		}

		for (int i = 0; i < m; i++)
		{
			int input;

			scanf("%d", &input);

			cnt[input]++;
		}

		int sol = 0;

		for (int i = 1; i <= 100; i++)
		{
			sol += cnt[i] / 2;
		}

		printf("%d\n", sol);
	}

	return 0;
}