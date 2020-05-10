#include<cstdio>
#include<cmath>
#include<vector>

using namespace std;

int main()
{
	int n;
	vector<long long> prime, a, b;
	int t, z;
	int i, j, lim;
	long long prod, input, off, part;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%d", &n);

		prod = 1;

		for (i = 0; i < n; i++)
		{
			scanf("%lld", &input);

			prime.push_back(input);
		}

		for (i = 0; i < n; i++)
		{
			scanf("%lld", &input);

			a.push_back(input);
		}

		for (i = 0; i < n; i++)
		{
			scanf("%lld", &input);

			b.push_back(input);
		}

		for (i = 0; i < n; i++)
		{
			//off = (long long)pow((double)prime[i], a[i] - b[i] + 1) - 1;

			//off /= prime[i] - 1;

			off = 0;
			part = 1;

			if (a[i] - b[i])
			{
				lim = (a[i] - b[i] + 1);

				while (lim)
				{
					part = 1;

					for (j = 2; j <= lim; j *= 2)
					{
						part = ((part*(prime[i] - 1) + 2)*part) % 1000000007;
					}

					j /= 2;

					lim -= j;

					off = (off + (part*(long long)pow((double)prime[i], lim)) % 1000000007) % 1000000007;

					//off = (off + ((long long)pow((double)prime[i], (a[i] - b[i] + 1 - j) - 1)) % 1000000007) % 1000000007;
				}
			}

			else
			{
				off = 1;
			}

			prod = (prod * (off % 1000000007)) % 1000000007;

			prod = (prod * ((long long)pow((double)prime[i], b[i]) % 1000000007)) % 1000000007;
		}

		printf("%lld\n", prod);

		prime.clear();
		a.clear();
		b.clear();
	}

	return 0;
}