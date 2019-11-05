#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	string str;
	char input[500001];
	char lmin;

	int i;

	scanf("%s", input);

	str = input;

	n = str.size();

	printf("Mike\n");

	lmin = str[0];

	for (i = 1; i < n; i++)
	{
		if (lmin < str[i])
		{
			printf("Ann\n");
		}

		else
		{
			printf("Mike\n");
		}

		if (lmin > str[i])
		{
			lmin = str[i];
		}
	}

	return 0;
}