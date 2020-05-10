#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		char input[201];
		string s;

		scanf("%s", input);

		s = input;

		int n;

		n = s.size();

		char keyboard[100];
		int ptr = 50;
		int start = 50, end = 50;
		bool used[256] = { 0, };

		memset(keyboard, -1, sizeof(keyboard));

		used[s[0]] = true;
		keyboard[50] = s[0];

		bool valid = true;

		for (int i = 1; i < n; i++)
		{
			if (keyboard[ptr] == s[i])
			{
				continue;
			}

			if (keyboard[ptr - 1] == s[i])
			{
				ptr--;
			}

			else if (keyboard[ptr + 1] == s[i])
			{
				ptr++;
			}

			else
			{
				if (used[s[i]])
				{
					valid = false;

					break;
				}

				if (keyboard[ptr + 1] == -1)
				{
					keyboard[++ptr] = s[i];

					used[s[i]] = true;
				}

				else if (keyboard[ptr - 1] == -1)
				{
					keyboard[--ptr] = s[i];

					used[s[i]] = true;
				}

				else
				{
					valid = false;

					break;
				}
			}

			if (ptr < start)
			{
				start = ptr;
			}

			if (ptr > end)
			{
				end = ptr;
			}
		}

		if (!valid)
		{
			printf("NO\n");
		}

		else
		{
			printf("YES\n");

			for (int i = start; i <= end; i++)
			{
				printf("%c", keyboard[i]);
			}

			for (int i = 'a'; i <= 'z'; i++)
			{
				if (!used[i])
				{
					printf("%c", i);
				}
			}

			printf("\n");
		}
	}

	return 0;
}