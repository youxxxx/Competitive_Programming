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

		int sol = 0;

		for (int i = 1; i <= 9; i++)
		{
			int cur = i;

			int digits = 1;

			while (cur < 10000)
			{
				sol += digits;

				if (cur == n)
				{
					break;
				}

				cur = cur * 10 + i;
				digits++;
			}

			if (cur == n)
			{
				break;
			}
		}

		printf("%d\n", sol);
	}

	return 0;
}