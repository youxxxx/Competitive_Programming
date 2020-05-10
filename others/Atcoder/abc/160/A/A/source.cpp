#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<cstring>
#include<functional>

using namespace std;

int main()
{
	char input[10];
	string str;

	scanf("%s", input);
	str = input;

	if (str[2] == str[3] && str[4] == str[5])
	{
		printf("Yes\n");
	}

	else
	{
		printf("No\n");
	}

	return 0;
}