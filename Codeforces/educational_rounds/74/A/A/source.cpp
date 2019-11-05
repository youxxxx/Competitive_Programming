#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int tc, cases;
	int n;
	long long a, b;

	scanf("%d", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		scanf("%lld %lld", &a, &b);

		if (a < b || a - b == 1)
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