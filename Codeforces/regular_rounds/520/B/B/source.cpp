#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	long long n, temp;
	vector<long long> prime;
	vector<long long> divd;
	long long cnt, total = 0, mul = 1;
	long long i, j;
	bool isprime, change, op2;
	long long min, max;

	scanf("%I64d", &n);

	temp = n;

	if (n == 1)
	{
		printf("1 0\n");

		return 0;
	}

	prime.push_back(2);

	if (!(temp%2))
	{
		cnt = 0;

		while (!(temp%2))
		{
			cnt++;

			temp /= 2;
		}

		divd.push_back(cnt);

		mul *= 2;
	}

	for (i = 3; i <= 1000; i++)
	{
		isprime = true;

		for (j = 0; j < prime.size() && prime[j]*prime[j]<=i; j++)
		{
			if (!(i%prime[j]))
			{
				isprime = false;

				break;
			}
		}

		if (isprime)
		{
			prime.push_back(i);

			if (!(temp%i))
			{
				cnt = 0;

				while (!(temp%i))
				{
					cnt++;

					temp /= i;
				}

				divd.push_back(cnt);

				mul *= i;
			}

			if (temp == 1)
			{
				break;
			}
		}
	}

	if (temp != 1)
	{
		divd.push_back(1);

		mul *= temp;
	}

	min = 999999999;

	for (i = 0; i < divd.size(); i++)
	{
		cnt = 0;

		temp = divd[i];

		while (!(temp % 2))
		{
			temp >>= 1;

			cnt++;
		}

		if (cnt < min)
		{
			min = cnt;
		}
	}

	total += min;

	for (i = 0; i < divd.size(); i++)
	{
		divd[i] >>= min;
	}
	
	max = 0;

	op2 = false;

	for (i = 0; i < divd.size() - 1; i++)
	{
		if (divd[i] != divd[i + 1])
		{
			op2 = true;

			break;
		}
	}

	for (i = 0; i < divd.size(); i++)
	{
		change = false;

		cnt = 0;

		temp = divd[i];

		while (temp != 1)
		{
			change = temp % 2;

			temp >>= 1;

			cnt++;
		}

		if (change)
		{
			cnt++;
		}

		if (cnt > max)
		{
			max = cnt;

			if (change)
			{
				op2 = true;
			}
		}
	}

	if (op2)
	{
		total++;
	}

	total += max;

	/*
	while (1)
	{
		cnt = 0;
		change = false;

		for (i = 0; i < divd.size(); i++)
		{
			if (divd[i] != 1)
			{
				break;
			}
		}

		if (i == divd.size())
		{
			break;
		}

		for (i = 0; i < divd.size(); i++)
		{
			if (divd[i] % 2)
			{
				divd[i] = (divd[i] + 1) / 2;
			}

			else
			{
				divd[i] /= 2;
			}
		}

		total += 2;
	}
	*/
	printf("%I64d %I64d\n", mul, total);

	return 0;
} 