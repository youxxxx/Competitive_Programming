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

		vector<pair<int, int>> sol;

		scanf("%d", &n);

		printf("2\n");

		int arr[200001];

		for (int i = 1; i <= n; i++)
		{
			arr[i] = i;
		}

		for (int i = n; i >= 2; i--)
		{
			if (i==2 || arr[i - 1] % 2 == arr[i] % 2)
			{
				printf("%d %d\n", arr[i - 1], arr[i]);

				arr[i - 1] = (arr[i - 1] + arr[i]) / 2;

				continue;
			}

			printf("%d %d\n", arr[i - 2], arr[i]);

			arr[i - 2] = (arr[i - 2] + arr[i]) / 2;
		}
	}

	return 0;
}