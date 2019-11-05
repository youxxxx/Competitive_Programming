#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	char input[1000];
	string str;
	int n;
	int i;
	int sol;

	scanf("%s", input);

	str = input;

	n = str.size();

	sol = (n + 1) / 2;

	if (n % 2)
	{
		for (i = 1; i < n; i++)
		{
			if (str[i] == '1')
			{
				break;
			}
		}
	}

	if (i == n)
	{
		sol--;
	}

	printf("%d\n", sol);

	return 0;
}