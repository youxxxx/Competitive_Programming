#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>

using namespace std;

int main()
{
	int tc, cases;
	int n;
	string str;
	char input[1000];
	bool right[26];
	int i;
	int cnt;
	char cur;

	scanf("%d", &cases);

	for (tc = 0; tc < cases; tc++)
	{
		scanf("%s", input);

		str = input;

		n = str.size();

		for (i = 0; i < 26; i++)
		{
			right[i] = false;
		}

		cnt = 1;
		cur = str[0];

		for (i = 1; i < n; i++)
		{
			if (str[i] != cur)
			{
				right[cur - 'a'] = (right[cur - 'a'] || (bool)(cnt % 2));

				cnt = 1;

				cur = str[i];
			}

			else
			{
				cnt++;
			}
		}

		right[cur - 'a'] = (right[cur - 'a'] || (bool)(cnt % 2));

		for (i = 0; i < 26; i++)
		{
			if (right[i])
			{
				printf("%c", i + 'a');
			}
		}

		printf("\n");
	}

	return 0;
}