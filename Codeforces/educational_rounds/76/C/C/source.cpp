#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int cases;

	scanf("%d", &cases);

	for (int tc = 0; tc < cases; tc++)
	{
		int n;
		vector<int> arr;

		arr.clear();

		scanf("%d", &n);

		int loc[200001];

		for (int i = 0; i <= n; i++)
		{
			loc[i] = -1;
		}

		int lmin;

		lmin = -1;

		for (int i = 0; i < n; i++)
		{
			int input;

			scanf("%d", &input);

			if (loc[input] != -1)
			{
				if (lmin == -1 || i - loc[input] + 1 < lmin)
				{
					lmin = i - loc[input] + 1;
				}
			}

			loc[input] = i;
		}

		printf("%d\n", lmin);
	}

	return 0;
}