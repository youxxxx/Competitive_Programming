#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int arr[3];

		for (int i = 0; i < 3; i++)
		{
			scanf("%d", &arr[i]);
		}

		sort(&arr[0], &arr[3]);

		if (arr[2] <= arr[0] + arr[1] + 1)
		{
			printf("Yes\n");
		}

		else
		{
			printf("No\n");
		}
	}

	return 0;
}