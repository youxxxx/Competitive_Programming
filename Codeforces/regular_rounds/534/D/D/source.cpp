#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
char input[10];
string str;

long long bin_search(long long lb, long long ub)
{
	long long next;

	if (lb == ub)
	{
		return lb;
	}
	
	if (ub - lb == 1)
	{
		printf("? %I64d %I64d\n", lb, ub);
		fflush(stdout);

		scanf("%s", input);

		str = input;

		if (str == "x")
		{
			return ub;
		}

		else if (str == "y")
		{
			return lb;
		}

		else
		{
			exit(0);
		}
	}

	next = (lb + ub) / 2;

	printf("? %I64d %I64d\n", lb, next);
	fflush(stdout);

	scanf("%s", input);

	str = input;

	if (str == "x")
	{
		if (next - lb == 1)
		{
			return next;
		}

		return bin_search(lb, next);
	}

	else if (str == "y")
	{
		if (next - lb == 1)
		{
			return next + 1;
		}

		return bin_search(next, ub);
	}

	else
	{
		exit(0);
	}
}

int main()
{
	long long i;
	long long pw;

	while (1)
	{
		scanf("%s", input);

		str = input;

		if (str == "end")
		{
			break;
		}

		else if (str == "mistake")
		{
			return 0;
		}

		pw = 1;

		while (pw<1000000000)
		{
			//printf("? %I64d %I64d\n", pw, pw * 2 >= 1000000000 ? 1000000000 : pw * 2);
			printf("? %I64d %I64d\n", pw, pw * 2);
			fflush(stdout);

			scanf("%s", input);

			str = input;

			if (str == "x")
			{
				break;
			}

			else if (str == "e")
			{
				exit(0);
			}

			pw *= 2;
		}

		if (pw == 1)
		{
			printf("? 0 1\n");
			fflush(stdout);

			scanf("%s", input);

			str = input;

			if (str == "x")
			{
				printf("! 1\n");
				fflush(stdout);
			}

			else
			{
				printf("! 2\n");
				fflush(stdout);
			}

			continue;
		}

		/*
		else if (pw * 2 >= 1000000000)
		{
			printf("! %I64d\n", bin_search(pw, 1000000001));
			fflush(stdout);
		}

		else
		{
			printf("! %I64d\n", bin_search(pw, pw * 2 + 1));
			fflush(stdout);
		}
		*/

		printf("! %I64d\n", bin_search(pw, pw * 2 + 1));
		fflush(stdout);
	}

	return 0;
}