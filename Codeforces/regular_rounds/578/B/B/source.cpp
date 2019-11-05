#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	long long tc, cases;
	long long n, m, k;
	long long cur;
	long long col[100];
	long long i;
	long long diff, val;

	scanf("%lld", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		scanf("%lld %lld %lld", &n, &m, &k);

		for (i = 0; i < n; i++)
		{
			scanf("%lld", &col[i]);
		}

		cur = m;

		for (i = 0; i < n - 1; i++)
		{
			diff = col[i + 1] - col[i];

			if (col[i + 1] < col[i])
			{
				val = 0 > col[i + 1] - k ? 0 : col[i + 1] - k;

				m += col[i] - val;
			}

			else
			{
				if (col[i + 1] - col[i] < k)
				{
					val = 0 > col[i + 1] - k ? 0 : col[i + 1] - k;

					m += col[i] - val;
				}

				else if (col[i + 1] - col[i] > k)
				{
					if (col[i + 1] - col[i] - k <= m)
					{
						m -= col[i + 1] - col[i] - k;
					}

					else
					{
						break;
					}
				}
			}
		}

		if (i == n - 1)
		{
			printf("YES\n");
		}

		else
		{
			printf("NO\n");
		}
	}

	return 0;
}