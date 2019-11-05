#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	long long tc, cases;
	char input[200001];
	string str;
	long long n;
	long long a, b;
	long long sol;
	long long i;
	long long start, end;
	long long zero, len;

	//freopen("input.txt", "r", stdin);

	scanf("%lld", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		scanf("%lld %lld %lld", &n, &a, &b);

		scanf("%s", input);

		str = input;

		sol = a*n + b*(n + 1);

		for (i = 0; i < n; i++)
		{
			if (str[i] == '1')
			{
				break;
			}
		}

		if (i == n)
		{
			printf("%lld\n", sol);

			continue;
		}

		start = i;

		for (i = n - 1; i >= 0; i--)
		{
			if (str[i] == '1')
			{
				break;
			}
		}

		end = i;

		sol += a * 2 + b * (end - start + 2);

		zero = -1;

		for (i = start + 1; i <= end; i++)
		{
			if (str[i] == '0')
			{
				if (zero == -1)
				{
					zero = i;
				}
			}

			else
			{
				if (zero != -1)
				{
					len = i - zero;

					zero = -1;

					if (len >= 2)
					{
						if (a * 2 - b * (len - 1) < 0)
						{
							sol += a * 2 - b * (len - 1);
						}
					}
				}
			}
		}

		printf("%lld\n", sol);
	}

	return 0;
}