#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cstring>

using namespace std;

int main()
{
	int n;
	long long m;

	scanf("%lld %d", &m, &n);

	long long sum = 0;

	for (int i = 0; i < n; i++)
	{
		long long input;

		scanf("%lld", &input);

		sum += input;
	}

	if (m >= sum)
	{
		printf("%lld\n", m - sum);
	}

	else
	{
		printf("-1\n");
	}

	return 0;
}