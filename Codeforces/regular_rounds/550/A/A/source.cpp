#include<cstdio>
#include<cmath>
#include<vector>
#include<string>

using namespace std;

int main()
{
	int n;
	char input[200];
	bool visited[26];
	int i, j;
	bool start, end;
	string str;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%s", input);

		str = input;

		for (j = 0; j < 26; j++)
		{
			visited[j] = false;
		}

		for (j = 0; j < str.size(); j++)
		{
			if (visited[str[j]-'a'])
			{
				break;
			}

			else
			{
				visited[str[j]-'a'] = true;
			}
		}

		if (j != str.size())
		{
			printf("No\n");
		}

		else
		{
			start = end = false;

			for (j = 0; j < 26; j++)
			{
				if (!start)
				{
					if (visited[j])
					{
						start = true;
					}
				}

				else if(!end)
				{
					if (!visited[j])
					{
						end = true;
					}
				}

				else
				{
					if (visited[j])
					{
						break;
					}
				}
			}

			if (j != 26)
			{
				printf("No\n");
			}
			
			else
			{
				printf("Yes\n");
			}
		}
	}

	return 0;
}