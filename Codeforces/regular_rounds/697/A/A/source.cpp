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
		long long n;

		scanf("%lld", &n);

		while (!(n % 2))
		{
			n /= 2;
		}

		if (n == 1)
		{
			printf("NO\n");
		}

		else
		{
			printf("YES\n");
		}
	}

	return 0;
}