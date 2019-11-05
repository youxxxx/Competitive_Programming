#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

int main()
{
	int t, z;
	string str;
	char input[100001];
	long long i, n;
	long long temp;
	long long rem;
	long long num, num2;
	long long sum, cur;
	bool sign;

	scanf("%d", &t);
	for (z = 0; z < t; z++)
	{
		scanf("%s",input);

		str = input;

		reverse(str.begin(), str.end());

		n = str.size();

		sum = 0;

		cur = 1;

		for (i = 0; i < n; i++)
		{
			temp = i;

			sum = (sum + (cur * ((str[((i + 1) + (i / n)) % n]) - '0'))) % 1000000007;

			cur = (cur * 10) % 1000000007;
		}

		/*

		for (i = 0; i < n*n; i++)
		{
			temp = i;

			if (temp > 9)
			{
				num = temp / 9 - 1;

				temp %= 9;

				temp += 9;

				sign = bool(num % 2);

				num2 = num / 10;
				num = num / num2;

				rem = (long long)pow(7.0, num);

				rem = (rem * (long long)pow(10.0, temp) % 1000000007) % 1000000007;
			}

			else
			{
				rem = (long long)pow(10.0, i) % 1000000007;
			}

			rem = (rem * ((str[((i + 1) + (i / n)) % n])-'0'));

			sum = (sum + rem) % 1000000007;
		}
		*/

		printf("%lld\n", sum);
	}

	return 0;
}