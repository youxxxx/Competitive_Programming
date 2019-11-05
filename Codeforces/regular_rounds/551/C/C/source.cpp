#include<cstdio>
#include<vector>
#include<string>

using namespace std;

int main()
{
	int n;
	char input[300001];
	string str;
	int i;
	int l = 0, r = 0;
	int h = 0;

	scanf("%d", &n);

	scanf("%s", input);

	if (n % 2)
	{
		printf(":(\n");

		return 0;
	}

	str = input;

	for (i = 0; i < n; i++)
	{
		if (str[i] == '(')
		{
			l++;
		}

		else if(str[i]==')')
		{
			r++;
		}
	}

	if (l > n / 2 || r > n / 2)
	{
		printf(":(\n");

		return 0;
	}

	l = n / 2 - l;
	r = n / 2 - r;

	for (i = 0; i < n; i++)
	{
		if (str[i] == '(')
		{
			h++;
		}

		else if (str[i] == ')')
		{
			h--;
		}

		else if (l)
		{
			l--;

			str[i] = '(';
			h++;
		}

		else
		{
			str[i] = ')';
			h--;
		}

		if (h <= 0 && i < n - 1)
		{
			printf(":(\n");

			return 0;
		}
	}

	printf("%s", str.c_str());

	return 0;
}