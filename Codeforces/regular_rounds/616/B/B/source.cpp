#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int main()
{
	int n, q;
	char input[200001];

	scanf("%s", input);

	string str;

	str = input;

	n = str.size();

	int acc[26][200001] = { 0, };

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			acc[j][i + 1] = acc[j][i];
		}

		acc[str[i] - 'a'][i + 1]++;
	}

	scanf("%d", &q);

	for (int i = 0; i < q; i++)
	{
		int l, r;

		scanf("%d %d", &l, &r);

		if (l == r || str[l - 1] != str[r - 1])
		{
			printf("Yes\n");

			continue;
		}

		int cnt = 0;

		for (int j = 0; j < 26; j++)
		{
			cnt += !!(acc[j][r] - acc[j][l - 1]);
		}

		if (cnt >= 3)
		{
			printf("Yes\n");
		}

		else
		{
			printf("No\n");
		}
	}

	return 0;
}