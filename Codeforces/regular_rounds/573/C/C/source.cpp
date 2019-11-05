#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	long long n, m, k;
	long long i, j;
	long long prev = -1, cur;
	long long input;
	long long sol = 0;

	scanf("%lld %lld %lld", &n, &m, &k);

	scanf("%lld", &input);

	for (i = 0; i < m; i++)
	{
		sol++;

		prev = (input - i - 1) / k;

		j = 0;

		while (j + i + 1 < m)
		{
			scanf("%lld", &input);

			j++;

			cur = (input - i - 1) / k;

			if (cur != prev)
			{
				break;
			}
		}

		if (j + i + 1 == m)
		{
			sol += (cur != prev);

			break;
		}

		i += j - 1;
	}

	printf("%lld\n", sol + !sol);

	return 0;
}