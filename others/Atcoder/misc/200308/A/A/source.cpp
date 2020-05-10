#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>
#include<cstring>

using namespace std;

int main()
{
	char input[11];
	string str;

	scanf("%s", input);
	str = input;

	if (str.size() % 2)
	{
		printf("No\n");

		return 0;
	}

	for (int i = 0; i < str.size(); i++)
	{
		if (!(i % 2))
		{
			if (str[i] != 'h')
			{
				printf("No\n");

				return 0;
			}
		}

		else
		{
			if (str[i] != 'i')
			{
				printf("No\n");

				return 0;
			}
		}
	}

	printf("Yes\n");

	return 0;
}