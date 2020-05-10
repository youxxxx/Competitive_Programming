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
	int cases;

	scanf("%d", &cases);

	for (long long tc = 0; tc < cases; tc++)
	{
		long long n, k;

		scanf("%lld %lld", &n, &k);

		long long lb;

		lb = (long long)sqrt((double)k) - 1;

		if (lb < 0)
		{
			lb = 0;
		}

		long long q,r;

		for (long long i = lb; ; i++)
		{
			long long cur;
			long long next;

			cur = i*(i + 1) / 2;
			next = (i + 1)*(i + 2) / 2;

			if (next >= k)
			{
				q = i;
				r = k - 1 - cur;

				break;
			}
		}

		string sol;

		for (long long i = 0; i < n; i++)
		{
			sol.push_back('a');
		}

		sol[n - q - 2] = 'b';
		sol[n - r - 1] = 'b';

		printf("%s\n", sol.c_str());
	}

	return 0;
}