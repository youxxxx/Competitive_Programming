#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		long long a, b;

		long long digits;

		scanf("%lld %lld", &a, &b);

		digits = (long long)log10(b + 1);

		printf("%lld\n", a*digits);
	}

	return 0;
}