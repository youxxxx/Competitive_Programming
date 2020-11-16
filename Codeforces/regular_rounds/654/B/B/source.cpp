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
		long long n, r;

		scanf("%lld %lld", &n, &r);

		long long sol = 0;

		if (r >= n)
		{
			sol = 1;

			r = n - 1;
		}

		sol += r*(r + 1) / 2;

		printf("%lld\n", sol);
	}

	return 0;
}