#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>

#define MOD 998244353

using namespace std;

int main()
{
	long long cnt[3] = { 0, };
	long long n;
	char input[100001];
	string str;
	long long i, j, k;
	long long color, other;
	long long sol = 0, acc = 0, add;
	long long prev = -1;
	long long lmin;
	long long perm[100001];

	perm[1] = 1;

	scanf("%lld", &n);

	for (i = 2; i <= n; i++)
	{
		perm[i] = perm[i - 1];

		for (j = 0; j < 3; j++)
		{
			perm[i] = perm[i] * i%MOD;
		}
	}

	scanf("%s", input);

	str = input;

	for (i = 0; i < 3 * n; i++)
	{
		switch (str[i])
		{
		case 'R':
			color = 0;
			break;
		case 'G':
			color = 1;
			break;
		default:
			color = 2;
			break;
		}

		for (j = 1; j < 3; j++)
		{
			other = (color + j) % 3;

			if (!cnt[other])
			{
				break;
			}
		}

		if (j == 3)
		{
			if (prev != -1 && color != prev)
			{
				sol = (sol + perm[acc]) % MOD;

				acc = 0;
			}

			for (j = 1; j < 3; j++)
			{
				cnt[(color + j) % 3]--;
			}

			acc++;

			prev = color;
		}

		else
		{
			cnt[color]++;
		}
	}

	sol = (sol + perm[acc]) % MOD;

	printf("%lld\n", sol);

	return 0;
}