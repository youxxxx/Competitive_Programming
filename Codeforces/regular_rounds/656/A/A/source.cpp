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
		int arr[3];

		for (int i = 0; i < 3; i++)
		{
			scanf("%d", &arr[i]);
		}

		int idx = -1;

		for (int i = 0; i < 3; i++)
		{
			if (arr[i] == arr[(i + 1) % 3] && arr[(i + 2) % 3] <= arr[i])
			{
				idx = i;

				break;
			}
		}

		if (idx == -1)
		{
			printf("NO\n");

			continue;
		}

		printf("YES\n");

		for (int i = 0; i < 3; i++)
		{
			printf("%d ", arr[i] < arr[(i + 2) % 3] ? arr[i] : arr[(i + 2) % 3]);
		}

		printf("\n");
	}

	return 0;
}