#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	char input[101];
	string str;

	scanf("%s", input);
	str = input;

	int cnt = 0;

	for (int i = 0; i < str.size() / 2; i++)
	{
		cnt += (str[i] != str[str.size() - 1 - i]);
	}

	printf("%d\n", cnt);

	return 0;
}