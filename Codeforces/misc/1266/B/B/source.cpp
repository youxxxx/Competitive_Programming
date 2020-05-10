#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	long long n;

	scanf("%lld", &n);

	for (long long i = 0; i < n; i++)
	{
		long long val;

		scanf("%lld", &val);

		long long q, r;

		q = val / 14;
		r = val % 14;

		if (q&&r >= 1 && r <= 6)
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