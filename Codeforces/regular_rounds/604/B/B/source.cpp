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
		vector<int> arr;
		int loc[200001];

		scanf("%d", &n);

		for (int i = 0; i < n; i++)
		{
			int input;

			scanf("%d", &input);

			arr.push_back(input);

			loc[input] = i;
		}

		int lmin, lmax;

		lmax = lmin = loc[1];

		string sol;

		sol.push_back('1');

		for (int i = 2; i <= n; i++)
		{
			if (loc[i] < lmin)
			{
				lmin = loc[i];
			}

			if (loc[i] > lmax)
			{
				lmax = loc[i];
			}

			if (lmax - lmin == i - 1)
			{
				sol.push_back('1');
			}

			else
			{
				sol.push_back('0');
			}
		}

		printf("%s\n", sol.c_str());
	}

	return 0;
}