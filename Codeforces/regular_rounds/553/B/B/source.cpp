#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n, m;
	vector<vector<int>> arr;
	vector<int> cur;
	int i, j;
	int firstdiff = -1, diffcol;
	int input;
	int val = 0;
	int first;

	scanf("%d %d", &n, &m);
	
	for (i = 0; i < n; i++)
	{
		cur.clear();

		scanf("%d", &input);
		first = input;
		cur.push_back(input);
		val ^= first;

		for (j = 1; j < m; j++)
		{
			scanf("%d", &input);

			cur.push_back(input);

			if (firstdiff == -1 && input != first)
			{
				firstdiff = i;
				diffcol = j;
			}
		}

		arr.push_back(cur);
	}

	if (val)
	{
		printf("TAK\n");

		for (i = 0; i < n; i++)
		{
			printf("1 ");
		}

		return 0;
	}

	if (firstdiff == -1)
	{
		printf("NIE\n");

		return 0;
	}

	printf("TAK\n");

	for (i = 0; i < firstdiff; i++)
	{
		printf("1 ");
	}

	printf("%d ", diffcol + 1);

	for (i = firstdiff + 1; i < n; i++)
	{
		printf("1 ");
	}

	return 0;
}