#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n, q;
	string str;
	char input[200001];
	int a = 0;
	int i;

	scanf("%d %d", &n, &q);

	scanf("%s", input);

	str = input;

	for (i = 0; i < n; i++)
	{
		if (str[i] == 'R')
		{
			a++;
		}

		else
		{
			a--;
		}
	}

	if (a > 0)
	{
		printf("Yes\n");
	}

	else
	{
		printf("No\n");
	}

	return 0;
}