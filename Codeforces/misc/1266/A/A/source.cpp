#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		char input[101];
		string str;

		scanf("%s", input);
		str = input;

		int zero = 0;
		bool even = false;
		int sum = 0;
		bool allzero = true;

		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '0')
			{
				if (++zero == 2)
				{
					even = true;
				}
			}

			else
			{
				if (!((str[i] - '0') % 2))
				{
					even = true;
				}

				allzero = false;
			}

			sum += str[i] - '0';
		}

		if (allzero||(zero&&even && !(sum % 3)))
		{
			printf("red\n");
		}

		else
		{
			printf("cyan\n");
		}
	}

	return 0;
}