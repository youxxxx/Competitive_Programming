#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	char input[100001];
	string str;
	int i;
	bool win = false;
	bool change = true;

	scanf("%s", input);
	str = input;
	
	for (i = str.size() - 2; i >= 0; i--)
	{
		if (str[i] == str[i + 1])
		{
			change = true;

			str.erase(i, 2);

			win = !win;
		}
	}

	if (win)
	{
		printf("Yes\n");
	}

	else
	{
		printf("No\n");
	}

	return 0;
}