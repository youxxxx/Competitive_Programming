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
		int n;
		long long k;

		scanf("%d %lld", &n, &k);

		long long sol = 0;

		long long cur;

		scanf("%lld", &cur);

		for (int i = 1; i < n; i++)
		{
			long long inc;

			scanf("%lld", &inc);

			const long long diff = (inc * 100 + k - 1) / k - cur;

			sol += max(diff, 0ll);
			cur += max(diff, 0ll) + inc;
		}

		printf("%lld\n", sol);
	}

	return 0;
}