#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	char input[101];
	string s, t;

	scanf("%s", input);
	s = input;
	scanf("%s", input);
	t = input;

	printf("%s%s\n", t.c_str(), s.c_str());

	return 0;
}