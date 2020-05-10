#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		long long n;

		scanf("%lld", &n);

		long long sum = 0;

		while (n >= 10)
		{
			sum += n / 10 * 10;

			n = n / 10 + n % 10;
		}

		sum += n;

		printf("%lld\n", sum);
	}

	return 0;
}