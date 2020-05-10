#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	long long cases;

	scanf("%lld", &cases);

	for (long long tc = 0; tc < cases; tc++)
	{
		long long n;
		vector<long long> arr;

		scanf("%lld", &n);

		long long sum = 0, xor = 0;

		for (long long i = 0; i < n; i++)
		{
			long long input;

			scanf("%lld", &input);

			arr.push_back(input);

			sum += input;
			xor ^= input;
		}

		if (sum == xor*2)
		{
			printf("0\n\n");

			continue;
		}

		if (xor == 0)
		{
			printf("1\n%lld\n", sum);

			continue;
		}

		long long diff;

		diff = xor * 2 - sum;

		if (diff > 0)
		{
			if (!(diff % 2))
			{
				printf("2\n%lld %lld\n", diff / 2, diff / 2);
			}

			else
			{
				xor--;
				sum++;

				diff = xor * 2 - sum;

				if (diff < 0)
				{
					long long add = 2;

					while (add <= sum)
					{
						add *= 2;
					}

					xor += add;
					sum += add;

					diff = xor * 2 - sum;

					printf("3\n%lld %lld %lld\n", add + 1, diff / 2, diff / 2);
				}

				else
				{
					printf("3\n1 %lld %lld\n", diff / 2, diff / 2);
				}
			}
		}

		else
		{
			long long add = 2;

			while (add <= sum)
			{
				add *= 2;
			}

			xor += add;
			sum += add;

			diff = xor * 2 - sum;

			if (!(diff % 2))
			{
				printf("3\n%lld %lld %lld\n", add, diff / 2, diff / 2);
			}

			else
			{
				xor--;
				sum++;

				diff = xor * 2 - sum;

				printf("3\n%lld %lld %lld\n", add + 1, diff / 2, diff / 2);
			}

		}
	}

	return 0;
}
