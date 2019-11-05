#include<cstdio>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n, m, l;
	bool sheet[50][10001] = { 0, };
	bool cur[10001];
	int i, j, k;
	vector<int> list[50];
	int input;

	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			cur[i] = false;
		}

		scanf("%d", &l);

		for (j = 0; j < l; j++)
		{
			scanf("%d", &input);

			sheet[i][input] = true;

			list[i].push_back(input);
		}
	}

	for (i = 1; i < n; i++)
	{
		for (j = 0; j < i; j++)
		{
			for (k = 0; k < list[i].size(); k++)
			{
				if (sheet[j][list[i][k]])
				{
					break;
				}
			}

			if (k == list[i].size())
			{
				printf("impossible\n");

				return 0;
			}
		}
	}

	printf("possible\n");	

	return 0;
}