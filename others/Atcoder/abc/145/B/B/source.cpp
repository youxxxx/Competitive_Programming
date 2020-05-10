#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	char input[200];
	string str;

	scanf("%d", &n);

	scanf("%s", input);

	str = input;

	if (n % 2)
	{
		printf("No\n");

		return 0;
	}

	for (int i = 0; i < n / 2; i++)
	{
		if (str[i] != str[i + n / 2])
		{
			printf("No\n");

			return 0;
		}
	}

	printf("Yes\n");

	return 0;
}