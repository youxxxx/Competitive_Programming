#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	char input[20];
	string str;
	int n;
	int i;
	long long lmax = 1, cand;
	long long saved[20];
	long long pnine = 1;
	bool carry;
	
	scanf("%s", input);

	str = input;

	n = str.size();

	if (n == 1)
	{
		printf("%c\n", str[0]);

		return 0;
	}

	for (i = 0; i < n; i++)
	{
		lmax *= str[i] - '0';

		saved[i] = lmax;
	}

	for (i = n - 1; i >= 2; i--)
	{
		pnine *= 9;

		if (str[i - 1] == '0')
		{
			continue;
		}

		cand = saved[i - 2] * pnine*(str[i - 1] - '0' - 1);

		if (cand > lmax)
		{
			lmax = cand;
		}
	}

	if (str[0] == '1')
	{
		cand = pnine * 9;

		if (cand > lmax)
		{
			lmax = cand;
		}
	}

	else
	{
		cand = pnine*(str[i - 1] - '0' - 1) * 9;

		if (cand > lmax)
		{
			lmax = cand;
		}
	}

	printf("%I64d\n", lmax);

	return 0;
}