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
		int arr[51];

		scanf("%d", &n);

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
		}

		int sol = 0;

		for (int i = 0; i < n - 1; i++)
		{
			int lmax = max(arr[i], arr[i + 1]);
			int lmin = min(arr[i], arr[i + 1]);

			while (lmin * 2 < lmax)
			{
				lmin *= 2;

				sol++;
			}
		}

		printf("%d\n", sol);
	}

	return 0;
}