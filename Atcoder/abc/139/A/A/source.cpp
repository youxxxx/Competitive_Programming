#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	string s, t;
	char input[1000];
	int cnt = 0;
	int i;

	scanf("%s", input);
	s = input;
	scanf("%s", input);
	t = input;

	for (i = 0; i < s.size(); i++)
	{
		cnt += (s[i] == t[i]);
	}

	printf("%d\n", cnt);

	return 0;
}