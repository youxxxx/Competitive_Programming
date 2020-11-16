#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
#include<cstring>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n, x;
		int arr[100001];

		scanf("%d", &n);

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
		}

		vector<int> sol;

		sol.push_back(arr[0]);

		for (int i = 1; i < n - 1; i++)
		{
			const int presign = (arr[i - 1] - arr[i]) / abs(arr[i - 1] - arr[i]);
			const int cursign = (arr[i] - arr[i + 1]) / abs(arr[i] - arr[i + 1]);

			if (presign != cursign)
			{
				sol.push_back(arr[i]);
			}
		}

		sol.push_back(arr[n - 1]);

		printf("%d\n", sol.size());

		for (int i = 0; i < sol.size(); i++)
		{
			printf("%d ", sol[i]);
		}

		printf("\n");
	}

	return 0;
}