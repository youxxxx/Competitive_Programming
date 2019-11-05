#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int i, j;
	char input[3];
	string str;
	vector<string> arr;
	int cnt[3][10] = { 0, };
	char let[3] = { 'm','p','s' };
	int y;
	bool two = false;

	for (i = 0; i < 3; i++)
	{
		scanf("%s", input);

		str = input;

		for (j = 0; j < 3; j++)
		{
			if (str[1] == let[j])
			{
				y = j;

				break;
			}
		}

		if (++cnt[y][str[0] - '0'] == 3)
		{
			printf("0\n");

			return 0;
		}

		else if(cnt[y][str[0] - '0'] == 2)
		{
			two = true;
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 1; j <= 7; j++)
		{
			if (cnt[i][j] && cnt[i][j + 1] && cnt[i][j + 2])
			{
				printf("0\n");

				return 0;
			}

			else if (cnt[i][j] && cnt[i][j + 1] || cnt[i][j + 1] && cnt[i][j + 2] || cnt[i][j] && cnt[i][j + 2])
			{
				two = true;
			}
		}
	}

	if (two)
	{
		printf("1\n");
	}

	else
	{
		printf("2\n");
	}

	return 0;
}