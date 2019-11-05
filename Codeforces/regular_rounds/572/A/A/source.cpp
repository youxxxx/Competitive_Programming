#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	char input[1000];
	string str;
	char oth;
	int i;
	int cnt[2] = { 0, };

	scanf("%d", &n);

	scanf("%s", input);

	str = input;

	for (i = 0; i < n; i++)
	{
		cnt[str[i] - '0']++;
	}

	if (cnt[0] != cnt[1])
	{
		printf("1\n%s\n", str.c_str());
	}

	else
	{
		oth = str.back();
		str.pop_back();

		printf("2\n%s %c\n", str.c_str(), oth);
	}

	return 0;
}