#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

#define MOD 1000000007;

using namespace std;

int main()
{
	long long base[2], free[2], ext = 0;
	bool zero = 0;
	char input[200000];
	string str;
	int n;
	int i;

	scanf("%s", input);

	str = input;

	n = str.size();

	base[0] = 2;
	free[0] = 1;

	for (i = 1; i < n; i++)
	{
		if (str[i] == '1')
		{
			base[i % 2] = base[!(i % 2)];

			if (zero)
			{
				ext = (ext + free[!(i % 2)]) % MOD;
				free[i % 2] = (free[!(i % 2)] * 3) % MOD;
			}

			else
			{
				free[i % 2] = (free[!(i % 2)] * 3 + 4) % MOD;
			}
		}

		else
		{
			zero = true;

			base[i % 2] = base[!(i % 2)];
			free[i % 2] = (free[!(i % 2)] * 3) % MOD;
		}
	}

	free[!(n % 2)] = (free[!(n % 2)] + base[!(n % 2)] + ext) % MOD;

	printf("%lld\n", free[!(n % 2)]);

	return 0;
}