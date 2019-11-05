#include<cstdio>
#include<string>

using namespace std;

int main()
{
	int n;
	char input[200001];
	string str;
	int i, j;
	int min = 300000;
	int midx[3];
	char color[3] = { 'R','G','B' };
	char sel[3];
	int h[26];
	int cost = 0;

	h['R' - 'A'] = 0;
	h['G' - 'A'] = 1;
	h['B' - 'A'] = 2;

	scanf("%d", &n);

	scanf("%s", input);

	str = input;

	for (i = 1; i < n - 1; i++)
	{
		if (str[i] == str[i - 1])
		{
			if (str[i - 1] != str[i + 1])
			{
				str[i] = color[3 - (h[str[i - 1] - 'A'] + h[str[i + 1] - 'A'])];
			}

			else
			{
				str[i] = color[(h[str[i - 1] - 'A'] + 1) % 3];
			}

			cost++;
		}
	}


	if (str[i] == str[i - 1])
	{
		str[i] = color[(h[str[i - 1] - 'A'] + 1) % 3];

		cost++;
	}

	printf("%d\n%s\n", cost, str.c_str());

	return 0;
}