#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cstring>

using namespace std;

int main()
{
	char input[101];
	string str;
	int n;

	scanf("%s", input);
	str = input;
	n = str.size();

	for (int i = 0; i < n / 2; i++)
	{
		if (str[i] != str[n - i - 1])
		{
			printf("No\n");

			return 0;
		}
	}

	for (int i = 0; i < n / 2; i++)
	{
		if (str[i] != str[n / 2 - i - 1])
		{
			printf("No\n");

			return 0;
		}
	}

	/*
	for (int i = n / 2 + 1; i < n; i++)
	{
		if (str[i] != str[n - i - 1])
		{
			printf("No\n");

			return 0;
		}
	}
	*/

	printf("Yes\n");

	return 0;
}