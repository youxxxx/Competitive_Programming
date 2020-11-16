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

	const int ub = (int)sqrt(1000000000);

	vector<int> prime = { 2 };

	for (int i = 3; i <= ub; i++)
	{
		bool isprime = true;

		for (int j = 0; j < prime.size() && prime[j] * prime[j] <= i; j++)
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

		int divd = -1;

		for (int i = 0; i < prime.size() && prime[i]*prime[i] <= n; i++)
		{
			if (!(n%prime[i]))
			{
				divd = prime[i];
				
				break;
			}
		}

		if (divd == -1)
		{
			printf("%d %d\n", 1, n - 1);
		}

		else
		{
			printf("%d %d\n", n / divd, n - n / divd);
		}
	}

	return 0;
}