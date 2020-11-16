#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
#include<cstring>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	/*
	vector<int> prime = { 2 };

	for (int i = 3; i < 31622; i += 2)
	{
		bool isprime = false;

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
	*/

	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int a, b;

		scanf("%d %d", &a, &b);

		if (b >= a)
		{
			printf("1\n");
		}

		else if (b == 1)
		{
			printf("%d\n", a);
		}

		else
		{
			int sol = a;

			/*
			for (int i = 0; i < prime.size() && prime[i] <= b && prime[i] * prime[i] <= a; i++)
			{
				if (!(a%prime[i]))
				{
					sol = prime[i];

					break;
				}
			}
			*/

			const int ub = (int)sqrt(a);

			for (int i = 2; i <= ub; i++)
			{
				if (!(a%i))
				{
					if (a / i <= b)
					{
						sol = i;

						break;
					}

					if (i <= b)
					{
						sol = a / i;
					}
				}
			}

			printf("%d\n", sol);
		}
	}

	return 0;
}