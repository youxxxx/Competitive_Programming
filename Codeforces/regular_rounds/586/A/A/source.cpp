#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int cnt[26] = { 0, };
	int n;
	int i;
	char input[100001];
	string str;

	scanf("%d", &n);

	scanf("%s", input);

	str = input;

	for (i = 0; i < n; i++)
	{
		cnt[str[i] - 'a']++;
	}

	for (i = 0; i < cnt[13]; i++)
	{
		printf("1 ");
	}

	for (i = 0; i < cnt[25]; i++)
	{
		printf("0 ");
	}

	return 0;
}