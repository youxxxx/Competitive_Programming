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

	scanf("%lld", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		long long a, b, c;

		scanf("%lld %lld %lld", &a, &b, &c);

		long long sol1 = -1, sol2 = -1;

		if (a * b < c)
		{
			sol1 = b;
		}

		else if (a < c)
		{
			sol1 = 1;
		}

		if (a*b > c)
		{
			sol2 = b;
		}

		printf("%lld %lld\n", sol1, sol2);
	}

	return 0;
}