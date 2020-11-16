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
		int x, y, n;

		scanf("%d %d %d", &x, &y, &n);

		int q, r;

		q = n / x;
		r = n%x;

		if (y <= r)
		{
			printf("%d\n", q * x + y);
		}

		else
		{
			printf("%d\n", (q - 1)*x + y);
		}
	}

	return 0;
}