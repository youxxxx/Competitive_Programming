#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int z, tc;
	int i, j;
	int n, k;
	int r;
	vector<int> gn;
	bool list[100000];

	//freopen("input.txt", "r", stdin);

	scanf("%d", &tc);

	for (z = 0; z < tc; z++)
	{
		scanf("%d %d", &n, &k);

		if (!(k % 3))
		{
			r = n % (k + 1);

			if (r == k || r % 3)
			{
				printf("Alice\n");
			}

			else
			{
				printf("Bob\n");
			}
		}

		else
		{
			if (!(n % 3))
			{
				printf("Bob\n");
			}

			else
			{
				printf("Alice\n");
			}
		}

		/*
		gn.clear();

		gn.push_back(0);

		for (i = 1; i <= n; i++)
		{
			for (j = 0; j <= n; j++)
			{
				list[j] = false;
			}

			if (i >= 1)
			{
				list[gn[i - 1]] = true;
			}

			if (i >= 2)
			{
				list[gn[i - 2]] = true;
			}

			if (i >= k)
			{
				list[gn[i - k]] = true;
			}

			for (j = 0; j < i; j++)
			{
				if (!list[j])
				{
					break;
				}
			}

			gn.push_back(j);
		}

		for (i = 0; i <= n; i++)
		{
			printf("%d ", gn[i]);
		}
		
		printf("\n");
		*/
	}

	return 0;
}