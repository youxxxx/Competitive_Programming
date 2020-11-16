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
		int arr[200001];

		scanf("%d", &n);

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
		}

		int idx = 0;

		for (int i = n - 1; i >= 1; i--)
		{
			if (arr[i] > arr[i - 1])
			{
				idx = i;

				break;
			}
		}

		if (idx == 0)
		{
			printf("0\n");

			continue;
		}

		int idx2 = 0;

		for (int i = idx; i >= 1; i--)
		{
			if (arr[i] < arr[i - 1])
			{
				idx2 = i;

				break;
			}
		}

		printf("%d\n", idx2);
	}

	return 0;
}