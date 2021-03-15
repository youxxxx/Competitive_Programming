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

		int arr[101];

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
		}

		sort(&arr[0], &arr[n]);

		if (arr[n - 1] > k&&arr[0] + arr[1] > k)
		{
			printf("NO\n");
		}

		else
		{
			printf("YES\n");
		}
	}

	return 0;
}