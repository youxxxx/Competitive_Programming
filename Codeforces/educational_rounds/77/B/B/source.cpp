#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		long long a, b;

		scanf("%lld %lld", &a, &b);

		if (a > b)
		{
			long long temp;

			temp = a;
			a = b;
			b = temp;
		}

		if (!((a + b) % 3) && a >= b / 2)
		{
			printf("YES\n");
		}

		else
		{
			printf("NO\n");
		}
	}

	return 0;
}