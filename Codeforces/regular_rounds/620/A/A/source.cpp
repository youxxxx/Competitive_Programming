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

using namespace std;

int main()
{
	long long cases;

	scanf("%lld", &cases);

	for (long long tc = 0; tc < cases; tc++)
	{
		long long x, y, a, b;

		scanf("%lld %lld %lld %lld", &x, &y, &a, &b);

		if (!((y - x) % (a + b)))
		{
			printf("%lld\n", (y - x) / (a + b));
		}

		else
		{
			printf("-1\n");
		}
	}

	return 0;
}