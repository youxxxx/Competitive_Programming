#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	long long b;
	long long ub;
	long long sol = 1;
	long long q, mul;
	vector<long long> prime;
	long long n;
	long long i, j;

	scanf("%I64d", &b);

	ub = (long long)sqrt((double)b);

	prime.push_back(2);

	for (i = 3; i <= ub; i++)
	{
		for (j = 0; j < prime.size(); j++)
		{
			if (!(i%prime[j]))
			{
				break;
			}
		}

		if (j == prime.size())
		{
			prime.push_back(i);
		}
	}

	for (i = 0; i < prime.size(); i++)
	{
		j = 0;

		while (!(b%prime[i]))
		{
			j++;

			b /= prime[i];
		}

		sol *= j + 1;
	}

	if (b > 1)
	{
		sol *= 2;
	}

	printf("%I64d\n", sol);

	return 0;
}