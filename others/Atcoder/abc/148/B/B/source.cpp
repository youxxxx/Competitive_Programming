#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	string s, t;
	char input[101];
	int n;

	scanf("%d", &n);

	scanf("%s", input);
	s = input;
	scanf("%s", input);
	t = input;

	for (int i = 0; i < n; i++)
	{
		printf("%c%c", s[i], t[i]);
	}

	printf("\n");

	return 0;
}
