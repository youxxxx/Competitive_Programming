#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int main()
{
	char input[1000001];
	string str;
	long long state[1000001];
	long long n, l, m;

	scanf("%lld %lld %lld", &n, &m, &l);

	scanf("%s", input);
	str = input;

	for (long long i = 0; i < n; i++)
	{
		if (str[i] <= 'Z')
		{
			state[i] = 0;
		}

		else
		{
			state[i] = 1;
		}

	}
	
	if (m*l >= n)
	{
		printf("0\n");

		return 0;
	}

	long long lmin = 1000001;
	long long left = n - m * l;

	map<long long,long long> dp[2][1000001];

	for (long long i = 0; i < 2; i++)
	{
		if (l == 1)
		{
			dp[i][0][0] = 0;
		}

		dp[i][0][1] = (state[0] != i);

		for (long long j = 1; j < n; j++)
		{
			if (n - j >= left && !(j % l))
			{
				dp[i][j][1] = (state[j] != i);
			}

			for (long long k = j - 1; k >= 0; k -= l)
			{
				map<long long, long long>::iterator it, ret, lb;

				lb = dp[i][k].lower_bound(left - (n - j));

				for (it = lb; it != dp[i][k].end(); it++)
				{
					long long nextval, nextidx;

					nextidx = it->first + 1;
					nextval = it->second + (state[j] != i);

					if (nextidx > left)
					{
						break;
					}

					ret = dp[i][j].find(nextidx);

					if (ret==dp[i][j].end())
					{
						dp[i][j][nextidx] = nextval;
					}

					else if (nextval < ret->second)
					{
						ret->second = nextval;
					}

					if (nextidx == left && nextval < lmin)
					{
						lmin = nextval;
					}
				}
			}
		}
	}

	printf("%lld\n", lmin);

	return 0;
} 