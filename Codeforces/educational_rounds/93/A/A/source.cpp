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
		int n;

		scanf("%d", &n);

		long long arr[500001];

		for (int i = 0; i < n; i++)
		{
			scanf("%lld", &arr[i]);
		}

		if (arr[0] + arr[1] <= arr[n - 1])
		{
			printf("1 2 %d\n", n);
		}

		else
		{
			printf("-1\n");
		}
	}

	return 0;
}