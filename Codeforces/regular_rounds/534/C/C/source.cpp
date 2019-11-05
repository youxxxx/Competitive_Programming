#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	char input[1001];
	string str;
	int i;
	int h = 0, v = 0;

	scanf("%s", input);
	str = input;

	for (i = 0; i < str.size(); i++)
	{
		if (str[i] == '0')
		{
			printf("1 %d\n", h + 1);

			h = (h + 1) % 4;
		}

		else
		{
			printf("3 %d\n", v + 1);

			v = (v + 2) % 4;
		}
	}

	return 0;
}