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

		long long arr[51];
		long long sum[2] = { 0, };

		for (int i = 0; i < n; i++)
		{
			scanf("%lld", &arr[i]);

			sum[i % 2] += arr[i];
		}

		int bit = 0;

		if (sum[0] > sum[1])
		{
			bit = 1;
		}

		for (int i = bit; i < n; i += 2)
		{
			arr[i] = 1;
		}

		for (int i = 0; i < n; i++)
		{
			printf("%lld ", arr[i]);
		}

		printf("\n");
	}

	return 0;
}