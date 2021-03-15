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
		long long n;

		scanf("%lld", &n);

		long long arr[200001];
		long long val[200001];

		for (long long i = 1; i <= n; i++)
		{
			scanf("%lld", &arr[i]);

			val[i] = 0;
		}

		long long sol = 0;

		for (long long i = 1; i <= n; i++)
		{
			if (i + arr[i] <= n)
			{
				val[i + arr[i]] = max(val[i + arr[i]], val[i] + arr[i]);
			}

			sol = max(sol, val[i] + arr[i]);
		}

		printf("%lld\n", sol);
	}

	return 0;
}