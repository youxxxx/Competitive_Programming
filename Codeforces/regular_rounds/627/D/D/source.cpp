#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>
#include<cstring>
#include<map>
#include<set>
#include<stack>

using namespace std;

int main()
{
	long long n;
	long long arr[200001];

	scanf("%lld", &n);

	for (long long i = 0; i < n; i++)
	{
		scanf("%lld", &arr[i]);
	}

	for (long long i = 0; i < n; i++)
	{
		long long input;

		scanf("%lld", &input);

		arr[i] -= input;
	}

	sort(&arr[0], &arr[n]);

	long long ptr = n - 1;
	long long sol = 0;

	for (long long i = 0; i < n - 1; i++)
	{
		while (ptr > 0  && arr[ptr] + arr[i] > 0)
		{
			ptr--;
		}

		sol += n - 1 - (ptr > i ? ptr : i);
	}

	printf("%lld\n", sol);

	return 0;
}
