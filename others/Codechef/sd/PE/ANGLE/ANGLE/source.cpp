#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int t, z;
	int i, j, k;
	int n, p, q;
	int input;
	vector<int> arr, arr2;
	int res;
	double max;

	scanf("%d", &t);

	for (z = 0; z < t; z++)
	{
		for (i = 0; i < n; i++)
		{
			scanf("%d", &input);

			arr.push_back(input);
		}

		sort(arr.begin(), arr.end());

		for (i = 0; i < n - 2; i++)
		{
			for (j = i + 1; j < n - 1; j++)
			{
				arr2 = arr;

				arr2.erase(arr2.begin(), arr2.begin() + j);
			}
		}
	}
}