#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

#define MOD 998244353

using namespace std;

long long exp(long long base, long long pw)
{
	vector<long long> bits;
	long long temp;

	temp = pw;

	while (temp)
	{
		bits.push_back(temp % 2);

		temp /= 2;
	}

	temp = base;

	long long rvalue = 1;

	for (int i = 0; i < bits.size(); i++)
	{
		if (bits[i])
		{
			rvalue = rvalue*temp%MOD;
		}

		temp = temp*temp%MOD;
	}

	return rvalue;
}

long long div(long long divs)
{
	return exp(divs, MOD - 2);
}

using namespace std;

int main()
{
	int n;

	scanf("%d", &n);

	long long divd = 1, divs = 1;
	long long odivd = 0, odivs = 1;
	long long prev = 1;

	for (int i = 0; i < n; i++)
	{
		long long input;

		scanf("%lld", &input);
		
		divd = divd*input%MOD;
		divs = divs * 100 % MOD;

		odivd = odivd * 100 % MOD;
		odivs = odivs * 100 % MOD;

		odivd = (odivd + prev * (100 - input) % MOD * (i + 1) % MOD) % MOD;
		prev = prev*input%MOD;
	}

	long long tdivd, tdivs, sol;
	long long dd, ds;

	tdivd = odivd*div(odivs) % MOD;
	tdivs = divd * div(divs) % MOD;

	sol = (n * tdivs % MOD + tdivd) % MOD*div(tdivs) % MOD;

	printf("%lld\n", sol);

 	return 0;
}