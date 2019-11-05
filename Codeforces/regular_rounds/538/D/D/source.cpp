#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
	int pre;
	int n;
	int i, j, k;
	int **tbl;
	int ptr = 0;
	int input;
	int cnt = 0;
	int dec;
	bool found;
	vector<int> color;

	scanf("%d %d", &n, &pre);

	for (i = 1; i < n; i++)
	{
		scanf("%d", &input);

		if (input != pre)
		{
			color.push_back(pre);

			pre = input;
		}
	}

	color.push_back(pre);

	if (color.size() == 1)
	{
		printf("0\n");

		return 0;
	}

	tbl = new int*[color.size()];

	for (i = 0; i < color.size(); i++)
	{
		tbl[i] = new int[color.size()];

		tbl[i][i] = 1;
	}

	for (k = 2; k <= color.size(); k++)
	{
		for (i = 0; i < color.size() - k + 1; i++)
		{
			j = i + k - 1;

			if (color[i] == color[j])
			{
				tbl[i][j] = tbl[i + 1][j - 1] + 2;
			}

			else
			{
				tbl[i][j] = tbl[i][j - 1] > tbl[i + 1][j] ? tbl[i][j - 1] : tbl[i + 1][j];
			}
		}
	}

	printf("%d\n", color.size() - (tbl[0][color.size() - 1]) / 2 - 1);

	return 0;
}