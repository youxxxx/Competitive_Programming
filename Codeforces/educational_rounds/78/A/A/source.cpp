#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		string s, t;
		char input[101];

		scanf("%s", input);
		s = input;
		scanf("%s", input);
		t = input;

		if (s.size() > t.size())
		{
			printf("NO\n");

			continue;
		}

		int base[26] = { 0, };

		for (int i = 0; i < s.size(); i++)
		{
			base[s[i] - 'a']++;
		}

		bool found = false;

		for (int i = 0; i <= t.size() - s.size(); i++)
		{
			int cnt[26] = { 0, };

			for (int j = 0; j < s.size(); j++)
			{
				cnt[t[i + j] - 'a']++;
			}

			bool check = true;

			for (int j = 0; j < 26; j++)
			{
				if (cnt[j] != base[j])
				{
					check = false;

					break;
				}
			}

			if (check)
			{
				found = true;

				break;
			}
		}

		if (found)
		{
			printf("YES\n");
		}

		else
		{
			printf("NO\n");
		}
	}

	return 0;
}