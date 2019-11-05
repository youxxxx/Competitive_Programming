#include<cstdio>
#include<string>
#include<cmath>

using namespace std;

int main()
{
	long long lb, ub, next;
	int n;
	int i;
	char input[10];
	string color;
	bool blackup = false;
	bool last = false;
	bool blacknew;
	bool sameheight = false;

	scanf("%d", &n);

	printf("0 0\n");

	fflush(stdout);

	scanf("%s", input);

	color = input;

	if (color == "white")
	{
		blackup = true;

		fflush(stdout);
	}

	lb = 0;
	ub = (long long)pow(10.0, 9);

	for (i = 1; i < n; i++)
	{
		blacknew = false;

		blacknew = (color == "black");

		next = (lb + ub) / 2;

		if (lb == next || ub == next)
		{
			sameheight = true;
		}

		if (blacknew&&blackup||!blacknew&&!blackup)
		{
			ub = next;
		}

		else
		{
			lb = next;
		}

		if (!sameheight)
		{
			printf("%I64d 0\n", next);
		}

		else
		{
			printf("%I64d 1000000000\n", next);
		}

		fflush(stdout);

		scanf("%s", input);

		color = input;
	}

	last = false;

	last = (color == "black");



	if (blacknew&&!blackup || !blacknew && blackup)
	{
		ub = next;
	}

	else
	{
		lb = next;
	}

	next = (lb + ub) / 2;

	if (!sameheight)
	{
		printf("%I64d 0 %I64d 1\n", next, next);
	}

	else
	{
		printf("%I64d 500000000 %I64d 1000000000", next, next + 1);
	}

	fflush(stdout);

	return 0;
}