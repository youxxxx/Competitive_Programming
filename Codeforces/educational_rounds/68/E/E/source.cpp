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
	}

	return 0;
}