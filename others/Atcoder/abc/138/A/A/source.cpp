#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int a;
	string s;
	char input[20];

	scanf("%d", &a);
	scanf("%s", input);
	s = input;

	if (a >= 3200)
	{
		printf("%s\n", s.c_str());
	}

	else
	{
		printf("red\n");
	}

	return 0;
}
