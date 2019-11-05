#include<cstdio>
#include<string>

using namespace std;

int main()
{
	char input[4];
	char temp;
	string str;

	scanf("%s", input);

	str = input;

	if (str.size() == 3)
	{
		temp = str[0];
		str[0] = str[2];
		str[2] = temp;
	}

	printf("%s", str.c_str());

	return 0;
}