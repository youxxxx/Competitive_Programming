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
		int a, b, c;

		scanf("%d %d %d", &a, &b, &c);

		int n = 1, m = 1;

		while (!(a % 2))
		{
			a /= 2;
			
			n *= 2;
		}

		while (!(b % 2))
		{
			b /= 2;

			m *= 2;
		}

		if (n*m >= c)
		{
			printf("YES\n");
		}

		else
		{
			printf("NO\n");
		}
	}

	return 0;
}