#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>
#include<cstring>
#include<map>
#include<set>
#include<stack>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;
		int arr[100];
		int lmin = 101;

		scanf("%d", &n);

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);

			if (arr[i] < lmin)
			{
				lmin = arr[i];
			}
		}

		bool valid = true;

		for (int i = 0; i < n; i++)
		{
			if ((arr[i] - lmin) % 2)
			{
				valid = false;

				break;
			}
		}

		if (valid)
		{
			printf("YES\n");
		}

		else
		{
			printf("NO\n");
		}
	}

	return 0;
}