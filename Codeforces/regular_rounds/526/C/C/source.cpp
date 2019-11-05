#include<cstdio>
#include<string>

using namespace std;

int main()
{
	char input[100001];
	string str;
	long long pre = 0, cur = 0, sum = 0;
	bool b = false;
	bool first = true;
	int i;
	int n;

	scanf("%s", input);

	str = input;

	n = str.size();

	for (i = 0; i < n; i++)
	{
		if (str[i] == 'a')
		{
			/*
			if (b)
			{
				//cur = pre;
				//pre = cur;
				sum = (sum + 1) % 1000000007;
			}

			else
			{
				sum = (sum + cur + 1) % 1000000007;
			}
			*/

			//sum = (sum + 1) % 1000000007;

			b = false;
			pre++;
		}

		else if(str[i]=='b')
		{
			b = true;

			if (first)
			{
				sum = pre;

				cur = (pre + 1) % 1000000007;

				first = false;
			}

			else
			{
				sum = (sum + cur * pre) % 1000000007;

				cur = (cur*(pre + 1)) % 1000000007;
			}

			pre = 0;
		}
	}

	if (str[n - 1] != 'b')
	{
		if (first)
		{
			sum = pre;
		}

		else
		{
			sum = (sum + cur * pre) % 1000000007;
		}
	}

	printf("%I64d\n", sum);

	return 0;
}