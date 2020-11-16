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

		scanf("%d", &n);

		int sol = n * 3;

		for (int i = 0; i < sol / 4; i++)
		{
			printf("9");
		}

		const int num[4] = { 8,8,8,8 };

		printf("%d", num[sol % 4]);

		for (int i = 0; i < n - (sol / 4 + 1); i++)
		{
			printf("8");
		}

		printf("\n");
	}

	return 0;
}