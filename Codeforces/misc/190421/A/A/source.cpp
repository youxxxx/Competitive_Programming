#include<cstdio>
#include<vector>
#include<cmath>
#include<string>

using namespace std;

int main()
{
	char input[100];
	string str;
	int sol;
	int i;
	int a = 0;
	int n;

	scanf("%s", input);
	str = input;

	for (i = 0; i < str.size(); i++)
	{
		if (str[i] == 'a')
		{
			a++;
		}
	}

	sol = str.size();

	n = str.size();

	if (n + n % 2 >= a * 2)
	{
		sol = a * 2 - 1;
	}

	printf("%d\n", sol);

	return 0;
}