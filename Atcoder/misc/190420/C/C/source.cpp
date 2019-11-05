#include<cstdio>
#include<cmath>
#include<string>

using namespace std;

int main()
{
	int *w, *b;
	char input[200001];
	string str;
	int n;
	int i;
	int ub, lb;
	int lmin;

	w = new int[200002];
	b = new int[200002];
	scanf("%d", &n);

	scanf("%s", input);

	str = input;

	for (i = n - 1; i >= 0; i--)
	{
		if (str[i] == '.')
		{
			break;
		}
	}

	ub = i;

	for (i = 0; i < n; i++)
	{
		if (str[i] == '#')
		{
			break;
		}
	}

	lb = i;

	w[0] = 0;
	b[ub - lb + 1] = 0;

	for (i = lb; i <= ub; i++)
	{
		if (str[i] == '#')
		{
			w[i - lb + 1] = w[i - lb] + 1;
		}

		else
		{
			w[i - lb + 1] = w[i - lb];
		}
	}

	for (i = ub; i >= lb; i--)
	{
		if (str[i] == '.')
		{
			b[i - lb] = b[i - lb + 1] + 1;
		}

		else
		{
			b[i - lb] = b[i - lb + 1];
		}
	}

	lmin = w[0] + b[0];

	for (i = 1; i <= ub - lb + 1; i++)
	{
		if (w[i] + b[i] < lmin)
		{
			lmin = w[i] + b[i];
		}
	}

	printf("%d\n", lmin);

	return 0;
}