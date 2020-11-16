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

		int arr[1001];

		scanf("%d %d", &n, &k);

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
		}

		sort(&arr[0], &arr[n]);

		int sol = 0;

		for (int i = 1; i < n; i++)
		{
			sol += (k - arr[i]) / arr[0];
		}

		printf("%d\n", sol);
	}

	return 0;
}