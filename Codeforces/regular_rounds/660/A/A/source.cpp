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

		if (n <= 30)
		{
			printf("NO\n");

			continue;
		}

		printf("YES\n");

		if (n == 36 || n == 40 || n == 44)
		{
			printf("6 10 15 %d\n", n - 31);
		}

		else
		{
			printf("6 10 14 %d\n", n - 30);
		}
	}

	return 0;
}