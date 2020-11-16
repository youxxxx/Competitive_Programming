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
		long long a, b, n, m;

		scanf("%lld %lld %lld %lld", &a, &b, &n, &m);

		if (a + b < n + m)
		{
			printf("No\n");

			continue;
		}

		long long l = a < b ? a : b;

		if (l >= m)
		{
			printf("Yes\n");
		}

		else
		{
			printf("No\n");
		}
	}

	return 0;
}