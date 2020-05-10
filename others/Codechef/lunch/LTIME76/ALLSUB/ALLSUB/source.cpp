#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int tc, cases;
	string s, t, other;
	char input[100001];
	int n, m;
	int i, j;
	bool small, start;
	int scnt[26], tcnt[26];

	scanf("%d", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		s.clear();
		t.clear();
		other.clear();

		scanf("%s", input);
		s = input;
		scanf("%s", input);
		t = input;
		
		n = s.size();
		m = t.size();

		if (n > m)
		{
			printf("Impossible\n");

			continue;
		}

		for (i = 0; i < 26; i++)
		{
			scnt[i] = tcnt[i] = 0;
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
			if (scnt[i] > tcnt[i])
			{
				break;
			}
		}

		if (i != 26)
		{
			printf("Impossible\n");

			continue;
		}

		small = false;

		for (i = 0; i < 26; i++)
		{
			for (j = 0; j < tcnt[i] - scnt[i]; j++)
			{
				other.push_back('a' + i);
			}
		}

		for (i = 0; i < n - 1; i++)
		{
			if (s[i + 1] != s[i])
			{
				if (s[i + 1] < s[i])
				{
					small = true;
				}

				break;
			}
		}

		if (n == m)
		{
			printf("%s\n", s.c_str());

			continue;
		}

		start = false;

		for (i = 0; i < other.size(); i++)
		{
			if (!start)
			{
				if (other[i] > s[0])
				{
					printf("%s", s.c_str());

					start = true;
				}

				else
				{
					if (small)
					{
						if (other[i] == s[0])
						{
							printf("%s", s.c_str());

							start = true;
						}
					}

					else
					{
						if (other[i] == s[0] && i + 1<other.size() && other[i + 1] != s[0])
						{
							printf("%c", other[i]);

							printf("%s", s.c_str());

							start = true;

							continue;
						}
					}
				}
			}

			printf("%c", other[i]);
		}

		if (!start)
		{
			printf("%s", s.c_str());
		}

		printf("\n");
	}

	return 0;
}