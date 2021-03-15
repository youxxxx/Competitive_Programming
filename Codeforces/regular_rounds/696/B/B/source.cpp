#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<functional>
#include<cstring>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	vector<int> prime = { 2 };

	for (int i = 3; i < 20200; i += 2)
	{
		bool isprime = true;

		for (int j = 0; prime[j] * prime[j] <= i; j++)
		{
			if (!(i%prime[j]))
			{
				isprime = false;

				break;
			}
		}

		if (isprime)
		{
			prime.push_back(i);
		}
	}

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;

		scanf("%d", &n);

		vector<int>::iterator ret = upper_bound(prime.begin(), prime.end(), n);

		int lb = ret - prime.begin();
		int ub = prime.size();

		for (int next = (lb + ub) / 2; ub - lb > 1; next = (lb + ub) / 2)
		{
			if (prime[next] - *ret >= n)
			{
				ub = next;
			}

			else
			{
				lb = next;
			}
		}

		printf("%lld\n", (long long)*ret*(long long)prime[ub]);
	}

	return 0;
}