#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	int n;

	scanf("%d", &n);

	string s, t;

	char input[1000001];

	scanf("%s", input);
	s = input;
	scanf("%s", input);
	t = input;

	int cnt[2] = { 0, };

	for (int i = 0; i < n; i++)
	{
		cnt[s[i] - '0']++;
		cnt[t[i] - '0']--;
	}

	if (cnt[0])
	{
		printf("-1\n");

		return 0;
	}

	int sol = 0;

	for (int i = 0; i < n; i++)
	{
		if (s[i] != t[i])
		{
			int num = s[i] - '0';

			if (!cnt[!num])
			{
				sol++;
			}

			else
			{
				cnt[!num]--;
			}

			cnt[num]++;
		}
	}

	printf("%d\n", sol);

	return 0;
}