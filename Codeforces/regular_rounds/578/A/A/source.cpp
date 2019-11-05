#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	char room[20] = "0000000000";
	int i, j;
	char input;

	scanf("%d", &n);
	scanf("%c", &input);

	for (i = 0; i < n; i++)
	{
		scanf("%c", &input);

		if (input == 'L')
		{
			for (j = 0; j < 10; j++)
			{
				if (room[j] == '0')
				{
					room[j] = '1';

					break;
				}
			}
		}

		else if (input == 'R')
		{
			for (j = 9; j >= 0; j--)
			{
				if (room[j] == '0')
				{
					room[j] = '1';

					break;
				}
			}
		}

		else
		{
			room[input - '0'] = '0';
		}
	}

	printf("%s\n", room);

	return 0;
}