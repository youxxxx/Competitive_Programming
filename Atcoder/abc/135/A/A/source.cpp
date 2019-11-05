#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	long long a, b;

	scanf("%lld %lld", &a, &b);

	if ((a + b) % 2)
	{
		printf("IMPOSSIBLE\n");
	}

	else
	{
		printf("%lld\n", (a + b) / 2);
	}

	return 0;
}
