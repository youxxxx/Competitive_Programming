#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<functional>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		long long n;
		long long sum = 0;
		long long lmax = 0;

		scanf("%lld", &n);

		for (long long i = 0; i < n; i++)
		{
			long long input;

			scanf("%lld", &input);

			lmax = max(lmax, input);

			sum += input;
		}

		long long sol;

		if (sum < lmax*(n - 1))
		{
			sol = lmax*(n - 1) - sum;
		}

		else
		{
			sol = ((n - 1) - sum % (n - 1)) % (n - 1);
		}

		printf("%lld\n", sol);
	}

	return 0;
}