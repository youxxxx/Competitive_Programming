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

		int arr[101];

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
		}

		sort(&arr[0], &arr[n]);

		int ptr = n;

		for (int i = 0; i < n - 1; i++)
		{
			if (arr[i] < arr[i + 1])
			{
				ptr = i + 1;

				break;
			}
		}

		printf("%d\n", n - ptr);
	}

	return 0;
}