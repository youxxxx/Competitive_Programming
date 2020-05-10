#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<cstring>
#include<functional>

using namespace std;

int main()
{
	int n;

	scanf("%d", &n);

	int arr[20][20];

	arr[0][0] = arr[1][1] = (int)pow(2.0, 18) - 1;
	arr[0][1] = (int)pow(2.0, 17);
	arr[1][0] = n;
	arr[2][0] = 0;
	arr[2][1] = (int)pow(2.0, 17) - 1;

	printf("3 2\n");

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("%d ", arr[i][j]);
		}

		printf("\n");
	}

	return 0;
}