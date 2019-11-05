#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

long long p;

long long fexp(long long val, long long pw)
{
	long long temp;
	vector<long long> arr;
	long long rvalue = 0;
	long long add = 1;
	int i;

	temp = pw;

	while (temp)
	{
		arr.push_back(temp % 2);

		temp /= 2;
	}

	for (i = 0; i < arr.size(); i++)
	{
		rvalue = (rvalue + arr[i] * add) % p;

		add = (add*val) % p;
	}

	return rvalue;
}

long long gcd(long long a, long long b)
{
	long long temp;

	while (b != 0)
	{
		a %= b;

		temp = a;
		a = b;
		b = temp;
	}

	return a;
}

long long lcm(long long a, long long b)
{
	return a*b / gcd(a, b);
}

int main()
{
	long long a[3000];
	long long i, j, k;
	long long coef[3000][3000];
	long long totl, totg;

	scanf("%lld", &p);

	for (i = 0; i < p; i++)
	{
		scanf("%lld", &a[i]);
	}

	for (i = 0; i < p; i++)
	{
		coef[i][0] = 1;

		for (j = 1; j < p; j++)
		{
			coef[i][j] = fexp(i + 1, j);
		}
	}

	for (i = 0; i < p; i++)
	{
		totl = 1;

		for (j = i; j < p; j++)
		{
			if (coef[j][i] != 0)
			{
				totl = lcm(totl, coef[j][i]);
			}
		}

		for (j = i; j < p; j++)
		{
			for (k = i; k < p; k++)
			{

			}
		}
	}

	return 0;
}