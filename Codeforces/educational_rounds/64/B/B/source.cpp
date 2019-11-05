#include<cstdio>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int t, z;
	int n;
	int i, j;
	int cnt[26];
	char input[101];
	string str;
	vector<int> type;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%s", input);

		str = input;

		type.clear();
		for (i = 0; i < 26; i++)
		{
			cnt[i] = 0;
		}

		for (i = 0; i < str.size(); i++)
		{
			cnt[str[i] - 'a']++;
		}

		for (i = 0; i < 26; i++)
		{
			if (cnt[i])
			{
				type.push_back(i);
			}
		}

		if (type.size() == 2)
		{
			if (type[0] + 1 == type[1])
			{
				printf("No answer\n");

				continue;
			}
		}

		if (type.size() == 3)
		{
			if (type[0] + 1 == type[1] && type[1] + 1 == type[2])
			{
				printf("No answer\n");

				continue;
			}

			if (type[0] + 1 == type[1])
			{
				for (j = 0; j < cnt[type[0]]; j++)
				{
					printf("%c", type[0] + 'a');
				}

				for (j = 0; j < cnt[type[2]]; j++)
				{
					printf("%c", type[2] + 'a');
				}

				for (j = 0; j < cnt[type[1]]; j++)
				{
					printf("%c", type[1] + 'a');
				}
			}

			else
			{
				for (j = 0; j < cnt[type[1]]; j++)
				{
					printf("%c", type[1] + 'a');
				}

				for (j = 0; j < cnt[type[0]]; j++)
				{
					printf("%c", type[0] + 'a');
				}

				for (j = 0; j < cnt[type[2]]; j++)
				{
					printf("%c", type[2] + 'a');
				}
			}

			printf("\n");

			continue;
		}

		n = type.size();

		for (i = 1; i < n; i += 2)
		{
			for (j = 0; j < cnt[type[i]]; j++)
			{
				printf("%c", type[i] + 'a');
			}
		}

		for (i = 0; i < n; i += 2)
		{
			for (j = 0; j < cnt[type[i]]; j++)
			{
				printf("%c", type[i] + 'a');
			}
		}

		printf("\n");
	}

	return 0;
}