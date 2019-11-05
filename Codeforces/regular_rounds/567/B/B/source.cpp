#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

#define MOD 1000000007

using namespace std;

int main()
{
	int n;
	char input[200000];
	int i, j;
	string str, sol, sol2;
	int carry;
	int val;
	int asize, bsize, ptr, ssize;
	char res;

	scanf("%d %s", &n, input);

	str = input;

	if (!(n % 2))
	{
		if (str[n / 2] != '0')
		{
			carry = 0;

			for (j = 0; j < n / 2; j++)
			{
				val = str[n / 2 - 1 - j] - '0' + str[n - 1 - j] - '0' + carry;

				carry = val / 10;

				res = val % 10 + '0';

				sol.insert(sol.begin(), res);
			}

			if (carry)
			{
				sol.insert(sol.begin(), '1');
			}

			printf("%s\n", sol.c_str());

			return 0;
		}

		for (i = 1; i < n / 2; i++)
		{
			sol.clear();
			sol2.clear();

			if (str[n / 2 - i] != '0'&&str[n / 2 + i] != '0')
			{
				asize = n / 2 - i;
				bsize = n / 2 + i;
				ssize = asize;

				ptr = n / 2 - i - 1;

				carry = 0;

				for (j = 0; j < ssize; j++)
				{
					val = str[ptr - j] - '0' + str[n - 1 - j] - '0' + carry;

					carry = val / 10;

					res = val % 10 + '0';

					sol.insert(sol.begin(), res);
				}

				for (j = ssize; j < bsize; j++)
				{
					val = str[n - 1 - j] - '0' + carry;

					carry = val / 10;

					res = val % 10 + '0';

					sol.insert(sol.begin(), res);
				}

				if (carry)
				{
					sol.insert(sol.begin(), '1');
				}

				asize = n / 2 + i;
				bsize = n / 2 - i;
				ssize = bsize;

				ptr = n / 2 + i - 1;

				carry = 0;

				for (j = 0; j < ssize; j++)
				{
					val = str[ptr - j] - '0' + str[n - 1 - j] - '0' + carry;

					carry = val / 10;

					res = val % 10 + '0';

					sol2.insert(sol2.begin(), res);
				}

				for (j = ssize; j < asize; j++)
				{
					val = str[ptr - j] - '0' + carry;

					carry = val / 10;

					res = val % 10 + '0';

					sol2.insert(sol2.begin(), res);
				}

				if (carry)
				{
					sol2.insert(sol2.begin(), '1');
				}

				if (sol.size() < sol2.size())
				{
					printf("%s\n", sol.c_str());
				}

				else if(sol.size() > sol2.size())
				{
					printf("%s\n", sol2.c_str());
				}

				else
				{
					if (sol < sol2)
					{
						printf("%s\n", sol.c_str());
					}

					else
					{
						printf("%s\n", sol2.c_str());
					}
				}

				return 0;
			}

			else if (str[n / 2 - i] != '0')
			{
				asize = n / 2 - i;
				bsize = n / 2 + i;
				ssize = asize;

				ptr = n / 2 - i - 1;

				carry = 0;

				for (j = 0; j < ssize; j++)
				{
					val = str[ptr - j] - '0' + str[n - 1 - j] - '0' + carry;

					carry = val / 10;

					res = val % 10 + '0';

					sol.insert(sol.begin(), res);
				}

				for (j = ssize; j < bsize; j++)
				{
					val = str[n - 1 - j] - '0' + carry;

					carry = val / 10;

					res = val % 10 + '0';

					sol.insert(sol.begin(), res);
				}

				if (carry)
				{
					sol.insert(sol.begin(), '1');
				}

				printf("%s\n", sol.c_str());
				
				return 0;
			}

			else if (str[n / 2 + i] != '0')
			{
				asize = n / 2 + i;
				bsize = n / 2 - i;
				ssize = bsize;

				ptr = n / 2 + i - 1;

				carry = 0;

				for (j = 0; j < ssize; j++)
				{
					val = str[ptr - j] - '0' + str[n - 1 - j] - '0' + carry;

					carry = val / 10;

					res = val % 10 + '0';

					sol2.insert(sol2.begin(), res);
				}

				for (j = ssize; j < asize; j++)
				{
					val = str[ptr - j] - '0' + carry;

					carry = val / 10;

					res = val % 10 + '0';

					sol2.insert(sol2.begin(), res);
				}

				if (carry)
				{
					sol2.insert(sol2.begin(), '1');
				}

				printf("%s\n", sol2.c_str());

				return 0;
			}
		}
	}

	else
	{
		for (i = 0; i < n / 2; i++)
		{
			sol.clear();
			sol2.clear();

			if (str[n / 2 - i] != '0'&&str[n / 2 + i + 1] != '0')
			{
				asize = n / 2 - i;
				bsize = n / 2 + i + 1;
				ssize = asize;

				ptr = n / 2 - i - 1;

				carry = 0;

				for (j = 0; j < ssize; j++)
				{
					val = str[ptr - j] - '0' + str[n - 1 - j] - '0' + carry;

					carry = val / 10;

					res = val % 10 + '0';

					sol.insert(sol.begin(), res);
				}

				for (j = ssize; j < bsize; j++)
				{
					val = str[n - 1 - j] - '0' + carry;

					carry = val / 10;

					res = val % 10 + '0';

					sol.insert(sol.begin(), res);
				}

				if (carry)
				{
					sol.insert(sol.begin(), '1');
				}

				asize = n / 2 + i + 1;
				bsize = n / 2 - i;
				ssize = bsize;

				ptr = n / 2 + i;

				carry = 0;

				for (j = 0; j < ssize; j++)
				{
					val = str[ptr - j] - '0' + str[n - 1 - j] - '0' + carry;

					carry = val / 10;

					res = val % 10 + '0';

					sol2.insert(sol2.begin(), res);
				}

				for (j = ssize; j < asize; j++)
				{
					val = str[ptr - j] - '0' + carry;

					carry = val / 10;

					res = val % 10 + '0';

					sol2.insert(sol2.begin(), res);
				}

				if (carry)
				{
					sol2.insert(sol2.begin(), '1');
				}

				if (sol.size() < sol2.size())
				{
					printf("%s\n", sol.c_str());
				}

				else if (sol.size() > sol2.size())
				{
					printf("%s\n", sol2.c_str());
				}

				else
				{
					if (sol < sol2)
					{
						printf("%s\n", sol.c_str());
					}

					else
					{
						printf("%s\n", sol2.c_str());
					}
				}

				return 0;
			}

			else if (str[n / 2 - i] != '0')
			{
				asize = n / 2 - i;
				bsize = n / 2 + i + 1;
				ssize = asize;

				ptr = n / 2 - i - 1;

				carry = 0;

				for (j = 0; j < ssize; j++)
				{
					val = str[ptr - j] - '0' + str[n - 1 - j] - '0' + carry;

					carry = val / 10;

					res = val % 10 + '0';

					sol.insert(sol.begin(), res);
				}

				for (j = ssize; j < bsize; j++)
				{
					val = str[n - 1 - j] - '0' + carry;

					carry = val / 10;

					res = val % 10 + '0';

					sol.insert(sol.begin(), res);
				}

				if (carry)
				{
					sol.insert(sol.begin(), '1');
				}

				printf("%s\n", sol.c_str());

				return 0;
			}

			else if (str[n / 2 + i + 1] != '0')
			{
				asize = n / 2 + i + 1;
				bsize = n / 2 - i;
				ssize = bsize;

				ptr = n / 2 + i;

				carry = 0;

				for (j = 0; j < ssize; j++)
				{
					val = str[ptr - j] - '0' + str[n - 1 - j] - '0' + carry;

					carry = val / 10;

					res = val % 10 + '0';

					sol2.insert(sol2.begin(), res);
				}

				for (j = ssize; j < asize; j++)
				{
					val = str[ptr - j] - '0' + carry;

					carry = val / 10;

					res = val % 10 + '0';

					sol2.insert(sol2.begin(), res);
				}

				if (carry)
				{
					sol2.insert(sol2.begin(), '1');
				}

				printf("%s\n", sol2.c_str());

				return 0;
			}
		}
	}

	return 0;
}