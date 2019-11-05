#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int tc, cases;
	long long a, b, n, s;

	scanf("%d", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		scanf("%lld %lld %lld %lld", &a, &b, &n, &s);

		if (b < n - 1)
		{
			if (s%n > b)
			{
				printf("NO\n");

				continue;
			}
		}

		if (s>a*n+b)
		{
			printf("NO\n");

			continue;
		}

		printf("YES\n");
	}

	return 0;
}