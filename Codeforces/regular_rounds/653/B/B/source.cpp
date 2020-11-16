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
		int two = 0, three = 0;

		scanf("%d", &n);

		while (!(n % 2))
		{
			n /= 2;
			two++;
		}

		while (!(n % 3))
		{
			n /= 3;
			three++;
		}

		if (n != 1 || two > three)
		{
			printf("-1\n");

			continue;
		}

		printf("%d\n", three * 2 - two);
	}

	return 0;
}