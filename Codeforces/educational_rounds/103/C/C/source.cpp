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
		
		scanf("%d", &n);

		long long a[100001];
		long long b[100001];
		long long c[100001];

		for (int i = 0; i < n; i++)
		{
			scanf("%lld", &c[i]);
		}

		for (int i = 0; i < n; i++)
		{
			scanf("%lld", &a[i]);
		}

		for (int i = 0; i < n; i++)
		{
			scanf("%lld", &b[i]);
		}

		long long cur = abs(a[1] - b[1]) + 1;

		long long sol = cur + c[1];

		for (int i = 1; i < n - 1; i++)
		{
			long long next = 0;

			if (a[i + 1] != b[i + 1])
			{
				next = cur + (c[i] - abs(b[i + 1] - a[i + 1]) + 1);
			}

			next = max(next, abs(a[i + 1] - b[i + 1]) + 1);

			sol = max(sol, next + c[i + 1]);

			cur = next;
		}

		printf("%lld\n", sol);
	}

	return 0;
}