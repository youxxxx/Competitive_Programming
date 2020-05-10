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
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int arr[9][9];

		for (int i = 0; i < 9; i++)
		{
			char input[10];

			scanf("%s", input);

			for (int j = 0; j < 9; j++)
			{
				arr[i][j] = input[j] - '0';
			}
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				arr[i * 3 + j][j * 3 + i] = arr[i * 3 + j][j * 3 + i] % 9 + 1;
			}
		}

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				printf("%d", arr[i][j]);
			}

			printf("\n");
		}
	}

	return 0;
}