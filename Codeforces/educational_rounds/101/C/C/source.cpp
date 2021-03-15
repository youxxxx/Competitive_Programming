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

		int arr[200001];

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
		}

		int lb[2], ub[2];

		lb[0] = ub[0] = arr[0];

		bool valid = true;

		for (int i = 1; i < n - 1; i++)
		{
			lb[i % 2] = arr[i];
			ub[i % 2] = arr[i] + k - 1;

			lb[i % 2] = max(lb[i % 2], lb[!(i % 2)] - (k - 1));
			ub[i % 2] = min(ub[i % 2], ub[!(i % 2)] + (k - 1));

			if (lb[i % 2] > ub[i % 2])
			{
				valid = false;

				break;
			}
		}

		if (!valid || lb[n % 2] - (k - 1) > arr[n - 1] || ub[n % 2] + (k - 1) < arr[n - 1])
		{
			printf("NO\n");

			continue;
		}

		printf("YES\n");
	}

	return 0;
}