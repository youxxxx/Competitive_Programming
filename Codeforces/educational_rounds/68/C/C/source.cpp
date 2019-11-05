#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int z, tc;
	char input[1000];
	string s, t, p;
	int left[26], scnt[26], tcnt[26];
	int n, m;
	int i, j;

	//freopen("input.txt", "r", stdin);

	scanf("%d", &tc);

	for (z = 0; z < tc; z++)
	{
		for (i = 0; i < 26; i++)
		{
			left[i] = scnt[i] = tcnt[i] = 0;
		}

		scanf("%s", input);
		s = input;
		n = s.size();
		scanf("%s", input);
		t = input;
		m = t.size();
		scanf("%s", input);
		p = input;

		if (n > m)
		{
			printf("NO\n");

			continue;
		}

		for (i = 0; i < p.size(); i++)
		{
			left[p[i] - 'a']++;
		}

		j = 0;

		for (i = 0; i < m&&j < n; i++)
		{
			if (s[j] == t[i])
			{
				j++;
			}
		}

		if (j != n)
		{
			printf("NO\n");

			continue;
		}

		for (i = 0; i < n; i++)
		{
			scnt[s[i] - 'a']++;
		}

		for (i = 0; i < m; i++)
		{
			tcnt[t[i] - 'a']++;
		}

		for (i = 0; i < 26; i++)
		{
			if (tcnt[i] - scnt[i] > left[i])
			{
				break;
			}
		}

		if (i != 26)
		{
			printf("NO\n");
		}

		else
		{
			printf("YES\n");
		}
	}

	return 0;
}