#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;



int main()
{
	int t, z;
	int n;
	int k;
	vector<int> s, pattern;
	int i;
	int lmax;
	int idx;
	int input;
	int x;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		lmax = 0;

		scanf("%d %d", &n, &k);

		for (i = 0; i < n; i++)
		{
			scanf("%d", &input);

			if (input > lmax)
			{
				idx = i;

				lmax = input;
			}
		}

		for (i = 0; i < k; i++)
		{
			scanf("%d", &input);

			s.push_back(input);
		}

		sort(s.begin(), s.end());

		if (n > idx + s.back() - 1)
		{
			n = idx + s.back() - 1;
		}

		x = n - idx;
	}
}