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

		int arr[300001];
		
		int lmax = 0;
		int midx = -1;

		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &arr[i]);

			lmax = max(lmax, arr[i]);
		}

		for (int i = 1; i <= n; i++)
		{
			if (arr[i] == lmax)
			{
				if (i > 1 && arr[i - 1] != lmax || i < n&&arr[i + 1] != lmax)
				{
					midx = i;

					break;
				}
			}
		}

		printf("%d\n", midx);
	}

	return 0;
}