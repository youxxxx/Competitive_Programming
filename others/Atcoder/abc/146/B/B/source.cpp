#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	char input[100000];
	string str;

	int n;

	scanf("%d", &n);

	scanf("%s", input);

	str = input;

	for (int i = 0; i < str.size(); i++)
	{
		int val;
		val = str[i] - 'A';

		val = (val + n) % 26;

		str[i] = 'A' + val;
	}

	printf("%s\n", str.c_str());

	return 0;
}