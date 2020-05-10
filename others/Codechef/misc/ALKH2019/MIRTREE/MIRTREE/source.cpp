#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>

#define MOD 1000000007

using namespace std;

int main()
{
	vector<long long> bits;
	long long temp;
	long long n;
	int q;
	int i;
	long long tot;
	long long u, d, l, r;
	int opcode, operation;

	scanf("%lld %d", &n, &q);

	n++;

	temp = n - 1;

	while (temp)
	{
		bits.push_back(temp % 2);

		temp /= 2;
	}
	//tot = (long long)pow(2.0, n) - 2;
	//d = (long long)pow(2.0, n - 1);

	d = 1;
	temp = 2;

	for (i = 0; i < bits.size(); i++)
	{
		if (bits[i])
		{
			d = (d * temp) % MOD;
		}

		temp = (temp*temp) % MOD;
	}

	tot = (d * 2 + MOD - 2) % MOD;
	u = 1;
	l = r = n;

	for (i = 0; i < q; i++)
	{
		scanf("%d", &opcode);

		if (opcode == 2)
		{
			printf("%lld\n", tot);
		}

		else
		{
			scanf("%d", &operation);

			switch (operation)
			{
			case 1:
				tot = (tot * 2 + r) % MOD;
				r = l;
				u = (u * 2) % MOD;
				d = (d * 2) % MOD;
				break;
			case 2:
				tot = (tot * 2 + l) % MOD;
				l = r;
				u = (u * 2) % MOD;
				d = (d * 2) % MOD;
				break;
			case 3:
				tot = (tot * 2 + u) % MOD;
				u = d;
				l = (l * 2) % MOD;
				r = (r * 2) % MOD;
				break;
			case 4:
				tot = (tot * 2 + d) % MOD;
				d = u;
				l = (l * 2) % MOD;
				r = (r * 2) % MOD;
				break;
			}
		}
	}

	return 0;
}