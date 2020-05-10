#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;
		bool taken[100001] = { 0, };
		int lmax = -1, ptr = 1;

		scanf("%d", &n);

		taken[0] = true;
		
		bool valid = true;

		vector<int> sol;

		for (int i = 0; i < n; i++)
		{
			int input;

			scanf("%d", &input);

			if (input > lmax)
			{
				lmax = input;

				taken[lmax] = true;

				sol.push_back(lmax);
			}

			else
			{
				while (taken[ptr] && ptr < lmax)
				{
					ptr++;
				}

				if (ptr >= lmax)
				{
					valid = false;
				}

				taken[ptr] = true;

				sol.push_back(ptr);
			}
		}

		if (!valid)
		{
			printf("-1\n");
		}

		else
		{
			for (int i = 0; i < n; i++)
			{
				printf("%d ", sol[i]);
			}

			printf("\n");
		}
	}

	return 0;
}