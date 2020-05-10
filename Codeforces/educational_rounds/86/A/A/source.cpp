#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cstring>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		long long x, y, a, b;

		scanf("%lld %lld %lld %lld", &x, &y, &a, &b);

		long long sol;

		if (a * 2 <= b)
		{
			sol = (x + y)*a;
		}

		else
		{
			long long lb;

			lb = x < y ? x : y;

			sol = lb*b + (x - lb)*a + (y - lb)*a;
		}

		printf("%lld\n", sol);
	}

	return 0;
}