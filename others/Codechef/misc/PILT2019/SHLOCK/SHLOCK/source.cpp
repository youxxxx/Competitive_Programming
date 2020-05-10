#include<cstdio>
#include<string>

using namespace std;

int main()
{
	int t, z;
	char input[2000];
	int start[26];
	string str;
	int i, j, n;
	int max;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		scanf("%s", input);

		str = input;
		
		n = str.size();

		max = 0;

		for (i = 0; i < 26; i++)
		{
			start[i] = -1;
		}

		for (i = 0; i < n; i++)
		{
			if (start[str[i] - 'a'] == -1)
			{
				start[str[i] - 'a'] = i;
			}

			if (start[25 - (str[i] - 'a')] != -1)
			{
				if (i - start[25 - (str[i] - 'a')] > max)
				{
					max = i - start[25 - (str[i] - 'a')];
				}
			}
		}

		printf("%d\n", max);
	}

	return 0;
}