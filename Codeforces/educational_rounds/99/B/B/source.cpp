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

		int sol = 2000;

		for (int i = 1; i <= 2000; i++)
		{
			if (n == i*(i + 1) / 2)
			{
				sol = i;

				break;
			}

			if (n < i*(i + 1) / 2 - 1)
			{
				sol = i;

				break;
			}
		}

		printf("%d\n", sol);
	}

	return 0;
}