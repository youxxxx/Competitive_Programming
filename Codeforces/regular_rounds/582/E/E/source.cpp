#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

int main()
{
	int n;
	string s, t, sol;
	char input[3];
	int i;
	int a[2], b[2];

	scanf("%d", &n);

	scanf("%s", input);
	s = input;
	scanf("%s", input);
	t = input;

	a[0] = s[0] - 'a';
	a[1] = s[1] - 'a';
	b[0] = t[0] - 'a';
	b[1] = t[1] - 'a';

	if (s == t)
	{
		printf("YES\n");

		if (s[0] == s[1])
		{
			sol.push_back(s[0]);
			sol.push_back((a[0] + 1) % 3 + 'a');
			sol.push_back((a[0] + 2) % 3 + 'a');
		}

		else
		{
			sol.push_back(s[0]);
			sol.push_back(3 - (a[0] + a[1]) + 'a');
			sol.push_back(s[1]);
		}

		for (i = 0; i < n; i++)
		{
			printf("%s", sol.c_str());
		}

		printf("\n");

		return 0;
	}

	else
	{
		if (s[0] == s[1] && t[0] == t[1])
		{
			printf("YES\n");

			sol.push_back(s[0]);
			sol.push_back(3 - a[0] - b[0] + 'a');
			sol.push_back(t[0]);
			
			for (i = 0; i < n; i++)
			{
				printf("%s", sol.c_str());
			}

			printf("\n");

			return 0;
		}

		if (s[0] == s[1])
		{
			printf("YES\n");

			if (t[0] == s[0])
			{
				sol.push_back(t[0]);
				sol.push_back(3 - b[0] - b[1] + 'a');
				sol.push_back(t[1]);
			}

			else if (t[1] == s[0])
			{
				sol.push_back(t[0]);
				sol.push_back(3 - b[0] - b[1] + 'a');
				sol.push_back(t[1]);
			}

			else
			{
				sol.push_back(t[0]);
				sol.push_back(s[0]);
				sol.push_back(t[1]);
			}

			for (i = 0; i < n; i++)
			{
				printf("%s", sol.c_str());
			}

			printf("\n");

			return 0;
		}

		if (t[0] == t[1])
		{
			printf("YES\n");

			if (s[0] == t[0])
			{
				sol.push_back(s[0]);
				sol.push_back(3 - a[0] - a[1] + 'a');
				sol.push_back(s[1]);
			}

			else if (s[1] == t[0])
			{
				sol.push_back(s[0]);
				sol.push_back(3 - a[0] - a[1] + 'a');
				sol.push_back(s[1]);
			}

			else
			{
				sol.push_back(s[0]);
				sol.push_back(t[0]);
				sol.push_back(s[1]);
			}

			for (i = 0; i < n; i++)
			{
				printf("%s", sol.c_str());
			}

			printf("\n");

			return 0;
		}

		if (s[0] == t[0])
		{
			printf("YES\n");

			for (i = 0; i < n; i++)
			{
				printf("%c", s[1]);
			}

			for (i = 0; i < n; i++)
			{
				printf("%c", t[1]);
			}

			for (i = 0; i < n; i++)
			{
				printf("%c", s[0]);
			}

			printf("\n");

			return 0;
		}

		if (s[1] == t[1])
		{
			printf("YES\n");

			for (i = 0; i < n; i++)
			{
				printf("%c", s[1]);
			}

			for (i = 0; i < n; i++)
			{
				printf("%c", s[0]);
			}

			for (i = 0; i < n; i++)
			{
				printf("%c", t[0]);
			}

			printf("\n");

			return 0;
		}

		if (s[0] == t[1] && t[0] == s[1])
		{
			printf("YES\n");

			for (i = 0; i < n; i++)
			{
				printf("%c", s[0]);
			}

			for (i = 0; i < n; i++)
			{
				printf("%c", 3 - a[0] - a[1] + 'a');
			}

			for (i = 0; i < n; i++)
			{
				printf("%c", t[0]);
			}

			printf("\n");

			return 0;
		}

		if (s[0] == t[1])
		{
			printf("YES\n");

			for (i = 0; i < n; i++)
			{
				printf("%c", s[1]);
			}

			for (i = 0; i < n; i++)
			{
				printf("%c", s[0]);
			}

			for (i = 0; i < n; i++)
			{
				printf("%c", t[0]);
			}

			printf("\n");

			return 0;
		}

		if (t[0] == s[1])
		{
			printf("YES\n");

			for (i = 0; i < n; i++)
			{
				printf("%c", t[1]);
			}

			for (i = 0; i < n; i++)
			{
				printf("%c", t[0]);
			}

			for (i = 0; i < n; i++)
			{
				printf("%c", s[0]);
			}

			printf("\n");

			return 0;
		}
	}

	return 0;
}