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
		int n, k;

		scanf("%d %d", &n, &k);

		long long arr[200001];

		for (int i = 0; i < n; i++)
		{
			scanf("%lld", &arr[i]);
		}

		if (n == 1)
		{
			printf("0\n");

			continue;
		}

		sort(&arr[0], &arr[n]);

		long long sol = 0;

		for (int i = n - k - 1; i < n; i++)
		{
			sol += arr[i];
		}

		printf("%lld\n", sol);
	}

	return 0;
}