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

		int arr[301];

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
		}

		for (int i = 0; i < n / 2; i++)
		{
			printf("%d %d ", arr[i], arr[n - 1 - i]);
		}

		if (n % 2)
		{
			printf("%d", arr[n / 2]);
		}

		printf("\n");
	}

	return 0;
}