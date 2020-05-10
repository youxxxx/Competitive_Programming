#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n, m;
	bool valid[26] = { 0, };

	scanf("%d %d", &n, &m);

	char input[200001];
	string str;

	scanf("%s", input);

	str = input;

	for (int i = 0; i < m; i++)
	{
		char ch;

		scanf("%c", &ch);

		scanf("%c", &ch);

		valid[ch - 'a'] = true;
	}

	long long cnt = 0, sol = 0;

	for (int i = 0; i < n; i++)
	{
		if (!valid[str[i] - 'a'])
		{
			sol += cnt*(cnt - 1) / 2 + cnt;

			cnt = 0;
		}

		else
		{
			cnt++;
		}
	}

	sol += cnt*(cnt - 1) / 2 + cnt;

	printf("%lld\n", sol);

	return 0;
}