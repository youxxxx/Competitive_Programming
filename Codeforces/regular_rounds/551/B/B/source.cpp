#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int n, m, h;
	vector<int> front;
	vector<int> left;
	vector<vector<int>> block;
	vector<int> emp;
	int i, j;
	int input;

	//freopen("input.txt", "r", stdin);

	scanf("%d %d %d", &n, &m, &h);

	for (i = 0; i < m; i++)
	{
		scanf("%d", &input);

		front.push_back(input);
	}

	for (i = 0; i < n; i++)
	{
		scanf("%d", &input);

		left.push_back(input);
	}

	for (i = 0; i < n; i++)
	{
		block.push_back(emp);

		for (j = 0; j < m; j++)
		{
			scanf("%d", &input);

			if (!input)
			{
				block[i].push_back(0);
			}

			else
			{
				block[i].push_back(front[j] < left[i] ? front[j] : left[i]);
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%d ", block[i][j]);
		}

		printf("\n");
	}

	return 0;
}