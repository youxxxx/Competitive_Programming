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

		long long x[1001], y[1001];

		for (int i = 0; i < n; i++)
		{
			long long a, b;

			scanf("%lld %lld", &x[i], &y[i]);
		}

		if (n % 2)
		{
			printf("1\n");

			continue;
		} 

		sort(&x[0], &x[n]);
		sort(&y[0], &y[n]);

		printf("%lld\n", (x[n / 2] - x[n / 2 - 1] + 1)*(y[n / 2] - y[n / 2 - 1] + 1));
	}

	return 0;
}