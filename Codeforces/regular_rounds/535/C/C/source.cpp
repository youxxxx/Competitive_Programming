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
	int cost;

	scanf("%d", &n);

	scanf("%s", input);

	str = input;

	for (i = 0; i < 3; i++)
	{
		sel[0] = color[i];
		sel[1] = color[(i + 1) % 3];
		sel[2] = color[(i + 2) % 3];

		cost = 0;

		for (j = 0; j < n; j++)
		{
			if (str[j] != sel[j % 3])
			{
				cost++;
			}
		}

		if (cost < min)
		{
			min = cost;

			for (j = 0; j < 3; j++)
			{
				midx[j] = (i + j) % 3;
			}
		}

		sel[0] = color[i];
		sel[1] = color[(i + 2) % 3];
		sel[2] = color[(i + 1) % 3];

		cost = 0;

		for (j = 0; j < n; j++)
		{
			if (str[j] != sel[j % 3])
			{
				cost++;
			}
		}

		if (cost < min)
		{
			min = cost;

			for (j = 0; j < 3; j++)
			{
				midx[j] = (i + 3 - j) % 3;
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		str[i] = color[midx[i % 3]];
	}

	printf("%d\n%s\n", min,str.c_str());

	return 0;
}