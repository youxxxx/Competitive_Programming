#include<cstdio>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

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
	return a / gcd(a, b)*b;
}

int main()
{
	int t, z;
	int n;
	int i, j;
	long long input;
	vector<long long> prime, div;
	long long cur, temp1, temp2;
	long long numofdivs;
	long long cnt;
	bool isprime, valid;

	scanf("%d", &t);

	prime.push_back(2);

	for (i = 3; i <= 1000; i += 2)
	{
		isprime = true;

		for (j = 0; j < prime.size() && prime[j]*prime[j] <= i; j++)
		{
			if (!(i%prime[j]))
			{
				isprime = false;

				break;
			}
		}

		if(isprime)
		{
			prime.push_back(i);
		}
	}

	for (z = 0; z < t; z++)
	{
		scanf("%d", &n);

		valid = true;

		cur = 1;

		div.clear();
		
		for (i = 0; i < n; i++)
		{
			scanf("%I64d", &input);

			//cur = lcm(cur, input);

			div.push_back(input);
		}

		sort(div.begin(), div.end());

		cur = div.front()*div.back();

		for (i = 1; i < n / 2 - !(n % 2); i++)
		{
			if (div[i] * div[n - i - 1] != cur)
			{
				valid = false;

				break;
			}
		}

		if (n % 2)
		{
			if (div[n / 2] * div[n / 2] != cur)
			{
				valid = false;
			}
		}

		if (!valid)
		{
			printf("-1\n");

			continue;
		}

		//temp1 = div[n / 2 - !(n % 2)];
		//temp2 = div[n - 1 - (n / 2 - !(n % 2))];
		temp1 = div.front();
		temp2 = div.back();

		numofdivs = 1;

		for (i = 0; i < prime.size(); i++)
		{
			cnt = 0;

			while (!(temp1%prime[i]))
			{
				temp1 /= prime[i];

				cnt++;
			}

			while (!(temp2%prime[i]))
			{
				temp2 /= prime[i];

				cnt++;
			}
			
			numofdivs *= (cnt + 1);

			if (temp1 == 1 && temp2 == 1)
			{
				break;
			}
		}

		if (temp1 != 1 && temp2 != 1)
		{
			if (temp1 == temp2)
			{
				numofdivs *= 3;
			}

			else
			{
				numofdivs *= 4;
			}
		}

		else
		{
			if (temp1 != 1)
			{
				numofdivs *= 2;
			}

			else
			{
				numofdivs *= 2;
			}
		}
		
		/*
		if (temp1 != 1)
		{
			numofdivs *= 2;
		}

		if (temp2 != 1)
		{
			numofdivs *= 2;
		}
		*/

		if (numofdivs - 2 == n)
		{
			printf("%I64d\n", cur);
		}

		else
		{
			printf("-1\n");
		}
	}

	return 0;
}