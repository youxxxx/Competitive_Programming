#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;

bool func(long long &a, long long &b)
{
	return a > b;
}

int main()
{
	long long sum;
	long long alp[26];
	long long min, cand;
	int t, z;
	int n, i, j;
	char input[1000001];
	string str;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		sum = 0;

		scanf("%s", input);

		str = input;

		for (i = 0; i < 26; i++)
		{
			alp[i] = 0;
		}

		for (i = 0; i < str.size(); i++)
		{
			sum++;

			alp[str[i] - 'A']++;
		}

		min = sum;

		sort(&alp[0], &alp[26], func);

		for (i = 1; i <= 26; i++)
		{
			if (!(sum%i))
			{
				cand = 0;

				for (j = 0; j < i; j++)
				{
					if (alp[j] - sum / i > 0)
					{
						cand += alp[j] - sum / i;
					}
				}

				for (j = i; j < 26; j++)
				{
					if (alp[j] > 0)
					{
						cand += alp[j];
					}
				}

				if (cand < min)
				{
					min = cand;
				}
			}
		}

		printf("%lld\n", min);
	}

	return 0;
}