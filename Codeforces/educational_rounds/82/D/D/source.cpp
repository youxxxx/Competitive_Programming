#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		long long n, m;

		scanf("%lld %lld", &n, &m);

		long long boxes[61] = { 0, };
		long long sum = 0;

		for (long long i = 0; i < m; i++)
		{
			long long input;

			scanf("%lld", &input);

			boxes[(long long)log2(input)]++;

			sum += input;
		}

		if (sum < n)
		{
			printf("-1\n");

			continue;
		}

		long long bit = 1;

		bool valid = true;

		long long cnt = 0;

		for (long long i = 0; i <= 60; i++)
		{
			if (n&bit)
			{
				if (boxes[i])
				{
					boxes[i]--;
				}

				else
				{
					long long target = -1;

					for (long long j = i + 1; j <= 60; j++)
					{
						if (boxes[j])
						{
							target = j;

							break;
						}
					}

					if (target == -1)
					{
						valid = false;

						break;
					}
					
					for (long long j = target; j >= i + 1; j--)
					{
						boxes[j]--;

						boxes[j - 1] += 2;

						cnt++;
					}

					boxes[i]--;
				}
			}
			
			boxes[i + 1] += boxes[i] / 2;

			bit <<= 1;
		}

		if (!valid)
		{
			printf("-1\n");
		}

		else
		{
			printf("%lld\n", cnt);
		}
	}

	return 0;
}