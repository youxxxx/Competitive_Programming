#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>

using namespace std;

int main()
{
	int tc, cases;
	long long n;
	long long pw;
	long long temp;
	vector<long long> digit;
	long long last;
	long long i, j;
	long long sol, add, cur;
	long long q;
	bool found;

	scanf("%d", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		scanf("%lld", &n);

		temp = n;

		digit.clear();

		found = false;

		while (temp >= 3)
		{
			pw = (long long)(log10((double)temp) / log10((double)3));

			q = temp / (long long)pow(3.0, pw);

			if (q == 2)
			{
				last = pw;

				for (i = (long long)digit.size() - 1; i >= 0; i--)
				{
					if (digit[i] != last + 1)
					{
						digit.push_back(last + 1);

						break;
					}

					last = digit[i];

					digit.erase(digit.begin() + i);
				}

				if (i == -1)
				{
					digit.clear();

					digit.push_back(last + 1);
				}

				sol = 0;

				add = 1;
				cur = 0;

				for (i = (long long)digit.size() - 1; i >= 0; i--)
				{
					for (j = cur; j < digit[i]; j++)
					{
						add *= (long long)3;
					}

					cur = digit[i];

					sol += add;
				}

				printf("%lld\n", sol);

				found = true;

				break;
			}

			digit.push_back(pw);

			temp -= (long long)pow(3.0, pw);
		}

		if (found)
		{
			continue;
		}

		if (temp != 0)
		{
			digit.push_back(0);

			temp--;
		}

		if (temp == 0)
		{
			printf("%lld\n", n);

			continue;
		}

		last = -1;

		for (i = (long long)digit.size() - 1; i >= 0; i--)
		{
			if (digit[i] != last + 1)
			{
				digit.push_back(last + 1);

				break;
			}

			last = digit[i];

			digit.erase(digit.begin() + i);
		}

		if (i == -1)
		{
			digit.clear();

			digit.push_back(last + 1);
		}

		sol = 0;

		add = 1;
		cur = 0;

		for (i = (long long)digit.size() - 1; i >= 0; i--)
		{
			for (j = cur; j < digit[i]; j++)
			{
				add *= (long long)3;
			}

			cur = digit[i];

			sol += add;
		}

		printf("%lld\n", sol);
	}

	return 0;
}