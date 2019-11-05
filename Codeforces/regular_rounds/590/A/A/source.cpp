#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int tc, cases;
	long long n;
	long long sum;
	long long i;
	long long input;

	scanf("%d", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		scanf("%lld", &n);
		
		sum = 0;

		for (i = 0; i < n; i++)
		{
			scanf("%lld", &input);

			sum += input;
		}

		printf("%lld\n", (sum + n - 1) / n);
	}

	return 0;
}