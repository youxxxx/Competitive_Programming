#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	int i;
	string str;
	char input[1001];
	int cnt[26] = { 0, };

	scanf("%d", &n);
	scanf("%s", input);
	str = input;

	/*
	for (i = 0; i < n; i++)
	{
		cnt[str[i] - 'a']++;
	}
	for (i = 0; i < 26; i++)
	{
		if (cnt[i] > n / 2)
		{
			printf("NO\n");

			return 0;
		}
	}
	*/

	for (i = 0; i < n - 1; i++)
	{
		if (str[i] != str[i + 1])
		{
			printf("YES\n%c%c", str[i], str[i + 1]);

			return 0;
		}
	}

	printf("NO\n");

	return 0;
}