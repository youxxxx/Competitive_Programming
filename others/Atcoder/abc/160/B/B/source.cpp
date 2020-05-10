#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<cstring>
#include<functional>

using namespace std;

int main()
{
	long long k;
	int n;

	scanf("%lld %d", &k, &n);

	long long sol = 0;
	long long lmax = 0;
	long long first;

	scanf("%lld", &first);

	long long prev;
	prev = first;
	long long input;

	for (int i = 0; i < n - 1; i++)
	{
		scanf("%lld", &input);

		sol += input - prev;

		if (input - prev > lmax)
		{
			lmax = input - prev;
		}

		prev = input;
	}

	sol += first + k - input;

	if (first + k - input > lmax)
	{
		lmax = first + k - input;
	}

	sol -= lmax;

	printf("%lld\n", sol);

	return 0;
}