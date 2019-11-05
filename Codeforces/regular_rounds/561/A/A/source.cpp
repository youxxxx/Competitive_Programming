#include<cstdio>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	char input[100];
	long long cnt[26] = { 0, };
	string str;
	int i;
	long long res = 0;
	long long g1, g2;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%s", input);

		str = input;

		cnt[str[0] - 'a']++;
	}

	for (i = 0; i < 26; i++)
	{
		if (cnt[i] <= 1)
		{
			continue;
		}

		g1 = cnt[i] / 2;
		g2 = cnt[i] - g1;

		res += (g1 - 1)*g1 / 2 + (g2 - 1)*g2 / 2;
	}

	printf("%I64d\n", res);

	return 0;
}