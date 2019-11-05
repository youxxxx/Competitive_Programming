#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int n, q;
	int t, z;
	int i, j;
	vector<int> prime;
	int cnt, sol;;

	prime.push_back(2);

	for (i = 3; i <= 3163; i++)
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

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d %d", &n, &q);

		if (n%q)
		{
			printf("0\n");
		}

		else
		{
			n /= q;

			sol = 1;

			for (i = 0; i < prime.size(); i++)
			{
				if (n == 1)
				{
					break;
				}

				cnt = 1;

				while (!(n%prime[i]))
				{
					n /= prime[i];
					cnt++;
				}

				sol *= cnt;
			}

			if (n > 1)
			{
				sol *= 2;
			}

			printf("%d\n", sol);
		}
	}

	return 0;
}