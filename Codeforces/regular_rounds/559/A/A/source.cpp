#include<cstdio>
#include<vector>
#include<string>

using namespace std;

int main()
{
	int n;
	int lmin = 0, cur = 0;
	char input[1000];
	string str;
	int i;

	scanf("%d", &n);
	scanf("%s", input);

	str = input;

	for (i = 0; i < n; i++)
	{
		if (str[i] == '+')
		{
			cur++;
		}

		else
		{
			cur--;
		}

		if (cur < lmin)
		{
			lmin = cur;
		}
	}

	printf("%d\n", cur - lmin);

	return 0;
}
