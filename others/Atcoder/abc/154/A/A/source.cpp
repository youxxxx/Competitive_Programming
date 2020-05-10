#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	string s, t, u;
	char input[11];

	scanf("%s", input);
	s = input;
	scanf("%s", input);
	t = input;

	int a, b;

	scanf("%d %d", &a, &b);

	scanf("%s", input);
	u = input;

	if (s == u)
	{
		a--;
	}

	else
	{
		b--;
	}

	printf("%d %d\n", a, b);

	return 0;
}