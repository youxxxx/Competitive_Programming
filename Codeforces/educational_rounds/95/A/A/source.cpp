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

#define MOD 1000000007

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		long long x, y, z;

		scanf("%lld %lld %lld", &x, &y, &z);

		long long sol = z + (z * y + z + (x - 2) - 1) / (x - 1);

		printf("%lld\n", sol);
	}

	return 0;
}