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
		int arr[3];
		int sum = 0;

		for (int i = 0; i < 3; i++)
		{
			scanf("%d", &arr[i]);

			sum += arr[i];
		}

		sort(&arr[0], &arr[3]);

		if (!(sum % 9) && arr[0] >= sum / 9)
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