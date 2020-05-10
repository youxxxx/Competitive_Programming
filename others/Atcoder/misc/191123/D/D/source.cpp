#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

int main()
{
	long long extra = 0;
	int n;
	long long sum = 0;
	long long totd = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		long long c, d;

		scanf("%lld %lld", &c, &d);

		sum += c*d;

		totd += sum / 10;

		do
		{
			extra = sum / 10;

			sum %= 10;

			sum += extra;

			totd += sum / 10;
		} while (sum >= 10);

		totd += d;
	}

	printf("%lld\n", totd - 1);

 	return 0;
}
