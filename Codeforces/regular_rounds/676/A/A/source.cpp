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
		int a, b;

		int cur = 1;
		int sol = 0;

		scanf("%d %d", &a, &b);

		while (a||b)
		{
			int aval = a % 2;
			int bval = b % 2;

			if (aval && !bval || !aval&&bval)
			{
				sol += cur;
			}

			cur *= 2;

			a /= 2;
			b /= 2;
		}

		printf("%d\n", sol);
	}

	return 0;
}