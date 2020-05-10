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
		int arr[5001];

		scanf("%d", &n);

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
		}

		int left[5001], right[5001];

		memset(left, -1, sizeof(left));
		memset(right, -1, sizeof(right));

		for (int i = 0; i < n; i++)
		{
			if (left[arr[i]] == -1)
			{
				left[arr[i]] = i;
			}
		}

		for (int i = n - 1; i >= 0; i--)
		{
			if (right[arr[i]] == -1)
			{
				right[arr[i]] = i;
			}
		}

		bool found = false;

		for (int i = 1; i <= n; i++)
		{
			if (left[i] < right[i] - 1)
			{
				found = true;

				break;
			}
		}

		if (found)
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