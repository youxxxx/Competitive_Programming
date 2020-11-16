#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cstring>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;

		scanf("%d", &n);

		map<int, int> list;

		int cnt[200001];

		for (int i = 1; i <= n; i++)
		{
			cnt[i] = 0;
		}

		for (int i = 0; i < n; i++)
		{
			int input;

			scanf("%d", &input);

			cnt[input]++;
		}

		int sol = 0;
		int left = 0;

		for (int i = 1; i <= n; i++)
		{
			sol += (left + cnt[i]) / i;
			left = (left + cnt[i]) % i;
		}

		printf("%d\n", sol);
	}

	return 0;
}