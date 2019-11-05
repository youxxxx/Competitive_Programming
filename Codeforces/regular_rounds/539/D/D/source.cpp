#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	char input[5002];
	string str;
	int n;
	int i;
	int size;

	scanf("%s", input);

	str = input;

	n = str.size();

	if (n <= 3)
	{
		printf("Impossible\n");

		return 0;
	}

	if (!(n % 2))
	{
		size = n / 2;

		while (!(size % 2))
		{
			for (i = 0; i < size / 2; i++)
			{
				if (str[i] != str[size - i - 1])
				{
					printf("1\n");

					return 0;
				}
			}

			size /= 2;
		}

		for (i = 0; i < size / 2; i++)
		{
			if (str[i] != str[size - i - 1])
			{
				printf("1\n");

				return 0;
			}
		}
	}

	for (i = 1; i < n / 2; i++)
	{
		if (str[i] != str[0])
		{
			printf("2\n");

			return 0;
		}
	}

	printf("Impossible\n");
	return 0;
}