#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>

using namespace std;

int main()
{
	int coord[3][2];
	int vec[3][2];

	for (int i = 0; i < 3; i++)
	{
		scanf("%d %d", &coord[i][0], &coord[i][1]);
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			vec[i][j] = coord[(i + 1) % 3][j] - coord[i][j];
		}
	}

	printf("3\n");

	for (int i = 0; i < 3; i++)
	{
		printf("%d %d\n", coord[i][0] - vec[(i + 2) % 3][0] + vec[i][0], coord[i][1] - vec[(i + 2) % 3][1] + vec[i][1]);
	}

	return 0;
}
