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
	long long sol[500001];

	sol[1] = 0;

	for (long long i = 3; i <= 500000; i+=2)
	{
		sol[i] = sol[i - 2] + (i - 1)*(i - 1) * 2;
	}

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;

		scanf("%d", &n);

		printf("%lld\n", sol[n]);
	}

	return 0;
}